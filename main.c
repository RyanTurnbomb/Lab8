#include <msp430g2553.h>
#include "moveRobot.h"
#include "IRsensor.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	for (;;) {
		getLeft();
		if (ADC10MEM < 0x250)
			rightMotorForward();
		else
			leftMotorForward();
		__delay_cycles(500);
	}

	return 0;
}
