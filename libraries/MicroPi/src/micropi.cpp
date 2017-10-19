/*
 * iopi.cpp
 *
 *  Created on: Aug 30, 2017
 *      Author: michael
 */


#include "micropi.h"

/**
 * SERVOR MOTOR CONTROL
 * ====================
 */
void servoStep(int pin, int dir) {

	if(dir != SERVO_FORWARD && dir != SERVO_BACKWARD) {
		dir = SERVO_STOP;
	}

	digitalWrite(pin, HIGH);
	usleep(dir);
	digitalWrite(pin, LOW);
	usleep(1000);
}



/**
 * INTERNET OF PI
 * ==============
 */

void IoPiProject::begin(const char *url, const char *project) {
	init(url, project);
}

void IoPiProject::begin(String &url, String &project) {
	init(url.c_str(), project.c_str());
}

void IoPiProject::init(const char* url, const char * project) {
	Bridge.begin();
	this->m_baseUrl = url;
	this->m_project = project;
	encodeUrl(this->m_project); // TODO: is this necessary?
}

unsigned int IoPiProject::postData(const char* sensorName, int value) {
	String strSensorName = sensorName;
	encodeUrl(strSensorName);
	String url = this->m_baseUrl + "/sensor/" + this->m_project + "/" + strSensorName + "/" + value;
	return this->m_httpClient.post(url.c_str(), "");
}

unsigned int IoPiProject::postData(String &sensorName, int value) {
	return postData(sensorName.c_str(), value);
}

unsigned int IoPiProject::postEvent(const char* event) {
	String strEvent = event;
	encodeUrl(strEvent);
	String url = this->m_baseUrl + "/event/" + this->m_project + "/" + strEvent;
	return this->m_httpClient.post(url.c_str(), "");
}

unsigned int IoPiProject::postEvent(String &event) {
	return postEvent(event.c_str());
}

String IoPiProject::getCommand() {
	String url = this->m_baseUrl + "/commands/" + this->m_project;
	String cmd = "";
	if(this->m_httpClient.get(url) == 0) {
		while(this->m_httpClient.available()) {
			cmd += (char)(this->m_httpClient.read());
		}
	}
	return cmd;
}

void IoPiProject::encodeUrl(String &url) {
	url.replace("\%", "\%25");
	url.replace(" ", "\%20");
	url.replace("!", "\%21");
	url.replace("*", "\%2A");
	url.replace("'", "\%27");
	url.replace("(", "\%28");
	url.replace(")", "\%29");
	url.replace(";", "\%3B");
	url.replace(":", "\%3A");
	url.replace("@", "\%40");
	url.replace("&", "\%26");
	url.replace("=", "\%3D");
	url.replace("+", "\%2B");
	url.replace("$", "\%24");
	url.replace(",", "\%2C");
	url.replace("/", "\%2F");
	url.replace("?", "\%3F");
	url.replace("#", "\%23");
	url.replace("[", "\%5B");
	url.replace("]", "\%5D");
}



