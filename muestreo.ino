int Lm35=A0;
float Voltaje, Valor, T;
const int pinPWM = 9; 

     
void setup() {
  pinMode(Lm35,INPUT);
  pinMode(pinPWM, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  Valor = analogRead(Lm35);     // Lectura del sensor
  Voltaje = Valor*(5./1023.);   // Calculo de Voltaje
  T = Voltaje*100.;             // Cálculo de Temperatura
  
  Serial.print("Voltaje: ");
  Serial.print(Voltaje);      // Imprime el valor del voltaje y salta a la sig linea
  Serial.print("\tTemperatura: ");
  Serial.print(T);
  Serial.print("\tTiempo: ");
  Serial.println(millis());  // Envía el tiempo en milisegundos

  analogWrite(pinPWM,102);
  delay(250);
}
