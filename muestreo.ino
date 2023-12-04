int Lm35 = A0;
float Voltaje, Valor, T;
const int pinPWM = 9;
int vueltas = 0;  // Variable para contar las vueltas
float x = 0.0;    // Variable para el valor de x
unsigned long previousMillis = 0;
unsigned long interval = 250;  // 250 ms

void setup() {
  pinMode(Lm35, INPUT);
  pinMode(pinPWM, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();  // Obtener el tiempo actual en milisegundos

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    Valor = analogRead(Lm35);     // Lectura del sensor
    Voltaje = Valor * (5. / 1023.);   // Calculo de Voltaje
    T = Voltaje * 100.;             // Cálculo de Temperatura

    Serial.print("Tiempo: ");
    Serial.print(currentMillis);  
    Serial.print("\tTemperatura: ");
    Serial.print(T);
    Serial.print("\tValor de entrada: ");
    Serial.println(x);

    // Condiciones para cambiar el valor de x
    if (vueltas < 20) {
      x = 0.0;
    } else if (vueltas < 500) {  
      x = 0.4;
    } else {
      x = 0.2;
    }

    analogWrite(pinPWM, 255 * x);

    vueltas++;
  }
}
