/*
  Exemples ESP32 - Comptador de pulsacions d'un botó

  Compta quantes vegades s'ha premut un botó, amb antirebot (debounce).
  Es pot provar a l'emulador Wokwi (https://wokwi.com/).

  Connexions:
    - Un terminal del botó al GPIO 13
    - L'altre terminal del botó a GND
  (S'utilitza INPUT_PULLUP: en repòs el pin llegeix HIGH, i en prémer LOW)
*/

#define BUTTON_PIN    13   // GPIO13 connectat al botó
#define DEBOUNCE_TIME 50   // temps antirebot en mil·lisegons

// Variables per a la lògica antirebot
int lastSteadyState = HIGH;       // estat estable anterior (HIGH = no premut)
int lastFlickerableState = HIGH;  // darrera lectura (pot tenir rebots)
int currentState;
unsigned long lastDebounceTime = 0;

// Comptador de pulsacions
unsigned int comptador = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("Comptador de pulsacions iniciat");
  Serial.println("Prem el botó...");
}

// Retorna true només un cop per cada pulsació (flanc de baixada)
bool button() {
  currentState = digitalRead(BUTTON_PIN);

  // Si l'estat ha canviat, reiniciem el temporitzador antirebot
  if (currentState != lastFlickerableState) {
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
  }

  // Si l'estat porta estable prou temps, el considerem vàlid
  if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {
    if (lastSteadyState != currentState) {
      lastSteadyState = currentState;
      // true si el botó s'acaba de prémer (LOW amb INPUT_PULLUP)
      return (currentState == LOW);
    }
  }

  return false;
}

void loop() {
  if (button()) {
    comptador++;
    Serial.print("Botó premut. Total de pulsacions: ");
    Serial.println(comptador);
  }
}
