
/*
  Project: Blink
  Description: Fa parpellejar un LED connectat al pin 23.
*/

// Definim una constant per al pin on hem connectat el LED
const int LED_PIN = 23;

// Variables per configurar els temps
int TEMPS_ENCES = 1000;
int TEMPS_APAGAT = 1000;

// La funció setup() s'executa un cop quan la placa arrenca
void setup() {
  // Configurem el pin del LED com una SORTIDA (OUTPUT)
  pinMode(LED_PIN, OUTPUT);
}

// La funció loop() s'executa contínuament
void loop() {
  digitalWrite(LED_PIN, HIGH);  // Encén el LED
  delay(TEMPS_ENCES);           // Espera el temps d'encesa

  digitalWrite(LED_PIN, LOW);   // Apaga el LED
  delay(TEMPS_APAGAT);          // Espera el temps d'apagat
}
