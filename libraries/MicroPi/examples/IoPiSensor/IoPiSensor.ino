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
String server = "http://vm-11.cses.informatik.hu-berlin.de";

// Der name unseres Projektes
String project = "My First Project";

// Das IoPi-Projekt:
IoPiProject iopi;

void setup() {
	// Starte den Seriellen Monitor
	Console.begin();

	// Initialisiere das IoPi Projekt.
	iopi.begin(server, project);

	// Starte den AD-Wandler
	adw.begin();			// initialisiere den ADW
	adw.setGain(GAIN_ONE);  // für eine analoge Spannung von +/- 4V
}

// loop, wird wiederholt ausgeführt
void loop() {

	// Lies den Wert an A2
	int analogIn = adw.readADC_SingleEnded(2);

	// Schicke den Wert an den IoPi Server
	iopi.postData("Helligkeit", analogIn);

	delay(1000);
}


