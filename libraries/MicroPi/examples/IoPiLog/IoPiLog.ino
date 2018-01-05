/*
 * Dieses Beispiel zeigt, wie sich der Raspberry Pi mit einem
 * IoPi Server verbindet, um ihm danach alle 5 Sekunden eine
 * "Hello Server" Nachricht zu schicken.
 */

#include <Bridge.h>
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


