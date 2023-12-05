#include <PID_v1.h>

// Definición de pines
const int sensorPin = A0;
const int outputPin = 9; // Pin PWM de salida
const int Pot = A1;
// Parámetros PID

double Kp = 0.729;         // Ganancia proporcional
double Ki = 0.0103;        // Ganancia integral
double Kd = 12.9;          // Ganancia derivativa

// Variables PID
double input, output, setpoint; // Declara setpoint aquí

// Parámetros de conversión
const double voltageConversion = 5.0 / 1023.0;  // Convertir lectura analógica a voltaje
const double temperatureConversion = 100.0;      // Convertir voltaje a temperatura (10mV = 1°C)

// Crear la instancia de PID fuera de cualquier función
PID myPID(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

// Variables para debouncing
unsigned long lastPrintTime = 0; // Tiempo de la última impresión
const unsigned long printInterval = 500; // Intervalo mínimo entre impresiones en milisegundos

void setup() {
  // Inicialización de pines
  pinMode(outputPin, OUTPUT);

  // Inicialización del PID
  myPID.SetMode(AUTOMATIC);
  
  // Ajusta el rango de salida del PID al rango del PWM (0-255)
  myPID.SetOutputLimits(0, 255);

  // Inicia el puerto serie para imprimir valores
  Serial.begin(9600);
}

void loop() {
  setpoint = analogRead(Pot) * voltageConversion * temperatureConversion/5; // Asigna valor a setpoint

  // Lectura de la temperatura desde el sensor (en mV)
  int sensorValue = analogRead(sensorPin)*voltageConversion*temperatureConversion;
  
  // Conversión de lectura analógica a voltaje
  double voltage = sensorValue * voltageConversion;

  // Conversión de voltaje a temperatura en grados Celsius
  input = voltage * temperatureConversion;

  // Cálculo del control PID
  myPID.Compute();

  // Verificar si ha pasado suficiente tiempo desde la última impresión
  if (millis() - lastPrintTime >= printInterval) {
    // Imprimir valores de entrada y salida del PID
    Serial.print("Input: ");
    Serial.print(input);
    Serial.print("   Output: ");
    Serial.print(output);
    Serial.print("   Setpoint: ");
    Serial.println(setpoint);

    // Actualizar el tiempo de la última impresión
    lastPrintTime = millis();
  }

  // Aplicación del PWM para controlar la potencia del elemento calefactor
  analogWrite(outputPin, output);
}
