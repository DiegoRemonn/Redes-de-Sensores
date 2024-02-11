import serial
import sys

def main(args):
    # Se inicia una instancia del puerto serie
    puerto = serial.Serial('COM5', 9600)
    
    try:
        while True:
            if puerto.in_waiting > 0:
                # Convierto datos de entrada a cadena de texto y elimino espacios
                line = puerto.readline().decode('utf-8').rstrip()
                print(line)
    
    except KeyboardInterrupt:
        # Finalizar con comando Ctrl+C para cerrar adecuadamente el puerto serie
        puerto.close()
        print("Comunicacion finalizada.")

if __name__ == '__main__':
    main(sys.argv)