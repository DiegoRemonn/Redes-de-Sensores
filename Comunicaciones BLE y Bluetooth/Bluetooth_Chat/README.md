# Bluetooth_Chat

## Descripción
Este directorio contiene un proyecto que permite establecer un chat entre dos dispositivos utilizando Bluetooth clásico. El proyecto está diseñado para funcionar con placas basadas en ESP32 y utiliza el perfil de puerto serie (SPP) para la comunicación Bluetooth.

## Archivos
- `Bluetooth_Chat.ino`: Archivo principal del proyecto que contiene el código para establecer la comunicación Bluetooth y permitir el intercambio de mensajes entre dos dispositivos.
  
## Contenido de `Bluetooth_Chat.ino`
El archivo `Bluetooth_Chat.ino` configura la comunicación Bluetooth y establece un nombre de dispositivo. Permite enviar y recibir mensajes entre dispositivos a través de Bluetooth clásico.

### Funcionamiento del código
1. Se inicializa la comunicación serie para la depuración.
2. Se inicializa la comunicación Bluetooth y se define un nombre de dispositivo.
3. El dispositivo espera conexiones Bluetooth entrantes y muestra un mensaje en el puerto serie cuando está listo para ser emparejado.
4. Cuando se reciben datos por el puerto serie, se envían a través de Bluetooth.
5. Cuando se reciben datos por Bluetooth, se muestran por el puerto serie.

### Uso
1. Abre el archivo `Bluetooth_Chat.ino` en el IDE de Arduino.
2. Carga el código en tu placa basada en ESP32.
3. Empareja dos dispositivos a través de Bluetooth.
4. Los dispositivos podrán intercambiar mensajes a través del chat Bluetooth.

## Notas
- Este proyecto está diseñado para funcionar con placas basadas en ESP32 y utiliza el perfil de puerto serie (SPP) para la comunicación Bluetooth.
- Asegúrate de que la configuración de Bluetooth esté habilitada en tu entorno de desarrollo y que la biblioteca `BluetoothSerial.h` esté correctamente instalada.
