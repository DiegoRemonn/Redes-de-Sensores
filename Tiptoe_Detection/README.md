# Tiptoe_Detection

Este directorio contiene los siguientes subdirectorios y archivos:

- **Get_Data**: Esta carpeta contiene scripts y archivos relacionados con la obtención de datos.
- **Tiptoe_detector**: Esta carpeta contiene scripts y archivos relacionados con la detección de puntillas.
- `Data_analysis.py`: Script en Python para el análisis de datos.
- `serial-data-collect-csv.py`: Script en Python para recopilar datos en bruto a través de una conexión serial y guardarlos en archivos CSV.

## Get_Data

### Descripción
Esta carpeta contiene un proyecto para obtener datos del acelerómetro y el giroscopio del sensor LSM9DS1 y enviarlos a través del puerto serie. El proyecto está diseñado para funcionar con placas Arduino compatibles con LSM9DS1.

## Tiptoe_detector

### Descripción
Esta carpeta contiene scripts y archivos relacionados con la detección de puntillas.

## Archivos
- `Data_analysis.py`: 
  - Descripción: Script en Python para el análisis de datos relacionado con la detección de puntillas. Incluye funciones para leer datos de archivos CSV, filtrar frecuencias altas, saturar datos, dibujar datos en un eje de tiempo, integrar una señal y analizar estados.
- `serial-data-collect-csv.py`: 
  - Descripción: Script en Python para recopilar datos en bruto a través de una conexión serial y guardarlos en archivos CSV. Incluye funcionalidad para abrir una conexión serial, recibir datos y escribirlos en archivos CSV.
