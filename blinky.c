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

int main(void)
{
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

	// blink
	while (1) {
		LED_ON_D(0);
		LED_ON_D(1);
		LED_ON_D(2);
		LED_ON_D(3);
		LED_ON_D(4);
		LED_ON_D(5);
		LED_ON_D(6);
		LED_ON_D(7);
		LED_ON_E(0);
		LED_OFF_E(1);
		LED_ON_F(0);
		LED_ON_F(1);
		LED_ON_F(2);
		LED_ON_F(3);
		LED_ON_F(4);
		LED_ON_F(5);
		LED_ON_F(6);
		LED_ON_F(7);
		_delay_ms(750);
		LED_OFF_D(0);
		LED_OFF_D(1);
		LED_OFF_D(2);
		LED_OFF_D(3);
		LED_OFF_D(4);
		LED_OFF_D(5);
		LED_OFF_D(6);
		LED_OFF_D(7);
		LED_OFF_E(0);
		LED_ON_E(1);
		LED_OFF_F(0);
		LED_OFF_F(1);
		LED_OFF_F(2);
		LED_OFF_F(3);
		LED_OFF_F(4);
		LED_OFF_F(5);
		LED_OFF_F(6);
		LED_OFF_F(7);
		_delay_ms(750);
	}
}
