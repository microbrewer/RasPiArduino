/*
 * This example shows how to use the FS90R library to turn a servo motor
 * attached to GPIO pin 3.
*/

#include <FS90R.h>

int servo_pin = 3;  // GPIO pin used to control the servo

void setup() {
	pinMode(servo_pin, OUTPUT);
}

void loop() {

	servoStep(servo_pin, SERVO_FORWARD);	// turn the servo one step forward
											// for backward, use: SERVO_BACKWARD
	delay(5);                           	// wait for the servo to complete the step
}
