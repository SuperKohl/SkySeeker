<template>
  <div class="min-h-screen bg-black text-white p-10">

    <h1 class="text-5xl font-black mb-10">
      SkySeeker Configurator
    </h1>

    <div class="space-y-6 max-w-xl">

      <div>
        <label class="block mb-2 text-zinc-400">
          Video System
        </label>

        <select
          v-model="video"
          class="w-full bg-zinc-900 border border-zinc-700 rounded-xl p-3"
        >
          <option>Analog</option>
          <option>Walksnail</option>
          <option>DJI O4</option>
        </select>
      </div>

      <div>
        <label class="block mb-2 text-zinc-400">
          Stack Size
        </label>

        <select
          v-model="stack"
          class="w-full bg-zinc-900 border border-zinc-700 rounded-xl p-3"
        >
          <option>20x20</option>
          <option>30x30</option>
        </select>
      </div>

    </div>

    <div class="mt-10 bg-zinc-900 rounded-2xl p-6">
      <pre>
Video: {{ video }}
Stack: {{ stack }}
      </pre>
    </div>

  </div>
</template>

<script setup>
const video = ref('Analog')
const stack = ref('20x20')
</script>