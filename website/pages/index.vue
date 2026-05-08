<template>
  <div class="relative min-h-screen bg-black text-white overflow-hidden">

    <!-- Background GIF -->
    <img
      src="/backgrounds/hero.gif"
      class="absolute inset-0 w-full h-full object-cover opacity-25 scale-105"
    />

    <!-- Overlay -->
    <div class="absolute inset-0 bg-black/70 backdrop-blur-[2px]" />

    <!-- Glow -->
    <div class="absolute top-[15%] left-[-200px] w-[600px] h-[600px] bg-white/10 blur-3xl rounded-full" />
    <div class="absolute bottom-[-200px] right-[-200px] w-[700px] h-[700px] bg-zinc-500/10 blur-3xl rounded-full" />

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

    <!-- HERO -->
    <section class="relative z-10">

      <div class="max-w-7xl mx-auto px-6 pt-32 pb-28">

        <div class="max-w-4xl">

          <div class="inline-flex items-center gap-2 border border-white/10 bg-white/5 backdrop-blur-2xl rounded-full px-5 py-2 text-sm text-zinc-300 mb-10">
            OPEN SOURCE FPV PLATFORM
          </div>

          <h1 class="text-6xl md:text-8xl font-black leading-none mb-8">
            Build<br>
            <span class="text-zinc-300">Speed.</span>
          </h1>

          <p class="text-zinc-400 text-xl md:text-2xl leading-relaxed max-w-2xl mb-14">
            Modular FPV speed platform with configurable hardware,
            printable parts and downloadable build packs.
          </p>

          <div class="flex flex-wrap gap-5">

            <NuxtLink
              to="/configurator"
              class="bg-white text-black px-8 py-4 rounded-2xl font-semibold transition-all duration-300 hover:scale-[1.03] hover:shadow-2xl hover:shadow-white/20 active:scale-[0.98]"
            >
              Open Configurator
            </NuxtLink>

            <button
              class="border border-white/10 bg-white/5 px-8 py-4 rounded-2xl font-semibold transition-all duration-300 hover:bg-white/10 hover:scale-[1.03]"
            >
              Explore Platform
            </button>

          </div>

        </div>

      </div>

    </section>

  </div>
</template>

<script setup>
const mobileOpen = ref(false)
</script>