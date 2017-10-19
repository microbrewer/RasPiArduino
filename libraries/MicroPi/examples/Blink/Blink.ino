/*
 * Dieses Beispiel zeigt, wie du eine LED zum Blinken bringen kannst.
 */

// LED pin
int LED;

// Die setup Funktion wird einmal am Anfang ausgeführt.
void setup() {

	// Die LED hängt an Pin 26
	LED = 26;

	// initialisiere den Pin als output
	pinMode(LED, OUTPUT);
}

// Die loop Funktion wird endlos in einer Schleife wiederholt.
void loop() {

	digitalWrite(LED, HIGH);	// schalte die LED an (HIGH steht für die elektrische Spannung)
	delay(1000);				// warte eine Sekunde (1000 Milisekunden)
	digitalWrite(LED, LOW);		// schalte die LED aus (indem die Spannung auf LOW gestellt wird)
	delay(1000);				// warte eine Sekunde
}


