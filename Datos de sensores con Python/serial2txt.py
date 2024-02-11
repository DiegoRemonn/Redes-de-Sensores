import serial
import sys

def main(args):
    # Se inicia una instancia del puerto serie
    puerto = serial.Serial('COM5', 9600)
    
    try:
        with open('prueba.txt', 'w') as f:
            f.write('Archivo generado adecuadamente\n')
        
        with open('datos.txt', 'w') as f:
            f.write("x;y;z\n")
        
        i = 0
        while i < 100:
            if puerto.in_waiting > 0:
                # Convierto datos de entrada a cadena de texto y elimino espacios
                line = puerto.readline().decode('utf-8').rstrip()
                print(line)
                with open('datos.txt', 'a') as f:
                    f.write(line.replace(', ', ';') + '\n')
                i += 1
        print("Escritura finalizada con exito.")
        puerto.close()
    
    except KeyboardInterrupt:
        # Finalizar con comando Ctrl+C para cerrar adecuadamente el puerto serie
        puerto.close()
        print("Comunicacion finalizada.")

if __name__ == '__main__':
    main(sys.argv)