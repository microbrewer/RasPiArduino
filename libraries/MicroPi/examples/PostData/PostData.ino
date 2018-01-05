/*
 * Dieses Beispiel zeigt, wie der AD-Wandler ADS1015 genutzt
 * werden kann, um den digitalisierten Wert eines analogen
 * Sensors auszulesen. Danach wird der Sensorwert an einen
 * IoPi Server gechickt.
 */

#include <Bridge.h>
#include <micropi.h>
#include <Adafruit_ADS1015.h>

// Definiere den ADW
Adafruit_ADS1015 adw;

// Die Adresse des IoPi Servers, mit dem wir uns verbinden wollen:
String adresse = "http://iopi.informatik.hu-berlin.de";

// Der name unseres Projektes
String projekt = "Mein Projekt";

// Das IoPi-Projekt:
IoPiServer server;

void setup() {
	// Initialisiere das IoPi Projekt.
	server.begin(adresse, projekt);

	// Starte den AD-Wandler
	adw.begin();			// initialisiere den ADW
	adw.setGain(GAIN_ONE);  // für eine analoge Spannung von +/- 4V
}

// loop, wird wiederholt ausgeführt
void loop() {

	// Lies den Wert an A2
	int analogIn = adw.readADC_SingleEnded(2);

	// Schicke den Wert an den IoPi Server
	server.postData("Helligkeit", analogIn);

	delay(1000);
}


