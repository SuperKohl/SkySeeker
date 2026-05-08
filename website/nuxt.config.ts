export default defineNuxtConfig({
  compatibilityDate: '2025-05-15',

  modules: ['@nuxtjs/tailwindcss'],

  app: {
    baseURL: '/SkySeeker/'
  },

  nitro: {
    preset: 'static'
  }
})