#include <msp430g2553.h>
#include "moveRobot.h"
#include "IRsensor.h"

/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initADC10();

	initPinOuts();
	timersConfig();

	for (;;) {
		if (getCenter() > 0x22A) {
			rightTurn();
			_delay_cycles(20000);
		} else if (getLeft() > 0x3A0) {
			rightTurn();
			_delay_cycles(5000);
		} else if (getLeft() < 0x199) {
			leftHairpin();
			_delay_cycles(3000);
		} else {
			moveForward();
			_delay_cycles(1000);
		}

	}

	return 0;
}
