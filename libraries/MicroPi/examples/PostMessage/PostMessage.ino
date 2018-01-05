/*
 * Dieses Beispiel zeigt, wie sich der Raspberry Pi mit einem
 * IoPi Server verbindet, um ihm danach alle 5 Sekunden eine
 * "Hello Server" Nachricht zu schicken.
 */

#include <Bridge.h>
#include <micropi.h>

// Die Adresse des IoPi Servers, mit dem wir uns verbinden wollen:
String adresse = "http://iopi.informatik.hu-berlin.de";

// Der name unseres Projektes
String projekt = "Mein Projekt";

// Das IoPi-Projekt:
IoPiServer server;

void setup() {
	// Initialisiere das Projekt.
	server.begin(adresse, projekt);
}

void loop() {

	// Sende "Hello Server" an den Server.
	server.postMessage("Hallo Server!");

	// Warte 5 Sekunden.
	delay(5000);
}


