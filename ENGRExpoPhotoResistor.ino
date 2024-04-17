#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 8

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];
int ledPin = 3;

void setup() { 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  FastLED.setBrightness(84);
}

void loop() { 
  int value = analogRead(A0);
  Serial.println("Analog Value: ");
  Serial.println(value);

  if (value < 500) {
    // Turn off all LEDs
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
  } else {
    fill_solid(leds, NUM_LEDS, CRGB::White);
    FastLED.show();
    delay(10);
  }
  
  delay(1000);
}