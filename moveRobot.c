/*
 * moveRobot.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Ryan.Turner
 */
#include <msp430.h>
#include "moveRobot.h"

void initPinOuts() {
	P1DIR |= BIT1;
	P1SEL |= BIT1;

	P1DIR |= BIT2;
	P1SEL |= BIT2;

	P2DIR |= BIT0;
	P2SEL |= BIT0;

	P2DIR |= BIT1;
	P2SEL |= BIT1;
}

void timersConfig() {
	TA0CTL &= ~MC1 | MC0;
	TA1CTL &= ~MC1 | MC0;

	TA0CTL |= TACLR;
	TA1CTL |= TACLR;

	TA0CTL |= TASSEL1;
	TA1CTL |= TASSEL1;

	TA0CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR0 = 100;
	TA0CCR1 = 0;
	TA1CCR1 = 0;

	TA0CCTL1 |= OUTMOD_7;
	TA0CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 |= OUTMOD_5;

	TA0CTL |= MC0;
	TA1CTL |= MC0;               // count up
}

void leftMotorForward() {
	TA0CCR1 = 50;
	TA0CCTL0 = OUTMOD_5;
}

void leftMotorBackward() {
	TA0CCR1 = 0;
	TA0CCTL0 = OUTMOD_4;
}

void rightMotorForward() {
	TA1CCR1 = 0;
	TA1CCTL0 = OUTMOD_4;
}

void rightMotorBackward() {
	TA1CCR1 = 60;
	TA1CCTL0 = OUTMOD_5;
}

void leftTurn() {
	leftMotorBackward();
	rightMotorForward();
}

void rightTurn() {
	leftMotorForward();
	rightMotorBackward();
}

void moveForward() {
	leftMotorForward();
	rightMotorForward();
}

void moveBackward() {
	leftMotorBackward();
	rightMotorBackward();
}

void pause(){

}
