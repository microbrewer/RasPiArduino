/*
 * FS90R.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: michael
 */


#include "../../FS90R/src/FS90R.h"

void servoStep(int pin, int dir) {

	if(dir != SERVO_FORWARD && dir != SERVO_BACKWARD) {
		dir = SERVO_STOP;
	}

	digitalWrite(pin, HIGH);
	usleep(dir);
	digitalWrite(pin, LOW);
	usleep(1000);
}
