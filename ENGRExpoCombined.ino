#include <FastLED.h>
#define NUM_LEDS 24
#define DATA_PIN 3

CRGB leds[NUM_LEDS];
int ledPin = 3;
const int trigPin = 10;
const int echoPin = 11;
int viBPin = 5; 
int viBintensity = 0;
float duration, distance;

void setup() { 
  Serial.begin(9600);
  FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  FastLED.setBrightness(86);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(viBPin, OUTPUT);
}

void loop() {
  //PING AND VIBRATION
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  viBintensity = map(distance, 0, 400, 255, 0);
  if (distance < 75) {
      analogWrite(viBPin, viBintensity); 
  }
  else {
    analogWrite(viBPin, 0);
  }
  //PHOTORESISTOR
  int value = analogRead(A3);
  Serial.println("Analog Value: ");
  Serial.println(value);
  if (value > 500) {
    // Turn off all LEDs
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
  } else {
    fill_solid(leds, NUM_LEDS, CRGB::White);
    FastLED.show();
    delay(10);
  }
  delay(500);
}
