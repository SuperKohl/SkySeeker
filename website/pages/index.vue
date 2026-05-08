<template>
  <div class="relative min-h-screen bg-black text-white overflow-hidden">

    <!-- Background GIF -->
    <img
      src="/backgrounds/hero.gif"
      class="absolute inset-0 w-full h-full object-cover opacity-30 scale-105 animate-pulse"
    >

    <!-- Dark Overlay -->
    <div class="absolute inset-0 bg-black/70 backdrop-blur-[2px]" />

    <!-- Ambient Glows -->
    <div class="absolute top-[10%] left-[-200px] w-[600px] h-[600px] bg-white/10 blur-3xl rounded-full" />

    <div class="absolute bottom-[-200px] right-[-200px] w-[700px] h-[700px] bg-zinc-500/10 blur-3xl rounded-full" />

    <!-- Navbar -->
    <header class="relative z-20 border-b border-white/10 backdrop-blur-2xl bg-black/20">
      <div class="max-w-7xl mx-auto px-6 py-5 flex items-center justify-between">

        <div class="text-2xl font-semibold tracking-tight">
          SkySeeker
        </div>

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

    <!-- Hero -->
    <section class="relative z-10">

      <div class="max-w-7xl mx-auto px-6 pt-32 pb-28">

        <div class="max-w-4xl">

          <!-- Badge -->
          <div class="inline-flex items-center gap-2 border border-white/10 bg-white/5 backdrop-blur-2xl rounded-full px-5 py-2 text-sm text-zinc-300 mb-10 shadow-2xl shadow-black/50">
            OPEN SOURCE FPV PLATFORM
          </div>

          <!-- Headline -->
          <h1 class="text-6xl md:text-8xl font-black tracking-tight leading-none mb-8">

            <span class="block">
              Build
            </span>

            <span class="block text-zinc-300">
              Speed.
            </span>

          </h1>

          <!-- Description -->
          <p class="text-zinc-400 text-xl md:text-2xl leading-relaxed max-w-2xl mb-14">
            Modular FPV speed platform with configurable hardware,
            printable parts and downloadable build packs.
          </p>

          <!-- Buttons -->
          <div class="flex flex-wrap gap-5">

            <NuxtLink
              to="/configurator"
              class="bg-white text-black px-8 py-4 rounded-2xl font-semibold transition-all duration-300 hover:scale-[1.03] hover:shadow-2xl hover:shadow-white/20 active:scale-[0.98]"
            >
              Open Configurator
            </NuxtLink>

            <button
              class="border border-white/10 bg-white/5 backdrop-blur-2xl px-8 py-4 rounded-2xl font-semibold transition-all duration-300 hover:bg-white/10 hover:border-white/20 hover:scale-[1.03]"
            >
              Explore Platform
            </button>

          </div>

        </div>

      </div>

    </section>

    <!-- Feature Cards -->
    <section class="relative z-10 pb-28">

      <div class="max-w-7xl mx-auto px-6">

        <div class="grid md:grid-cols-3 gap-6">

          <!-- Card -->
          <div class="group border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8 transition-all duration-500 hover:bg-white/10 hover:border-white/20 hover:-translate-y-2 hover:shadow-2xl hover:shadow-black/50">

            <div class="text-sm text-zinc-500 mb-4 tracking-widest">
              CONFIGURATOR
            </div>

            <h2 class="text-3xl font-bold mb-4">
              Modular Build System
            </h2>

            <p class="text-zinc-400 leading-relaxed">
              Configure frames, stacks, motors and video systems
              with compatibility-aware presets.
            </p>

          </div>

          <!-- Card -->
          <div class="group border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8 transition-all duration-500 hover:bg-white/10 hover:border-white/20 hover:-translate-y-2 hover:shadow-2xl hover:shadow-black/50">

            <div class="text-sm text-zinc-500 mb-4 tracking-widest">
              CAD PLATFORM
            </div>

            <h2 class="text-3xl font-bold mb-4">
              Printable Components
            </h2>

            <p class="text-zinc-400 leading-relaxed">
              Download modular STL and STEP files optimized
              for high-speed FPV platforms.
            </p>

          </div>

          <!-- Card -->
          <div class="group border border-white/10 bg-white/5 backdrop-blur-2xl rounded-[32px] p-8 transition-all duration-500 hover:bg-white/10 hover:border-white/20 hover:-translate-y-2 hover:shadow-2xl hover:shadow-black/50">

            <div class="text-sm text-zinc-500 mb-4 tracking-widest">
              OPEN SYSTEM
            </div>

            <h2 class="text-3xl font-bold mb-4">
              Community Driven
            </h2>

            <p class="text-zinc-400 leading-relaxed">
              Open documentation, upgrade paths and configurable
              hardware ecosystem.
            </p>

          </div>

        </div>

      </div>

    </section>

  </div>
</template>