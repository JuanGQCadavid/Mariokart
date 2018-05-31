import socket

mi_sokect = socket.socket()
mi_sokect.connect(('localhost',8000))


mi_sokect.send(("Nigga, aint a server but a Client Dude").encode())
respuesta = mi_sokect.recv(1024).decode()

print(respuesta)

mi_sokect.close()
