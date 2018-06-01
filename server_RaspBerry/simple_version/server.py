import socket

mi_sokect = socket.socket( socket.AF_INET, socket.SOCK_DGRAM)
mi_sokect.bind(('192.168.1.101', 8000))
#mi_sokect.listen(5)

while True:
    data, addr = mi_sokect.recvfrom(1024)
    print("Nueva Conexion establecida!")
    print(addr)
    print(data)

    #conexion.send(("Whats App my nigga, from the server!").encode())
    #conexion.close()
