// Lectura ADC
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

int sensorPin = A0;
float sensorValue = 0;
float sensorVoltage = 0;

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Lectura del ADC y conversion a valor de tension (10 bit - 3.3 V)
  sensorValue = analogRead(sensorPin);
  sensorVoltage = sensorValue*3.3/1023;
  // Muestra por pantalla el valor de tension
  Serial.print("The value is: ");
  Serial.println(sensorVoltage);
  // Espera de 1 segundo
  delay(1000);
}
