/*
 * iopi.h
 *
 *
 *  Created on: Aug 30, 2017
 *      Author: Michael T. Rücker
 */

#ifndef MICROPI_H_
#define MICROPI_H_

#include <Arduino.h>
#include <Bridge.h>
#include <HttpClient.h>

/**
 * SERVO MOTOR CONTROL
 * ===================
 */
#define SERVO_FORWARD		2000
#define SERVO_BACKWARD		1000
#define SERVO_STOP			1500

void servoStep(int pin, int dir);


/**
 * INTERNET OF PI
 * ==============
 */

class IoPiServer {

private:
	String m_baseUrl;
	String m_project;
	HttpClient m_httpClient;

	void init(const char *url, const char *project);
	void encodeUrl(String &url);

public:
	IoPiServer() {}

	void begin(const char *url, const char *project);
	void begin(String &url, String &project);

	unsigned int postData(String &sensorName, int value);
	unsigned int postData(const char *sensorName, int value);

	unsigned int postMessage(String &event);
	unsigned int postMessage(const char *event);

	String getCommand();
};

#endif /* MICROPI_H_ */
