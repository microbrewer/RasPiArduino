/*
 * Diese Beispiel zeigt, wie du deinen Raspberry Pi mit einem IoPi-Server
 * verbinden kannst, um von diesem Server Befehle zu empfangen. In diesem
 * Beispiel hier, wird eine LED an- oder ausgeschaltet, je nach dem, welcher
 * Befehl empfangen wird.
 */

#include <Bridge.h>
#include <micropi.h>

// Die Adresse des IoPi Servers, mit dem wir uns verbinden wollen:
String adresse = "http://vm-11.cses.informatik.hu-berlin.de";

// Der name unseres Projektes
String projekt = "My First Project";

// Das IoPi-Projekt:
IoPiServer server;

// LED pin
int LED = 26;

void setup() {
	Console.begin();

	pinMode(LED, OUTPUT);
	digitalWrite(LED, LOW);

	server.begin(server, projekt);
}

void loop() {

	// Schau nach, ob auf dem Server ein Befehl für uns vorliegt. Sollte kein
	// Befehl vorliegen, oder etwas schief gehen, erhalten wir einen leeren String.
	String befehl = server.getCommand();

	// Wenn wir "licht an" erhalten haben, schalte die LED an.
	if (befehl == "licht an") {
		digitalWrite(LED, HIGH);

	// Wenn wir "licht aus" erhalten haben, schalte die LED aus.
	} else if (befehl == "licht aus") {
		digitalWrite(LED, LOW);

	// Wenn wir einen anderen Befehl erhalten haben, gib ihn auf dem Monitor aus.
	} else if (befehl != "")  {
		Console.println("Unbekannter Befehl: " + cmd);
	}

	// Warte ein bisschen
	delay(500);
}

