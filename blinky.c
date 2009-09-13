/* LED Blink Example with USB Debug Channel for Teensy USB Development Board
 * http://www.pjrc.com/teensy/
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define LED_CONFIG_D(n)	(DDRD |= (1<<n))
#define LED_ON_D(n)		(PORTD &= ~(1<<n))
#define LED_OFF_D(n)		(PORTD |= (1<<n))
#define LED_CONFIG_E(n)	(DDRE |= (1<<n))
#define LED_ON_E(n)		(PORTE &= ~(1<<n))
#define LED_OFF_E(n)		(PORTE |= (1<<n))
#define LED_CONFIG_F(n)	(DDRF |= (1<<n))
#define LED_ON_F(n)		(PORTF &= ~(1<<n))
#define LED_OFF_F(n)		(PORTF |= (1<<n))
#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))
#define ON		1
#define OFF		0
#define TRI_RED			1
#define TRI_GREEN		2
#define TRI_ORANGE		3

void setup() {
	// set for 16 MHz clock, and make sure the LED is off
	CPU_PRESCALE(0);
	LED_CONFIG_D(0);
	LED_CONFIG_D(1);
	LED_CONFIG_D(2);
	LED_CONFIG_D(3);
	LED_CONFIG_D(4);
	LED_CONFIG_D(5);
	LED_CONFIG_D(6);
	LED_CONFIG_D(7);
	LED_CONFIG_E(0);
	LED_CONFIG_E(1);
	LED_CONFIG_F(0);
	LED_CONFIG_F(1);
	LED_CONFIG_F(2);
	LED_CONFIG_F(3);
	LED_CONFIG_F(4);
	LED_CONFIG_F(5);
	LED_CONFIG_F(6);
	LED_CONFIG_F(7);
}

void handlebars(int onoff) {
  if(onoff == ON) {
    LED_ON_D(4);
  } else {
    LED_OFF_D(4);
  }
}

void backleft(int onoff) {
  if(onoff == ON) {
    LED_ON_F(6);
  } else {
    LED_OFF_F(6);
  }
}

void backright(int onoff) {
  if(onoff == ON) {
    LED_ON_F(7);
  } else {
    LED_OFF_F(7);
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
                handlebars(ON);
                leftfork(TRI_RED);
                rightfork(TRI_GREEN);
                backleft(ON);
                backright(ON);
		_delay_ms(250);

                leftfork(TRI_GREEN);
                rightfork(TRI_RED);
                backleft(ON);
                backright(OFF);
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

