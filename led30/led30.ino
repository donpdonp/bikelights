//https://github.com/cpldcpu/light_ws2812
#include <WS2812.h>
#include <cRGB.h>

#define LEDCount 30
WS2812 NeoA(LEDCount); 
cRGB value;
byte intensity;
byte sign;

int ledRed = 3;
int ledGreen = 4;

void setup() {
  NeoA.setOutput(2); 

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  digitalWrite(ledGreen, HIGH);
  NeoA.setColorOrderRGB(); 
  intensity = 0;
  sign = 1;
}

void loop() {
	int i = 0;
	if (sign) {
		intensity++;
		if (intensity == 255) 
			sign = 0; 
	}
	else {
		intensity--;
		if (intensity == 0)
			sign = 1;
	}

	while (i < LEDCount){
		if ((i % 3) == 0) {  // First LED, and every third after that
			value.b = 0; 
			value.g = 0; 
			value.r = intensity; // RGB Value -> Red Only
			NeoA.set_crgb_at(i, value); // Set value at LED found at index 0
		}
		else if ((i % 3) == 1) { // Second LED, and every third after that
			value.b = 0; 
			value.g = intensity; 
			value.r = 0; // RGB Value -> Green Only
			NeoA.set_crgb_at(i, value); // Set value at LED found at index 0
		}
		else  { // Third LED, and every third after that
			value.b = intensity; 
			value.g = 0; 
			value.r = 0; // RGB Value -> Blue Only
			NeoA.set_crgb_at(i, value); // Set value at LED found at index 0
		}
		i++;
	}

	NeoA.sync(); // Sends the data to the LEDs
	delay(10); // Wait (ms)
}
