/*
 * FS90R.h
 *
 *  Created on: Oct 5, 2017
 *      Author: michael
 */

#ifndef LIBRARIES_FS90R_SRC_FS90R_H_
#define LIBRARIES_FS90R_SRC_FS90R_H_

#include <Arduino.h>

#define SERVO_FORWARD		2000
#define SERVO_BACKWARD		1000
#define SERVO_STOP			1500

void servoStep(int pin, int dir);

#endif /* LIBRARIES_FS90R_SRC_FS90R_H_ */
