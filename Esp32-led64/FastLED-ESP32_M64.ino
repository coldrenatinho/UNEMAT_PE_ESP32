#include <FastLED.h>
#define DATA_PIN 18
#define NUM_LEDS 64
CRGB leds[NUM_LEDS];
int i =0;
void setup(){
 FastLED.addLeds<NEOPIXEL, DATA_PIN >(leds, NUM_LEDS); 
}

void loop(){
  leds[i] = CRGB::GreenYellow;
  leds[63-i] = CRGB(39, 4, 239);
  FastLED.show();
  delay(100);
  leds[i] = CRGB::Black;
  leds[63-i] = CRGB::Black;
  FastLED.show();
  delay(100);
  i = i + 1;
  if(i> 63) i = 0;
}

