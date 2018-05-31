import socket
import sys
from threading import Thread
import traceback
## Datos

carros = {}
usuarios = {}
carros_usuarios = {}


def crear_carros(id_carro):
    if carros.has_key(id_carro):
        carros[id_carro] = [0];
    else:
        print("Carro ya en existencia")
    passOA
        
def registrar_usuarios(ip_usuario, nombre = None):
    if usuarios.has_key(ip_usuario):
        carros[id_carro] = [nombre, 0, 0];
        return 0
    else:
        print("usuario ya en existencia")
        return 1

def setup_carros():
    crear_carros([0,1]);
    crear_carros([1,0]);


def client_thread(conn, ip, port, MAX_BUFFER_SIZE = 4096):
    # The input is in Bytes, so decode it
    input_from_client_bytes = conn.recv(MAX_BUFFER_SIZE)

    # MAX_BUFFER_SIZE is how big the message can be

    input_from_client = input_from_client_bytes.decode("utf8").rstrip()


    if input_from_client == "--VERD--" :
        mandarDisponibles(conn,MAX_BUFFER_SIZE);
        conn.close()
        print('Connection ' + ip + ':' + port +  ' ended')

    else:
        #Damn it;

        
    
    
    pass

def mandar_disponibles():
    for 

def start_server():
    soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # this is for easy starting/killing the app
    soc.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    print('Socket created')

    try:
        soc.bind(("127.0.0.1", 12345))
        print('Socket bind complete')

    except socket.error as msg:
        print('Bind failed. Error : ' + str(sys.exc_info()))
        sys.exit()

    #Start listening on socket

    soc.listen(10)
    print('Socket now listening')

    # We are going to use Threading for handle
    # differente conections at once

    # This will make an infinite loop neede for
    # not reseting server for every client

    while True:
        conn, addr = soc.accept()
        ip, portt = str(addr[0]), str(addr[1])

        print('Accepting connection from ' + ip + ":" + port)
        try:
            Thread(target=client_thread, arg=(conn, ip, port)).start()
        except:
            print('Damn it, Terrible error!')
            traceback.print_exc()


    soc.close()

        
    
def main():
    setup_carros()
    start_server() 
    
