/*
 * This example shows how to use the iopi library to connect
 * to an IoPi server and post a simple "Hello World" event
 * every five seconds.
 */

#include <micropi.h>

// Die Adresse des IoPi Servers, mit dem wir uns verbinden wollen:
String server = "http://vm-11.cses.informatik.hu-berlin.de";

// Der name unseres Projektes
String project = "My First Project";

// Das IoPi-Projekt:
IoPiProject iopi;

void setup() {
	// Initialisiere das Projekt.
	iopi.begin(server, project);
}

void loop() {

	// Sende "Hello Server" an den Server.
	iopi.postEvent("Hello Server!");

	// Warte 5 Sekunden.
	delay(5000);
}


