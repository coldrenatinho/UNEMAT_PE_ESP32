#include <FastLED.h>

#define NUM_LEDS 64
#define DATA_PIN 18 // Use o pino correto do ESP32

CRGB leds[NUM_LEDS];

// Defina os dados da matriz de imagem
const uint64_t IMAGES[] = {
  0x0000000000000000,
  0x3c7efffffffb7e3c,
  0x3c7eff07fffb7e3c,
  0x3c7eff070ffb7e3c,
  0x3c7eff070f1b7e3c,
  0x3c7eff071f7b7e3c,
  0x3c7eff1fff7b7e3c,
  0x3c7effffff7b7e3c
};
const int IMAGES_LEN = sizeof(IMAGES) / 8;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(64); // Ajuste o brilho conforme necessário
}

void loop() {
  // Exiba cada imagem por 1 segundo
  for (int i = 0; i < IMAGES_LEN; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      // Verifique se o bit está definido na imagem
      if (bitRead(IMAGES[i], j)) {
        leds[j] = CRGB::CRGB::Yellow; // Cor dos LEDs ligados
      } else {
        leds[j] = CRGB::Black; // Cor dos LEDs desligados
      }
    }
    FastLED.show();
    delay(1000);
  }
}
