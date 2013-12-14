/*
 * IRsensor.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Ryan.Turner
 */
#include <msp430g2553.h>
#include "IRsensor.h"

void initADC10() {
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
	ADC10CTL1 = ADC10DIV_7;
	ADC10AE0 |= BIT3 | BIT4 | BIT5;
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;
}

unsigned int getLeft() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3 | INCH2 | INCH1 | INCH0);
	ADC10CTL1 |= INCH_3;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getCenter() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3 | INCH2 | INCH1 | INCH0);
	ADC10CTL1 |= INCH_4;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getRight() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3 | INCH2 | INCH1 | INCH0);
	ADC10CTL1 |= INCH_5;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
	// Clear CPUOFF bit from 0(SR)
}
