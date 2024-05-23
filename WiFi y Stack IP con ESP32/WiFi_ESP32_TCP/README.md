# WiFi_ESP32_TCP

## Descripción
Este directorio contiene un proyecto para conectar un dispositivo ESP32 a una red WiFi y establecer una conexión TCP con un servidor. El dispositivo ESP32 enviará datos aleatorios al servidor a través de la conexión TCP.

## Archivos
- `WiFi_ESP32_TCP.ino`: Archivo principal del proyecto que contiene el código para conectar el ESP32 a la red WiFi y establecer la conexión TCP con el servidor.
- `TCPServerPython.py`: Script en Python que actúa como servidor TCP para recibir los datos enviados por el ESP32.

## Contenido de `WiFi_ESP32_TCP.ino`
El archivo `WiFi_ESP32_TCP.ino` configura la conexión a la red WiFi y establece una conexión TCP con un servidor remoto. El ESP32 enviará datos aleatorios al servidor a intervalos regulares.

### Funcionamiento del código del ESP32
1. Se inicializa la comunicación serie para la depuración.
2. Se establece la conexión a la red WiFi utilizando las credenciales proporcionadas.
3. Se inicializa un temporizador para generar interrupciones a intervalos regulares.
4. En cada interrupción del temporizador, se envían datos aleatorios al servidor a través de la conexión TCP.

### Uso
1. Abre el archivo `WiFi_ESP32_TCP.ino` en el IDE de Arduino.
2. Completa las credenciales de la red WiFi y la dirección IP del servidor.
3. Carga el código en tu dispositivo ESP32.
4. Ejecuta el script `TCPServerPython.py` en el servidor para iniciar el servidor TCP.
5. El ESP32 enviará datos aleatorios al servidor a través de la conexión TCP.

## Contenido de `TCPServerPython.py`
El archivo `TCPServerPython.py` contiene un script en Python que actúa como servidor TCP para recibir los datos enviados por el ESP32.

### Funcionamiento del script Python
1. Se importa el módulo `socket` para la comunicación TCP/IP.
2. Se configura la dirección IP y el puerto del servidor.
3. Se crea un socket TCP y se enlaza al servidor.
4. Se inicia la escucha del socket en el puerto especificado.
5. Cuando se establece una conexión con el ESP32, se muestra un mensaje y se espera a recibir datos.
6. Cuando se reciben datos del ESP32, se muestran por la consola del servidor.

### Uso
1. Abre el archivo `TCPServerPython.py` en un entorno de desarrollo Python como Spyder.
2. Ejecuta el script en el servidor.
3. El servidor estará listo para recibir datos del ESP32 a través de la conexión TCP.

## Notas
- Este proyecto requiere un dispositivo ESP32 compatible y una conexión a una red WiFi.
- Asegúrate de configurar correctamente las credenciales de la red WiFi y la dirección IP del servidor antes de cargar el código en el ESP32.
- El script Python debe ejecutarse en el servidor antes de que el ESP32 comience a enviar datos.
