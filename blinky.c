/* LED Bike Blirker for Teensy ATMEL Board
 * http://www.pjrc.com/teensy/
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define CONFIG_OUT_B(n) (DDRB |= (1<<n))
#define CONFIG_IN_B(n) (DDRB &= ~(1<<n))
#define LED_OFF_B(n)   (PORTB &= ~(1<<n))
#define LED_ON_B(n)    (PORTB |= (1<<n))
#define CONFIG_OUT_C(n) (DDRC |= (1<<n))
#define CONFIG_IN_C(n) (DDRC &= ~(1<<n))
#define LED_OFF_C(n)   (PORTC &= ~(1<<n))
#define LED_ON_C(n)    (PORTC |= (1<<n))
#define CONFIG_IN_D(n) (DDRD &= ~(1<<n))
#define CONFIG_OUT_D(n)	(DDRD |= (1<<n))
#define LED_OFF_D(n)		(PORTD &= ~(1<<n))
#define LED_ON_D(n)		(PORTD |= (1<<n))
#define CONFIG_OUT_E(n)	(DDRE |= (1<<n))
#define LED_OFF_E(n)		(PORTE &= ~(1<<n))
#define LED_ON_E(n)		(PORTE |= (1<<n))
#define CONFIG_OUT_F(n)	(DDRF |= (1<<n))
#define LED_OFF_F(n)		(PORTF &= ~(1<<n))
#define LED_ON_F(n)		(PORTF |= (1<<n))
#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))
#define ON		1
#define OFF		0
#define TRI_RED			1
#define TRI_GREEN		2
#define TRI_ORANGE	3

/*
Wired Pins 1-Nov-2012
B4 - Rear rack green LED #1 (OK)
B5 - Read rack green LED #2 (BAD)
C6 IN- OnTube Toggle Switch
C7 - Headlamp while LED (OK)
D3 IN- OnTube Momentary Switch
D4 - Handlebars blue LEDs (OK)
D6 - Internal yellow LED
D7 - Forks blue LEDs (OK)
F7 - (BAD)
*/

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
  CONFIG_OUT_C(7);
	CONFIG_OUT_D(0);
	CONFIG_OUT_D(1);
	CONFIG_OUT_D(2);
	CONFIG_IN_D(3); // switch
  LED_ON_D(3); // pullup resistor
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

void headlamp(int onoff) {
  if(onoff == ON) {
    LED_ON_C(7);
  } else {
    LED_OFF_C(7);
  }
}

void handlebars(int onoff) {
  if(onoff == ON) {
    LED_ON_D(4);
  } else {
    LED_OFF_D(4);
  }
}

void forks(int onoff) {
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
    LED_ON_B(4);
  } else {
    LED_OFF_B(4);
  }
}

void all_off() {
  onboardled(OFF);
  headlamp(OFF);
  handlebars(OFF);
  forks(OFF);
  backleft(OFF);
  backright(OFF);
}

int main(void) {
	setup();
  all_off();

	// blink
	while (1) {
    if(PINC & (1<<6)) {
      onboardled(ON);
      headlamp(ON);
      handlebars(ON);
      forks(ON);
      backleft(ON);
      backright(ON);
  		_delay_ms(250);

      forks(OFF);
      _delay_ms(150);

      forks(ON);
      handlebars(OFF);
      backleft(ON);
      backright(OFF);
      _delay_ms(250);

      handlebars(ON);
      backleft(OFF);
      backright(ON);
      _delay_ms(250);
    } else {
      all_off();
      onboardled(ON);
      _delay_ms(250);
      onboardled(OFF);
      _delay_ms(250);
    }
	}
}

