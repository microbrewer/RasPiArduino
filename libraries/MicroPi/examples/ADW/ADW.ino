/*
 * Dieses Beispiel zeigt, wie der AD-Wandler ADS1015 genutzt
 * werden kann, um den digitalisierten Wert eines analogen
 * Sensors auszulesen. Liegt der Wert unter einer bestimmten
 * Grenze, soll eine LED eingeschaltet werden.
 */

// Importiere die Bibliothek für den Analog-Digial-Wandler (ADW)
#include <Adafruit_ADS1015.h>

// Definiere den ADW
Adafruit_ADS1015 adw;

// LED pin
int LED;

// setup, wird einmal am Anfang ausgeführt.
void setup() {

	// Die LED hängt an Pin 26
	LED = 26;
	pinMode(LED, OUTPUT);

	// Starte den Seriellen Monitor
	Console.begin();

	// Starte den AD-Wandler
	adw.begin();			// initialisiere den ADW
	adw.setGain(GAIN_ONE);  // für eine analoge Spannung von +/- 4V
}

// loop, wird wiederholt ausgeführt
void loop() {

	// Lies den Wert an A2
	int analogIn = adw.readADC_SingleEnded(2);

	// Gib den Wert auf dem seriellen Monitor aus
	Console.println(analogIn);

	// Wenn es dunkel ist, mach das Licht an
	if(analogIn < 1000) {
		digitalWrite(LED, HIGH);

	// Wenn nicht, mach es aus.
	} else {
		digitalWrite(LED, LOW);
	}

	// Warte ein bisschen
	delay(100);
}


