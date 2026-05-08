<template>
  <div class="relative min-h-screen bg-black text-white overflow-hidden">

    <!-- Background -->
    <img
      src="/backgrounds/hero.gif"
      class="absolute inset-0 w-full h-full object-cover opacity-20 scale-105"
    />

    <div class="absolute inset-0 bg-black/75 backdrop-blur-[3px]" />

    <!-- Glow -->
    <div class="absolute top-[10%] left-[-200px] w-[600px] h-[600px] bg-white/10 blur-3xl rounded-full" />
    <div class="absolute bottom-[-250px] right-[-250px] w-[700px] h-[700px] bg-zinc-500/10 blur-3xl rounded-full" />

    <!-- NAVBAR -->
    <header class="relative z-20 border-b border-white/10 backdrop-blur-2xl bg-black/20">

      <div class="max-w-7xl mx-auto px-6 py-5 flex items-center justify-between">

        <NuxtLink to="/" class="text-2xl font-semibold tracking-tight">
          SkySeeker
        </NuxtLink>

        <nav class="hidden md:flex items-center gap-8 text-sm text-zinc-400">
          <NuxtLink to="/" class="hover:text-white transition">Home</NuxtLink>
          <NuxtLink to="/configurator" class="hover:text-white transition">Configurator</NuxtLink>
          <a href="#" class="hover:text-white transition">Wiki</a>
          <a href="#" class="hover:text-white transition">Downloads</a>
        </nav>

        <button
          @click="mobileOpen = !mobileOpen"
          class="md:hidden border border-white/10 bg-white/5 px-3 py-2 rounded-xl"
        >
          ☰
        </button>

      </div>

      <div v-if="mobileOpen" class="md:hidden border-t border-white/10 bg-black/90 backdrop-blur-2xl">
        <div class="flex flex-col px-6 py-4 gap-4 text-zinc-300">
          <NuxtLink to="/">Home</NuxtLink>
          <NuxtLink to="/configurator">Configurator</NuxtLink>
          <a href="#">Wiki</a>
          <a href="#">Downloads</a>
        </div>
      </div>

    </header>

    <!-- MAIN -->
    <main class="relative z-10 max-w-7xl mx-auto px-6 py-16">

      <div class="grid lg:grid-cols-2 gap-10">

        <!-- LEFT -->
        <div class="space-y-8">

          <h1 class="text-5xl md:text-7xl font-black leading-none">
            Configure<br>FPV Build
          </h1>

          <!-- CONFIG -->
          <div class="border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8 space-y-8">

            <div>
              <label class="text-zinc-400 block mb-3">Video System</label>
              <select v-model="config.video" class="w-full bg-black/60 border border-white/10 p-4 rounded-2xl">
                <option v-for="v in parts?.video || []" :key="v.id" :value="v.id">
                  {{ v.label }}
                </option>
              </select>
            </div>

            <div>
              <label class="text-zinc-400 block mb-3">Stack</label>
              <select v-model="config.stack" class="w-full bg-black/60 border border-white/10 p-4 rounded-2xl">
                <option v-for="s in parts?.stack || []" :key="s.id" :value="s.id">
                  {{ s.label }}
                </option>
              </select>
            </div>

            <div>
              <label class="text-zinc-400 block mb-3">Motor</label>
              <select v-model="config.motor" class="w-full bg-black/60 border border-white/10 p-4 rounded-2xl">
                <option v-for="m in parts?.motor || []" :key="m.id" :value="m.id">
                  {{ m.label }}
                </option>
              </select>
            </div>

          </div>

          <!-- COMPATIBILITY WARNINGS -->
          <div v-if="warnings.length" class="border border-red-500/30 bg-red-500/10 rounded-2xl p-4">
            <p class="text-red-300 font-semibold mb-2">Warnings</p>
            <ul class="text-sm text-red-200 space-y-1">
              <li v-for="w in warnings" :key="w">• {{ w }}</li>
            </ul>
          </div>

          <!-- ONLY BUTTON -->
          <button
            @click="downloadZip"
            class="bg-white text-black px-8 py-4 rounded-2xl font-semibold hover:scale-[1.03] transition"
          >
            Download
          </button>

        </div>

        <!-- RIGHT -->
        <div class="border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8">

          <h2 class="text-2xl font-bold mb-8">Current Build</h2>

          <div class="space-y-5 text-sm">

            <div class="flex justify-between">
              <span class="text-zinc-500">Video</span>
              <span>{{ config.video }}</span>
            </div>

            <div class="flex justify-between">
              <span class="text-zinc-500">Stack</span>
              <span>{{ config.stack }}</span>
            </div>

            <div class="flex justify-between">
              <span class="text-zinc-500">Motor</span>
              <span>{{ config.motor }}</span>
            </div>

          </div>

        </div>

      </div>

    </main>

  </div>
</template>

<script setup>
import JSZip from 'jszip'
import { saveAs } from 'file-saver'

const mobileOpen = ref(false)
const parts = ref(null)
const warnings = ref([])

const config = reactive({
  video: '',
  stack: '',
  motor: ''
})

onMounted(async () => {
  const res = await fetch('/data/parts.json')
  parts.value = await res.json()

  config.video = parts.value.video[0].id
  config.stack = parts.value.stack[0].id
  config.motor = parts.value.motor[0].id
})

watch(config, () => {

  warnings.value = []

  if (config.stack === '20x20' && config.motor === '3115') {
    warnings.value.push('3115 motors are too large for 20x20 stack')
  }

  if (config.video === 'dji_o4' && config.stack === '20x20') {
    warnings.value.push('DJI O4 requires at least 30x30 stack')
  }

}, { deep: true })

async function downloadZip() {

  const zip = new JSZip()

  const video = parts.value.video.find(v => v.id === config.video)
  const stack = parts.value.stack.find(s => s.id === config.stack)
  const motor = parts.value.motor.find(m => m.id === config.motor)

  zip.file("config.json", JSON.stringify(config, null, 2))

  const models = zip.folder("models")

  video.zipFiles.forEach(f => models.file(f.split('/').pop(), "STL"))
  stack.zipFiles.forEach(f => models.file(f.split('/').pop(), "STL"))
  motor.zipFiles.forEach(f => models.file(f.split('/').pop(), "STL"))

  const blob = await zip.generateAsync({ type: "blob" })

  saveAs(blob, `SkySeeker_${Date.now()}.zip`)
}
</script>