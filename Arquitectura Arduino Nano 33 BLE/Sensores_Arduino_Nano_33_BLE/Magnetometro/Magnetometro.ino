// Lectura y uso del magnetometro del Arduino Nano 33 BLE
// Created by Diego Remon
// https://github.com/DiegoRemonn/Redes-de-Sensores

#include <Arduino.h>
#include "BBTimer.hpp"
#include <Arduino_LSM9DS1.h>

// Designacion de un timer de la clase BBTimer para su uso
BBTimer my_t3(BB_TIMER3);

// Inicializacion de Variables y pines del dispositivo
float x, y, z, ledvalue;
int cont = 0;
float medidas[10][3]; // Matriz con los 10 valores medidos de x, de y, de z
bool send = false;
char buffer[15];

// Funcion de devolucion de llamada del timer
void t3Callback()
{
  send = true; // Semaforo/Flag lectura ADC
  cont = (cont+1)%10; // Incremento del 0 a 9
}

void setup() {
  // put your setup code here, to run once:
  // Inicializacion del puerto serie
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Started"); // Mensaje de inicio del puerto serie

  // Inicializacion del sensor IMU (Inertial Measurement Unit)
  // Comprobacion de un arranque correcto
  if(!IMU.begin()){
    Serial.println("Error al inicializar el IMU!");
    while(1);
  }

  // Muestra por puerto serie el ratio de muestras del magnetometro en Hz y otros mensajes utiles
  Serial.print("Ratio de muestras del campo magnetico = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");

  // Inicializacion y arranque del timer con una periodicidad de 0.1 segundos
  my_t3.setupTimer(100000, t3Callback);
  my_t3.timerStart();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Comprobacion que el contador sea mayor o igual a 0 y menor que 10 y que haya llamada al timer
  // Se debe medir cada 100 ms y mostrar una vez pasado 1 segundo (10 veces 100 ms)
  if (cont>=0 and cont<10 and send == true){
    // Comprobacion que el magnetometro esta disponible
    if(IMU.magneticFieldAvailable()){
      // Lectura del sensor magnetico en x, y, z
      IMU.readMagneticField(x, y, z);
    }
    // Almacenamiento de las lecturas en una matriz, primer valor x, segundo y, tercero z
    // Diez filas cont y 3 columnas para x, y, z
    medidas[cont][0] = x; // Nueve valores de x
    medidas[cont][1] = y; // Nueve valores de y
    medidas[cont][2] = z; // Nueve valores de z
    
    // Comprobacion que ya se ha terminado el segundo (10 veces recorrido el timer)
    if(cont == 9){
      // Recorrido de la matriz, se anida sobre las muestras los ejes a leer
      for(int muestra = 0; muestra < 10; muestra++){
        for(int axis = 0; axis < 3; axis++){
          // Guarda en un float el valor leido en cada posicion de la matriz medidas
          float resultados = medidas[muestra][axis];
          // Ejemplo de conversion de la variable float a string
          dtostrf(resultados, 10, 2, buffer);
          // Muestra por puerto serie los valores obtenidos en resultados y los separa por comas
          Serial.print(resultados);
          Serial.print(",");
        }
      }
      // Fin de linea por cada 1 segundo de medidas
      Serial.println();
    }
    // Indicacion final de fin de uso del timer
    send = false;
  }
  /*
  // Comprobacion que el magnetometro esta disponible
  if(IMU.magneticFieldAvailable()){
    // Lectura del sensor magnetico en x, y, z
    IMU.readMagneticField(x, y, z);
  }
  
  // Comprobacion que el campo magnetico en x es negativo
  if(x < 0){
    // Campo magnetico en x negativo, asigno el valor del sensor con signo positivo al led
    ledvalue = -(x);
  }else{
    // Campo magnetico en x positivo, asigno el valor del sensor con signo positivo al led
    ledvalue = x;
  }
  
  // Asigno al LED del Arduino el valor del magnetometro en x
  analogWrite(LED_BUILTIN, ledvalue);
  // Muestra por puerto serie los valores de x, y, z obtenidos del magnetometro
  Serial.print(x);
  Serial.print(',');
  Serial.print(y);
  Serial.print(',');
  Serial.println(z);

  // Espera 0.5 segundos
  delay(500);
  */
}

// Funcion que permite convertir un valor float en un string
// Parametros: valor a leer, longitud del string, numero de decimales y puntero string de salida
char *dtostrf(double val, signed char width, unsigned char prec, char *sout){
  // Inicializacion de un buffer de caracteres de tamaño 20 para guardar la cadena
  char fmt[20];
  // Creacion del formato de la cadena con width y prec con formato w.pf
  // w (width) el ancho de la cadena y con p (prec) el numero de decimales
  sprintf(fmt, "%%%d.%df", width, prec);
  // Creacion de la cadena final con el formato anterior "fmt" en la variable "sout" a partir del valor de "val"
  sprintf(sout, fmt, val);
}
