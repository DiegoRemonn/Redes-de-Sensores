# Datos de sensores con Python

Este directorio contiene un proyecto arduino para la comunicación con puerto serie y scripts Python relacionados con la comunicación serie entre un dispositivo Arduino y una computadora, así como el procesamiento y visualización de los datos recibidos.

## Contenido

- `ComunicacionTermite`: Carpeta que contiene un proyecto de Arduino para la comunicación serie utilizando el software Termite. Esta carpeta incluye un archivo de código Arduino (`ComunicacionTermite.ino`) y la biblioteca externa `BBTimer.hpp` necesaria para su funcionamiento.

- `serialPython.py`: Script Python que permite la lectura de datos del puerto serie y su visualización en la consola. Este script ha sido desarrollado con Spyder y Anaconda.

- `serial2txt.py`: Script Python que lee los datos del puerto serie y los guarda en un archivo de texto `.txt`. Además, genera un archivo CSV con los datos del sensor en formato adecuado para su posterior análisis.

- `plotSerial.py`: Script Python que lee los datos del puerto serie y genera un gráfico en tiempo real con el promedio y la desviación estándar de los datos recibidos cada 5 segundos. Este script utiliza las bibliotecas `numpy`, `matplotlib`, y `serial` para el procesamiento de datos y la visualización del gráfico.

## Descripción de los Códigos

- `ComunicacionTermite`: Esta carpeta contiene el código de Arduino necesario para establecer una comunicación serie con la computadora a través del software Termite. El código configura el puerto serie y envía datos del sensor a la computadora para su visualización.

- `serialPython.py`: Este script Python se encarga de leer los datos del puerto serie utilizando la biblioteca `serial` y mostrarlos en la consola de manera continua. Proporciona una forma sencilla de visualizar los datos recibidos en tiempo real.

- `serial2txt.py`: Este script Python lee los datos del puerto serie y los guarda en un archivo de texto `.txt`. Además, formatea los datos en un archivo CSV para su posterior análisis y procesamiento.

- `plotSerial.py`: Este script Python utiliza las bibliotecas `numpy`, `matplotlib` y `serial` para generar un gráfico en tiempo real con el promedio y la desviación estándar de los datos recibidos del puerto serie cada 5 segundos. Proporciona una visualización útil para el análisis de datos en tiempo real.

## Uso

1. Descarga o clona este repositorio en tu máquina local.
2. Configura y ejecuta los proyectos de Arduino según sea necesario para establecer la comunicación serie.
3. Ejecuta los scripts Python utilizando Spyder y Anaconda para procesar y visualizar los datos del puerto serie según tus necesidades.

## Notas

- Asegúrate de tener correctamente configurados los puertos serie en los scripts de Python y en el código Arduino para establecer una comunicación efectiva.
- Es necesario tener instaladas las bibliotecas y dependencias mencionadas en cada proyecto o script de Python para garantizar su correcto funcionamiento.
- Se recomienda tener familiaridad con el IDE de Arduino, Python y los conceptos básicos de la comunicación serie para trabajar con estos proyectos y scripts de manera efectiva.
