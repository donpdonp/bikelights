/* LED Bike Blirker for Teensy ATMEL Board
 * http://www.pjrc.com/teensy/
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
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

/*
Wired Pins 1-Nov-2012
B3 W- Headlamp white
B4 W- Rear rack green LED #1
B5 W- Rear left red (PWM) (BAD)
B6 W- Rear left green (PWM)
B7 W- Rear left blue (PWM)
C6 W- Rear right red (PWM)
C7 W- Rear right green (PWM)
D1 W- Forks
D2 W- Handlebar ends
D3 W- Switch OnTube Momentary
D4 W- Handlebars blue LEDs
D5 W- Switch OnTube Toggle
D6 W- Internal yellow LED
D7 W- Rear right blue (PWM)
F7 W- (BAD)
*/

void setup() {

  CPU_PRESCALE(0x03);

  CONFIG_OUT_B(0);
  CONFIG_OUT_B(1);
  CONFIG_OUT_B(2);
  CONFIG_OUT_B(3);
  CONFIG_OUT_B(4);
  CONFIG_OUT_B(5);
  CONFIG_OUT_B(6);
  CONFIG_OUT_B(7);
  CONFIG_OUT_C(6);
  CONFIG_OUT_C(7);
  CONFIG_OUT_D(0);
  CONFIG_OUT_D(1);
  CONFIG_OUT_D(2);
  CONFIG_IN_D(3); // switch
  LED_ON_D(3); // pullup resistor
  CONFIG_OUT_D(4);
  CONFIG_IN_D(5); // switch
  LED_ON_D(5); // pullup resistor
  CONFIG_OUT_D(6);
  CONFIG_OUT_D(7);
  CONFIG_OUT_F(7);
}

void headlamp(int onoff) {
  if(onoff == ON) {
    LED_ON_B(3);
  } else {
    LED_OFF_B(3);
  }
}

void handlebars(int onoff) {
  if(onoff == ON) {
    LED_ON_D(2);
  } else {
    LED_OFF_D(2);
  }
}

void forks(int onoff) {
  if(onoff == ON) {
    LED_ON_D(1);
  } else {
    LED_OFF_D(1);
  }
}

void onboardled(int onoff) {
  if(onoff == ON) {
    LED_ON_D(6);
  } else {
    LED_OFF_D(6);
  }
}

void rack(int onoff) {
  if(onoff == ON) {
    LED_ON_B(4);
  } else {
    LED_OFF_B(4);
  }
}

void backleft(int onoff) {
  if(onoff == ON) {
    LED_ON_B(5);
    LED_ON_B(6);
    LED_ON_B(7);
  } else {
    LED_OFF_B(5);
    LED_OFF_B(6);
    LED_OFF_B(7);
  }
}

void backright(int onoff) {
  if(onoff == ON) {
    LED_ON_C(6);
    LED_ON_C(7);
    LED_ON_D(7);
  } else {
    LED_OFF_C(6);
    LED_OFF_C(7);
    LED_OFF_D(7);
  }
}

void all_off() {
  onboardled(OFF);
  headlamp(OFF);
  handlebars(OFF);
  forks(OFF);
  rack(OFF);
  backleft(OFF);
  backright(OFF);
}

// todo: timer to wake up from idle
void idle() {
  set_sleep_mode(SLEEP_MODE_IDLE);
  cli();
  sleep_enable();
  sei();
  sleep_cpu();
  sleep_disable();
}

// blink each light individually once
void around_the_world() {
  int delay = 100;

  LED_ON_B(3);
  _delay_ms(delay);
  LED_OFF_B(3);
  _delay_ms(delay);
  LED_ON_B(4);
  _delay_ms(delay);
  LED_OFF_B(4);
  _delay_ms(delay);
  LED_ON_B(5);
  _delay_ms(delay);
  LED_OFF_B(5);
  _delay_ms(delay);
  LED_ON_B(6);
  _delay_ms(delay);
  LED_OFF_B(6);
  _delay_ms(delay);
  LED_ON_B(7);
  _delay_ms(delay);
  LED_OFF_B(7);
  _delay_ms(delay);
  LED_ON_C(6);
  _delay_ms(delay);
  LED_OFF_C(6);
  _delay_ms(delay);
  LED_ON_C(7);
  _delay_ms(delay);
  LED_OFF_C(7);
  _delay_ms(delay);
  LED_ON_D(1);
  _delay_ms(delay);
  LED_OFF_D(1);
  _delay_ms(delay);
  LED_ON_D(2);
  _delay_ms(delay);
  LED_OFF_D(2);
  _delay_ms(delay);
  LED_ON_D(4);
  _delay_ms(delay);
  LED_OFF_D(4);
  _delay_ms(delay);
  LED_ON_D(6);
  _delay_ms(delay);
  LED_OFF_D(6);
  _delay_ms(delay);
  LED_ON_D(7);
  _delay_ms(delay);
  LED_OFF_D(7);
  _delay_ms(delay);

}

int main(void) {
  setup();
  all_off();
  around_the_world();

  // blink
  while (1) {
    if(PIND & (1<<5)) {
      onboardled(ON);
      headlamp(ON);
      handlebars(ON);
      forks(ON);
      backleft(ON);
      backright(ON);
      rack(OFF);
      _delay_ms(250);

      forks(OFF);
      rack(ON);
      _delay_ms(150);

      forks(ON);
      handlebars(OFF);
      backleft(ON);
      backright(OFF);
      rack(OFF);
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

