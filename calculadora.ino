// Calculadora con teclado 4x4 en ESP32
// A suma, B resta, C multiplica, D divide
// # calcula, * borra

#include <Keypad.h>

const int FILAS = 4;
const int COLUMNAS = 4;

char teclas[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinesFilas[FILAS] = {19, 18, 5, 17};
byte pinesColumnas[COLUMNAS] = {16, 4, 2, 15};

Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

String numero1 = "";
String numero2 = "";
String operacion = "";

void borrarTodo() {
  numero1 = "";
  numero2 = "";
  operacion = "";
}

String simbolo(char tecla) {
  if (tecla == 'A') return "+";
  if (tecla == 'B') return "-";
  if (tecla == 'C') return "*";
  return "/";
}

void calcular() {
  if (numero1 == "" || numero2 == "" || operacion == "") {
    Serial.println();
    Serial.println("Faltan datos");
    borrarTodo();
    return;
  }

  float a = numero1.toFloat();
  float b = numero2.toFloat();
  float resultado = 0;

  if (operacion == "+") resultado = a + b;
  if (operacion == "-") resultado = a - b;
  if (operacion == "*") resultado = a * b;
  if (operacion == "/") {
    if (b == 0) {
      Serial.println();
      Serial.println("Error: division por cero");
      borrarTodo();
      return;
    }
    resultado = a / b;
  }

  Serial.print(" = ");
  Serial.println(resultado);
  borrarTodo();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Calculadora ESP32");
}

void loop() {
  char tecla = teclado.getKey();

  if (tecla == NO_KEY) {
    return;
  }

  if (tecla >= '0' && tecla <= '9') {
    if (operacion == "") {
      numero1 = numero1 + tecla;
    } else {
      numero2 = numero2 + tecla;
    }
    Serial.print(tecla);
  }
  else if (tecla >= 'A' && tecla <= 'D') {
    if (numero1 != "" && operacion == "") {
      operacion = simbolo(tecla);
      Serial.print(" ");
      Serial.print(operacion);
      Serial.print(" ");
    }
  }
  else if (tecla == '#') {
    calcular();
  }
  else if (tecla == '*') {
    borrarTodo();
    Serial.println();
    Serial.println("Borrado");
  }
}
