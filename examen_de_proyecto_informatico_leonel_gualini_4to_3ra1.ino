// Constantes para los pines de los LEDs RGB
const int pinRojo = 9;
const int pinVerde = 10;
const int pinAzul = 11;

// Constante para el pin del botón
const int pinBoton = 2;

// Variables para almacenar los valores de las resistencias variables
int valorResistenciaRojo = 0;
int valorResistenciaVerde = 0;
int valorResistenciaAzul = 0;

// Variable para almacenar el estado del botón
int estadoBoton = LOW;

void setup() {
  // Configurar los pines de los LEDs RGB como salidas
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);

  // Configurar el pin del botón como entrada
  pinMode(pinBoton, INPUT_PULLUP);
  
  // Iniciar la comunicación serial para mostrar los colores por consola
  Serial.begin(9600);
}

void loop() {
  // Leer el estado del botón
  estadoBoton = digitalRead(pinBoton);
  
  // Si el botón está presionado, mostrar el color
  if (estadoBoton != HIGH) {
    mostrarColor();
  } else {
    // Si el botón no está presionado, apagar los LEDs
    apagarLEDs();
  }
}

void mostrarColor() {
  // Leer los valores de las resistencias variables
  valorResistenciaRojo = analogRead(A0);
  valorResistenciaVerde = analogRead(A1);
  valorResistenciaAzul = analogRead(A2);

  // Mapear los valores de las resistencias a la escala de 0 a 255 para el brillo de los LEDs
  int brilloRojo = map(valorResistenciaRojo, 0, 1023, 0, 255);
  int brilloVerde = map(valorResistenciaVerde, 0, 1023, 0, 255);
  int brilloAzul = map(valorResistenciaAzul, 0, 1023, 0, 255);

  // Encender los LEDs con los colores configurados
  analogWrite(pinRojo, 255);
  analogWrite(pinVerde, 255);
  analogWrite(pinAzul, 255);

  // Mostrar el color por consola
  Serial.print("(R: ");
  Serial.print(brilloRojo);
  Serial.print(" ; G: ");
  Serial.print(brilloVerde);
  Serial.print(" ; B: ");
  Serial.print(brilloAzul);
  Serial.println(")");
}

void apagarLEDs() {
  // Apagar los LEDs
  analogWrite(pinRojo, 0);
  analogWrite(pinVerde, 0);
  analogWrite(pinAzul, 0);
}