// Lectura del ADC con/sin los timers y escritura de PWM
// Asignacion de tarea por UART mediante Strings
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <Arduino.h>
#include "BBTimer.hpp"
#include "mbed.h"

// Designacion de un timer de la clase BBTimer para su uso
BBTimer my_t3(BB_TIMER3); 

// Inicializacion de Variables y pines del dispositivo
int sensorPin = A0;
int PinPWM = D2;
int pwmFrequency = 5000;
int sensorValue = 0;
float sensorVoltage = 0;
bool send = false;
float dutyCycle = 0;

// Asignacion de pin como salida PWM
mbed::PwmOut pwmPin(digitalPinToPinName(PinPWM));

// Funcion de devolucion de llamada del timer
void t3Callback()
{
  send = true; // Semaforo/Flag lectura ADC
}

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);

  // Inicializacion y arranque del timer con una periodicidad ajustable (1 segundo)
  my_t3.setupTimer(1000000, t3Callback);
  my_t3.timerStart();

  // Inicializacion del PWM
  pwmPin.period(1.0/pwmFrequency); // Periodo del PWM
  pwmPin.write(0.5); // Duty inicial de señal cuadrada 50 % de t_on
}

void loop() {
  // put your main code here, to run repeatedly:

  // Si hay valor disponible en el puerto serie se procede a leerlo
  if (Serial.available() > 0){
    // Lectura de una palabra en el puerto serie
    String valor = Serial.readStringUntil('\n'); // Lectura hasta que finaliza la linea
    String subValor = valor.substring(0,4); // Extrae los 4 primeros caracteres de la palabra

    // Decision dependiendo de la palabra leida por el puerto serie
    if(subValor.equals("ADC")){
      // Lectura en el puerto serie de la palabra "ADC"
      // Lectura del ADC y conversion a valor de tension (10 bit - 3.3 V)
      sensorValue = analogRead(sensorPin);
      sensorVoltage = sensorValue*3.3/1023;
      // Muestra por pantalla el valor de la tension
      Serial.print("The value is: ");
      Serial.println(sensorVoltage);
    
    }else if(subValor.equals("ADC(")){
      // Lectura en el puerto serie de la palabra "ADC(x)", subpalabra "ADC("
      // Obtencion de la subpalabra correspondiente a la frecuencia del timer "x"
      String x = valor.substring(valor.indexOf('(')+1, valor.indexOf(')')); // Palabra entre caracteres '(' y ')'
      // Conversion de la subpalabra "x" a un numero entero
      int valFrecuencia = x.toInt();
      // Creacion de una nueva palabra para comparacion
      // Se le añade a esta palabra el subValor "ADC("
      String nuevoADC = subValor;
      // Concatenacion de la nueva palabra con el valor de x (numero entero) y con un ')' de final
      nuevoADC.concat(valFrecuencia);
      nuevoADC.concat(')');
      // Conversion de frecuencia de micro segundos a segundos
      int valFrecuenciaseg = valFrecuencia*1000000;
      // Actualizacion del valor del timer y comienzo de este segun el periodo establecido
      my_t3.setupTimer(valFrecuenciaseg, t3Callback);
      my_t3.timerStart();
      // Lectura del ADC si el valor leido en el puerto serie corresponde con la nueva palabra
      if(valor.equals(nuevoADC)){
        // Mientras que el puerto serie este libre y el valor de periodo recibido no son 0 segundos se lee el ADC
        while(Serial.available() == 0 && valFrecuencia != 0){
          // Lectura del ADC si se ha iniciado / devuelto la llamada del timer 
          if(send == true){
            // Lectura del ADC y conversion a valor de tension (10 bit - 3.3 V)
            sensorValue = analogRead(sensorPin);
            sensorVoltage = sensorValue*3.3/1023;
            // Muestra por pantalla el valor de la tension
            Serial.print("The value is: ");
            Serial.println(sensorVoltage);
            // Indicacion final de fin de uso del timer
            send = false;
          }
        }
      }else{
        // La lectura del puerto serie y la nueva palabra no son coincidentes (valoes erroneos)
        Serial.println("Not valid value");
      }

    }else if(subValor.equals("PWM(")){
      // Lectura en el puerto serie de la palabra "PWM(y)", subpalabra "PWM("
      // Obtencion de la subpalabra correspondiente al valor del duty "y" de 0 a 9
      String y = valor.substring(valor.indexOf('(')+1, valor.indexOf(')')); // Palabra entre caracteres '(' y ')'
      // Conversion de la subpalabra "y" a un numero entero
      float duty = y.toFloat();
      // Creacion de una nueva palabra para comparacion
      // Se le añade a esta palabra el subValor "PWM("
      String nuevoDuty = subValor;
      // Concatenacion de la nueva palabra con la palabra "y" y con un ')' de final
      nuevoDuty.concat(y);
      nuevoDuty.concat(')');
      // Asignacion de duty si el valor leido en el puerto serie corresponde con la nueva palabra
      if(valor.equals(nuevoDuty)){
        if(duty > 9){
          // Caso numero escrito en el puerto serie superior a 9
          dutyCycle = 1;
        }else if(duty < 0){
          // Caso numero escrito en el puerto serie inferior a 0
          dutyCycle = 0;
        }else{
          // Asignacion de duty a valores de 0 a 9 y conversion a valores de 0 a 0.9
          dutyCycle = duty/10;
        }
        // Asignacion del valor del ADC al ciclo de duty y llevarlo a valores entre 0 y 1
        pwmPin.write(dutyCycle);
        // Escritura del duty sobre el pin asignado a PWM
        Serial.println(dutyCycle);

      }else{
        // La lectura del puerto serie y la nueva palabra no son coincidentes (valoes erroneos)
        Serial.println("Not valid value");
      }

    }else{
      // Lectura en el puerto serie de una palabra no valida
      Serial.println("Not valid value");
    }
  }
}
