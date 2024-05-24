# Get_Data

## Descripción
Este directorio contiene un proyecto para obtener datos del acelerómetro y el giroscopio del sensor LSM9DS1 y enviarlos a través del puerto serie. El proyecto está diseñado para funcionar con placas Arduino compatibles con LSM9DS1.

## Archivos
- `Get_Data.ino`: Archivo principal del proyecto que contiene el código para leer los datos del sensor LSM9DS1 y enviarlos a través del puerto serie.
  
## Contenido de `Get_Data.ino`
El archivo `Get_Data.ino` configura el sensor LSM9DS1 y envía los datos del acelerómetro y el giroscopio a través del puerto serie.

### Funcionamiento del código
1. Se configuran las constantes y variables necesarias, incluyendo el pin del LED, el retraso entre las recopilaciones de datos y las conversiones de unidades.
2. Se inicia la comunicación serie y se inicializa el sensor LSM9DS1.
3. En el bucle principal, se espera a que esté disponible algún comando por el puerto serie.
4. Cuando se recibe el comando 'k', se activa un flag para comenzar a enviar datos.
5. Se recopilan los datos del acelerómetro y el giroscopio y se envían a través del puerto serie en formato CSV.
6. Cuando se recibe el comando 'w', se detiene el envío de datos y se apaga el LED.

### Uso
1. Abre el archivo `Get_Data.ino` en el IDE de Arduino.
2. Carga el código en tu placa Arduino compatible con LSM9DS1.
3. Abre el monitor serie para ver los datos del sensor.
4. Envía el comando 'k' para comenzar la transmisión.
