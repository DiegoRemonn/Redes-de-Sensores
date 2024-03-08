'''
Script lectura de mensajes enviados a un servidor TCP mediante codigo python
Created by Diego Remón
https://github.com/DiegoRemonn/Redes-de-Sensores
'''

import socket

''' Configuración del server TCP '''
Server_IP = '0.0.0.0' # Use '0.0.0.0' to listen all available interfaces
Server_PORT = 4096

''' Inicialización del server TCP/IP '''
tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Enlaza el socket al la dirección IP y al puerto
server_address = (Server_IP, Server_PORT)
tcp_socket.bind(server_address)
 
# Escucha en el puerto
tcp_socket.listen(1)


# Espera a una nueva conexión
print("Waiting for connection")
while True:
    connection, client = tcp_socket.accept()
    
    try:
        print("Connected to client IP: {}".format(client))
        
        # Recibe y muestra un dato de 32 bytes en el momento en el que el cliente envía algo
        while True:
            data = connection.recv(32)
            if data:
                print("Received data: {}".format(data.decode('utf-8').rstrip()))
            
            if not data:
                break
    
    finally:
        connection.close()
