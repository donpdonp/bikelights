/* LED Blink Example with USB Debug Channel for Teensy USB Development Board
 * http://www.pjrc.com/teensy/
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define CONFIG_OUT_B(n) (DDRB |= (1<<n))
#define CONFIG_IN_B(n) (DDRB &= ~(1<<n))
#define LED_ON_B(n)   (PORTB &= ~(1<<n))
#define LED_OFF_B(n)    (PORTB |= (1<<n))
#define CONFIG_OUT_C(n) (DDRC |= (1<<n))
#define CONFIG_IN_C(n) (DDRC &= ~(1<<n))
#define LED_ON_C(n)   (PORTC &= ~(1<<n))
#define LED_OFF_C(n)    (PORTC |= (1<<n))
#define CONFIG_OUT_D(n)	(DDRD |= (1<<n))
#define LED_ON_D(n)		(PORTD &= ~(1<<n))
#define LED_OFF_D(n)		(PORTD |= (1<<n))
#define CONFIG_OUT_E(n)	(DDRE |= (1<<n))
#define LED_ON_E(n)		(PORTE &= ~(1<<n))
#define LED_OFF_E(n)		(PORTE |= (1<<n))
#define CONFIG_OUT_F(n)	(DDRF |= (1<<n))
#define LED_ON_F(n)		(PORTF &= ~(1<<n))
#define LED_OFF_F(n)		(PORTF |= (1<<n))
#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))
#define ON		1
#define OFF		0
#define TRI_RED			1
#define TRI_GREEN		2
#define TRI_ORANGE	3

void setup() {
	// set for 16 MHz clock, and make sure the LED is off
	CPU_PRESCALE(0);
	CONFIG_OUT_B(0);
	CONFIG_OUT_B(1);
	CONFIG_OUT_B(2);
  CONFIG_OUT_B(3);
  CONFIG_OUT_B(4);
  CONFIG_OUT_B(5);
  CONFIG_OUT_B(6);
  CONFIG_IN_C(6); // switch
  LED_ON_C(6); // pullup resistor
	CONFIG_OUT_D(0);
	CONFIG_OUT_D(1);
	CONFIG_OUT_D(2);
	CONFIG_OUT_D(3);
	CONFIG_OUT_D(4);
	CONFIG_OUT_D(5);
	CONFIG_OUT_D(6);
	CONFIG_OUT_D(7);
	CONFIG_OUT_E(0);
	CONFIG_OUT_E(1);
	CONFIG_OUT_F(0);
	CONFIG_OUT_F(1);
	CONFIG_OUT_F(2);
	CONFIG_OUT_F(3);
	CONFIG_OUT_F(4);
	CONFIG_OUT_F(5);
	CONFIG_OUT_F(6);
	CONFIG_OUT_F(7);
}

void handlebars(int onoff) {
  if(onoff == ON) {
    LED_ON_D(7);
  } else {
    LED_OFF_D(7);
  }
}

void onboardled(int onoff) {
  if(onoff == ON) {
    LED_ON_D(6);
  } else {
    LED_OFF_D(6);
  }
}

void backleft(int onoff) {
  if(onoff == ON) {
    LED_ON_B(5);
  } else {
    LED_OFF_B(5);
  }
}

void backright(int onoff) {
  if(onoff == ON) {
    LED_ON_B(6);
  } else {
    LED_OFF_B(6);
  }
}


void leftfork(int color) {
  if(color == OFF) {
		LED_OFF_D(2);
		LED_OFF_D(3);
  }
  if(color == TRI_RED) {
		LED_OFF_D(2);
		LED_ON_D(3);
  }
  if(color == TRI_GREEN) {
		LED_ON_D(2);
		LED_OFF_D(3);
  }
  if(color == TRI_ORANGE) {
		LED_ON_D(2);
		LED_ON_D(3);
  }
}

void rightfork(int color) {
  if(color == OFF) {
		LED_OFF_E(1);
		LED_OFF_E(0);
  }
  if(color == TRI_RED) {
		LED_OFF_E(1);
		LED_ON_E(0);
  }
  if(color == TRI_GREEN) {
		LED_ON_E(1);
		LED_OFF_E(0);
  }
  if(color == TRI_ORANGE) {
		LED_ON_E(1);
		LED_ON_E(0);
  }
}

int main(void) {
	setup();

	// blink
	while (1) {
    if(PINC & (1<<6)) {
      handlebars(ON);
      leftfork(TRI_RED);
      rightfork(TRI_GREEN);
      backleft(ON);
      backright(ON);
      onboardled(OFF);
  		_delay_ms(250);

      leftfork(TRI_GREEN);
      rightfork(TRI_RED);
      backleft(ON);
      backright(OFF);
      onboardled(ON);
  		_delay_ms(250);

      leftfork(TRI_ORANGE);
      rightfork(TRI_ORANGE);
      backleft(OFF);
      backright(ON);
  		_delay_ms(550);

      handlebars(OFF);
      leftfork(OFF);
      rightfork(OFF);
      backleft(OFF);
      backright(OFF);
  		_delay_ms(450);
    }
	}
}

