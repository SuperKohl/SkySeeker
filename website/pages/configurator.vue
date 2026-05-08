<template>
  <div class="p-10 text-white bg-black min-h-screen">
    <h1 class="text-3xl font-bold mb-6">SkySeeker Configurator</h1>

    <div class="space-y-4">
      <div>
        <h2 class="font-semibold">Frame</h2>
        <select v-model="config.frame" class="text-black">
          <option v-for="f in data.frames" :key="f.id" :value="f.id">
            {{ f.name }}
          </option>
        </select>
      </div>

      <div>
        <h2 class="font-semibold">Video System</h2>
        <select v-model="config.video" class="text-black">
          <option v-for="v in data.video" :key="v.id" :value="v.id">
            {{ v.name }}
          </option>
        </select>
      </div>

      <div>
        <h2 class="font-semibold">Stack</h2>
        <select v-model="config.stack" class="text-black">
          <option v-for="s in data.stacks" :key="s.id" :value="s.id">
            {{ s.name }}
          </option>
        </select>
      </div>
    </div>

    <pre class="mt-10 bg-gray-900 p-4">
{{ config }}
    </pre>
  </div>
</template>

<script setup>
import data from '~/data/parts.json'

const config = reactive({
  frame: '',
  video: '',
  stack: ''
})
</script>