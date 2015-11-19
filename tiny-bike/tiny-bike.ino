#define USE_HSV 1
#include <WS2812.h>

WS2812 NeoA(16); 
//WS2812 NeoB(8); // 8 LED
	
cRGB color;

int ledR = 3;
int ledG = 4;

void setup() {
  randomSeed(analogRead(0));

  NeoA.setOutput(2); 
  //NeoB.setOutput(5); 
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);

  digitalWrite(ledG, HIGH);

  // 0-7 front lights
  color.r = 155; color.g = 155; color.b = 155;
  for(int i=0; i < 8; i++) {
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
  }

  // 8-15 back lights
  color.r = 155; color.g = 0; color.b = 0;
  for(int i=8; i < 16; i++) {
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
  }

  NeoA.sync(); // Sends the color to the LED
}

void loop() {
  
  // cycle front strip
  digitalWrite(ledR, HIGH);  
  for(int i=0; i < 8; i++) {
    color.r = 0; color.g = 150; color.b = 0; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
    color.r = 155; color.g = 155; color.b = 155;
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
  }

  for(int i=7; i >= 0; i--) {
    color.r = 0; color.g = 0; color.b = 155;
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
    color.r = 255; color.g = 255; color.b = 255;
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
  }

  delay(300); 


  // cycle back strip
  digitalWrite(ledR, LOW); 
  for(int i=8; i < 16; i++) {
    color.SetHSV(random(255),255,155);
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(150); 
    color.r = 155; color.g = 0; color.b = 0;
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
  }

  for(int i=15; i > 7; i--) {
    color.SetHSV(random(255),255,155);
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(150); 
    color.r = 155; color.g = 0; color.b = 0;
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
  }

  delay(300); // Wait 500 ms

}

