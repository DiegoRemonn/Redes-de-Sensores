# WiFi_Json

## Descripción
Este directorio contiene un proyecto para crear un archivo JSON cada 10 segundos con datos de temperatura aleatorios. El proyecto está diseñado para funcionar en dispositivos compatibles con Arduino que puedan conectarse a una red WiFi.

## Archivos
- `WiFi_Json.ino`: Archivo principal del proyecto que contiene el código para generar y enviar datos en formato JSON a través del puerto serie.

## Contenido de `WiFi_Json.ino`
El archivo `WiFi_Json.ino` configura el dispositivo para generar un archivo JSON cada 10 segundos con datos de temperatura aleatorios. Utiliza la biblioteca `ArduinoJson` para construir y serializar el objeto JSON.

### Funcionamiento del código
1. Se inicializa la comunicación serie para la depuración.
2. Se inicializa la semilla para la generación de números aleatorios.
3. En cada iteración del bucle principal, se verifica si ha pasado un intervalo de 10 segundos.
4. Si ha pasado el intervalo de tiempo, se genera un objeto JSON con datos de temperatura aleatorios y se envía a través del puerto serie.

### Uso
1. Abre el archivo `WiFi_Json.ino` en el IDE de Arduino.
2. Carga el código en tu dispositivo compatible con Arduino.
3. Abre el monitor serie para visualizar los archivos JSON generados.

## Notas
- Este proyecto está diseñado para funcionar en dispositivos compatibles con Arduino que puedan conectarse a una red WiFi.
- Asegúrate de tener instalada la biblioteca `ArduinoJson` en tu entorno de desarrollo Arduino antes de compilar el código.
- El dispositivo generará un nuevo archivo JSON cada 10 segundos con datos de temperatura aleatorios.
