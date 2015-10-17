#include <WS2812.h>

WS2812 NeoA(16); 
//WS2812 NeoB(8); // 8 LED
	
cRGB color;

int ledR = 3;
int ledG = 4;

void setup() {
  // put your setup code here, to run once:
  NeoA.setOutput(2); 
  //NeoB.setOutput(5); 
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);

  digitalWrite(ledG, HIGH);

  color.r = 255; color.g = 255; color.b = 255;
  for(int i=0; i < 8; i++) {
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
  }

  color.r = 255; color.g = 0; color.b = 0; // RGB color -> Red
  for(int i=8; i < 16; i++) {
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
  }

  NeoA.sync(); // Sends the color to the LED
}

void loop() {
  
  digitalWrite(ledR, HIGH);
    
  for(int i=8; i < 16; i++) {
    color.r = 0; color.g = 0; color.b = 0; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
    color.r = 255; color.g = 0; color.b = 0; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
  }

  for(int i=15; i > 7; i--) {
    color.r = 0; color.g = 0; color.b = 0; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
    color.r = 255; color.g = 0; color.b = 0; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
  }

  delay(300); // Wait 500 ms

  digitalWrite(ledR, LOW); 
  
  for(int i=0; i < 8; i++) {
    color.r = 0; color.g = 255; color.b = 0; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(50); 
    color.r = 255; color.g = 255; color.b = 255; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(50); 
  }

  for(int i=7; i >= 0; i--) {
    color.r = 0; color.g = 0; color.b = 255; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
    color.r = 255; color.g = 255; color.b = 255; // RGB color -> Half Red
    NeoA.set_crgb_at(i, color); // Set color at LED found at index 0
    NeoA.sync(); // Sends the color to the LED
    delay(90); 
  }

  delay(300); // Wait 500 ms

}

