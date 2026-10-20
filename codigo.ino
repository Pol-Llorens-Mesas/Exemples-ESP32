// En aquest arxiu veurem les diferents variables de C i els seus usos i funcionament.

// Const serveix per crear una constant, és a dir, un valor que un cop definit no pot tornar a canviar mai més durant tot el programa.
const int ledpin = 2; 

// Int es fa servir per guardar números enters, ni massa grans ni amb decimals.
int comptador = 0; 

// Long és un enter però molt més gran.
long tempsespera = 1000; 

// Float s'utilitza sempre que necessitem números amb decimals.
float temperatura = 23.5; 

// Char serveix per guardar un sol caràcter o lletra, sempre posat entre cometes simples.
char estat = 'a'; 

// Bool és un tipus de dada booleana que només pot valer true (cert) o false (fals).
bool encendida = true; 

// Funcio de startup que inicialitza els components i pins que utilitza el nostre projecte.

void setup() {
  // Serial.begin s'utilitza per iniciar la comunicació amb l'ordinador a través del port sèrie indicant la velocitat en baudis.
  Serial.begin(115200); 
  
  // PinMode serveix per configurar un pin del microcontrolador dient-li si ha de funcionar com a entrada (INPUT) o sortida (OUTPUT).
  pinMode(ledpin, OUTPUT); 
  
  // Serial.println serveix per enviar una línia de text al monitor sèrie i després saltar a la línia següent.
  Serial.println("Comencem el programa");
}

void loop() {
  // DigitalWrite serveix per que un pin estigui actiu o apagat.
  digitalWrite(ledpin, HIGH); 
  Serial.println("LED encès");
  
  // Delay s'utilitza per pausar o congelar el programa durant els mil·lisegons que li passis dintre del parèntesi.
  delay(tempsespera); 

  digitalWrite(ledpin, LOW); 
  Serial.println("LED apagat");
  delay(tempsespera); 

  comptador = comptador + 1; 
  tempsespera = tempsespera + 100;

  // Serial.print serveix exactament igual que el println però sense fer salt de línia.
  Serial.print("Quantes vegades s'ha fet: ");
  Serial.println(comptador);
  
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
}
