import socket

mi_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
dir_server = '192.168.1.101'
port_server = 8000
mensaje = "Nigga, aint a server but a Client Dude"
mi_socket.sendto(mensaje.encode("utf8"),
                 (dir_server, port_server))

#respuesta = mi_sokect.recv(1024).decode()

#print(respuesta)
