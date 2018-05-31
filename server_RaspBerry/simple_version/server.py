import socket

mi_sokect = socket.socket()
mi_sokect.bind(('localhost', 8000))
mi_sokect.listen(5)

while True:
    conexion, addr = mi_sokect.accept()
    print("Nueva Conexion establecida!")
    print(addr)

    peticion = conexion.recv(1024).decode()
    print(peticion)

    conexion.send(("Whats App my nigga, from the server!").encode())
    conexion.close()
