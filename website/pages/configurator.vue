<template>
  <div class="relative min-h-screen bg-black text-white overflow-hidden">

    <!-- Background GIF -->
    <img
      src="/backgrounds/hero.gif"
      class="absolute inset-0 w-full h-full object-cover opacity-20 scale-105"
    />

    <!-- Overlay -->
    <div class="absolute inset-0 bg-black/75 backdrop-blur-[3px]" />

    <!-- Glow -->
    <div class="absolute top-[10%] left-[-200px] w-[600px] h-[600px] bg-white/10 blur-3xl rounded-full" />
    <div class="absolute bottom-[-250px] right-[-250px] w-[700px] h-[700px] bg-zinc-500/10 blur-3xl rounded-full" />

    <!-- NAVBAR -->
    <header class="relative z-20 border-b border-white/10 backdrop-blur-2xl bg-black/20">

      <div class="max-w-7xl mx-auto px-6 py-5 flex items-center justify-between">

        <!-- Logo -->
        <NuxtLink to="/" class="text-2xl font-semibold tracking-tight">
          SkySeeker
        </NuxtLink>

        <!-- Desktop Nav -->
        <nav class="hidden md:flex items-center gap-8 text-sm text-zinc-400">

          <NuxtLink to="/" class="hover:text-white transition">
            Home
          </NuxtLink>

          <NuxtLink to="/configurator" class="hover:text-white transition">
            Configurator
          </NuxtLink>

          <a href="#" class="hover:text-white transition">
            Wiki
          </a>

          <a href="#" class="hover:text-white transition">
            Downloads
          </a>

        </nav>

        <!-- Mobile Button -->
        <button
          @click="mobileOpen = !mobileOpen"
          class="md:hidden border border-white/10 bg-white/5 px-3 py-2 rounded-xl"
        >
          ☰
        </button>

      </div>

      <!-- Mobile Menu -->
      <div v-if="mobileOpen" class="md:hidden border-t border-white/10 bg-black/90 backdrop-blur-2xl">

        <div class="flex flex-col px-6 py-4 gap-4 text-zinc-300">

          <NuxtLink to="/" class="hover:text-white">
            Home
          </NuxtLink>

          <NuxtLink to="/configurator" class="hover:text-white">
            Configurator
          </NuxtLink>

          <a href="#" class="hover:text-white">
            Wiki
          </a>

          <a href="#" class="hover:text-white">
            Downloads
          </a>

        </div>

      </div>

    </header>

    <!-- MAIN -->
    <main class="relative z-10 max-w-7xl mx-auto px-6 py-20">

      <div class="grid lg:grid-cols-[1.1fr_0.9fr] gap-8">

        <!-- LEFT -->
        <div class="space-y-8">

          <div>
            <h1 class="text-5xl md:text-7xl font-black leading-none mb-6">
              Configure<br>Builds.
            </h1>

            <p class="text-zinc-400 text-xl max-w-2xl">
              Modular FPV configuration system with compatibility-aware hardware selection.
            </p>
          </div>

          <div class="border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8 space-y-8">

            <div>
              <label class="text-zinc-400 block mb-3">Video System</label>
              <select v-model="config.video" class="w-full bg-black/60 border border-white/10 p-4 rounded-2xl">
                <option>Analog</option>
                <option>Walksnail</option>
                <option>DJI O4</option>
              </select>
            </div>

            <div>
              <label class="text-zinc-400 block mb-3">Stack</label>
              <select v-model="config.stack" class="w-full bg-black/60 border border-white/10 p-4 rounded-2xl">
                <option>20x20</option>
                <option>30x30</option>
              </select>
            </div>

            <div>
              <label class="text-zinc-400 block mb-3">Motor</label>
              <select v-model="config.motor" class="w-full bg-black/60 border border-white/10 p-4 rounded-2xl">
                <option>2207</option>
                <option>2807</option>
                <option>3115</option>
              </select>
            </div>

          </div>

        </div>

        <!-- RIGHT -->
        <div class="space-y-6">

          <div class="border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] h-[420px] flex items-center justify-center text-zinc-500">
            3D Viewer
          </div>

          <div class="border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8">

            <h2 class="text-2xl font-bold mb-6">Current Build</h2>

            <div class="space-y-4 text-sm">

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

      </div>

    </main>

  </div>
</template>

<script setup>
const mobileOpen = ref(false)

const config = reactive({
  video: 'Analog',
  stack: '20x20',
  motor: '2207'
})
</script>