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
#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

int main(void)
{
	// set for 16 MHz clock, and make sure the LED is off
	CPU_PRESCALE(0);
	LED_CONFIG_D(4);
	LED_CONFIG_D(5);
	LED_CONFIG_D(6);
	LED_CONFIG_E(0);
	LED_CONFIG_E(1);

	// blink
	while (1) {
		LED_ON_D(4);
		LED_ON_D(5);
		LED_ON_D(6);
		LED_ON_E(0);
		LED_OFF_E(1);
		_delay_ms(1000);
		LED_OFF_D(4);
		LED_OFF_D(5);
		LED_OFF_D(6);
		LED_OFF_E(0);
		LED_ON_E(1);
		_delay_ms(1000);
	}
}
