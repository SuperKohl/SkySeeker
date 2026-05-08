<template>
  <div class="relative min-h-screen bg-black text-white overflow-hidden">

    <!-- Background GIF -->
    <img
      src="/backgrounds/hero.gif"
      class="absolute inset-0 w-full h-full object-cover opacity-20 scale-105"
    >

    <!-- Overlay -->
    <div class="absolute inset-0 bg-black/75 backdrop-blur-[3px]" />

    <!-- Ambient Glow -->
    <div class="absolute top-[10%] left-[-200px] w-[600px] h-[600px] bg-white/10 blur-3xl rounded-full" />

    <div class="absolute bottom-[-250px] right-[-250px] w-[700px] h-[700px] bg-zinc-500/10 blur-3xl rounded-full" />

    <!-- Navbar -->
    <header class="relative z-20 border-b border-white/10 backdrop-blur-2xl bg-black/20">
      <div class="max-w-7xl mx-auto px-6 py-5 flex items-center justify-between">

        <!-- Logo -->
        <NuxtLink
          to="/"
          class="text-2xl font-semibold tracking-tight"
        >
          SkySeeker
        </NuxtLink>

        <!-- Navigation -->
        <nav class="hidden md:flex items-center gap-8 text-sm text-zinc-400">

          <NuxtLink
            to="/configurator"
            class="hover:text-white transition-all duration-300"
          >
            Configurator
          </NuxtLink>

          <a
            href="#"
            class="hover:text-white transition-all duration-300"
          >
            Wiki
          </a>

          <a
            href="#"
            class="hover:text-white transition-all duration-300"
          >
            Downloads
          </a>

        </nav>

      </div>
    </header>

    <!-- Main -->
    <main class="relative z-10 max-w-7xl mx-auto px-6 py-20">

      <div class="grid lg:grid-cols-[1.1fr_0.9fr] gap-8">

        <!-- Left Side -->
        <div class="space-y-8">

          <!-- Heading -->
          <div>

            <div class="inline-flex items-center gap-2 border border-white/10 bg-white/5 backdrop-blur-2xl rounded-full px-5 py-2 text-sm text-zinc-300 mb-8">
              LIVE CONFIGURATOR
            </div>

            <h1 class="text-5xl md:text-7xl font-black tracking-tight leading-none mb-6">
              Configure
              <br>
              Your Build.
            </h1>

            <p class="text-zinc-400 text-xl leading-relaxed max-w-2xl">
              Select compatible hardware configurations and generate
              modular FPV build packages.
            </p>

          </div>

          <!-- Config Card -->
          <div class="border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8 space-y-8 shadow-2xl shadow-black/50">

            <!-- Video -->
            <div>

              <label class="block text-zinc-400 mb-3">
                Video System
              </label>

              <select
                v-model="config.video"
                class="w-full bg-zinc-950/80 border border-white/10 rounded-2xl p-4 outline-none transition-all duration-300 focus:border-white/30"
              >
                <option>Analog</option>
                <option>Walksnail</option>
                <option>DJI O4</option>
              </select>

            </div>

            <!-- Stack -->
            <div>

              <label class="block text-zinc-400 mb-3">
                Stack Size
              </label>

              <select
                v-model="config.stack"
                class="w-full bg-zinc-950/80 border border-white/10 rounded-2xl p-4 outline-none transition-all duration-300 focus:border-white/30"
              >
                <option>20x20</option>
                <option>30x30</option>
              </select>

            </div>

            <!-- Motor -->
            <div>

              <label class="block text-zinc-400 mb-3">
                Motor Size
              </label>

              <select
                v-model="config.motor"
                class="w-full bg-zinc-950/80 border border-white/10 rounded-2xl p-4 outline-none transition-all duration-300 focus:border-white/30"
              >
                <option>2207</option>
                <option>2807</option>
                <option>3115</option>
              </select>

            </div>

            <!-- Buttons -->
            <div class="flex flex-wrap gap-4 pt-4">

              <button
                class="bg-white text-black px-8 py-4 rounded-2xl font-semibold transition-all duration-300 hover:scale-[1.03] hover:shadow-2xl hover:shadow-white/20 active:scale-[0.98]"
              >
                Generate Build
              </button>

              <button
                class="border border-white/10 bg-white/5 backdrop-blur-2xl px-8 py-4 rounded-2xl font-semibold transition-all duration-300 hover:bg-white/10 hover:border-white/20 hover:scale-[1.03]"
              >
                Export ZIP
              </button>

            </div>

          </div>

        </div>

        <!-- Right Side -->
        <div class="space-y-6">

          <!-- 3D Viewer Placeholder -->
          <div class="border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] h-[430px] flex items-center justify-center text-zinc-500 text-lg shadow-2xl shadow-black/50">
            3D Viewer Coming Soon
          </div>

          <!-- Current Build -->
          <div class="border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8 shadow-2xl shadow-black/50">

            <div class="flex items-center justify-between mb-8">

              <h2 class="text-2xl font-bold">
                Current Build
              </h2>

              <div class="text-xs tracking-widest text-zinc-500">
                LIVE CONFIG
              </div>

            </div>

            <div class="space-y-5">

              <div class="flex justify-between items-center">
                <span class="text-zinc-500">
                  Video
                </span>

                <span class="font-medium">
                  {{ config.video }}
                </span>
              </div>

              <div class="flex justify-between items-center">
                <span class="text-zinc-500">
                  Stack
                </span>

                <span class="font-medium">
                  {{ config.stack }}
                </span>
              </div>

              <div class="flex justify-between items-center">
                <span class="text-zinc-500">
                  Motor
                </span>

                <span class="font-medium">
                  {{ config.motor }}
                </span>
              </div>

            </div>

          </div>

        </div>

      </div>

    </main>

  </div>
</template>

<script setup>
const config = reactive({
  video: 'Analog',
  stack: '20x20',
  motor: '2207'
})
</script>