import socket
import traceback
import sys
import RPi.GPIO as IO
from threading import Thread

mi_sokect = socket.socket( socket.AF_INET, socket.SOCK_DGRAM)
mi_sokect.bind(('192.168.1.100', 8000))
#mi_ sokect.listen(5)

arduino_ip = "192.168.1.103"
arduino_port = 2390


def main():
    print("Iniciando servidor")
    
    while True:
        data, addr = mi_sokect.recvfrom(1024)
        ip, port = str(addr[0]),str(addr[1])
        
        print('Accepting connection from ' + ip)
        try:
            Thread(target=client_thread, args=(data, addr)).start()
        except:
            print('Damn it, Terrible error!')
            traceback.print_exc()
    
   
def client_thread(data_code, addr):
    derecha = 'RIGHT'
    izquierda = 'LEFT'
    adelante = 'FW'
    pare = 'STOP'
    retroceda = 'BACK'
    data = data_code.decode() 

    if derecha in data:
        print("Derecha")
        mi_sokect.sendto(derecha.encode(), (arduino_ip,arduino_port))
    elif izquierda in data:
        print("izquierda")
        mi_sokect.sendto( izquierda.encode(), (arduino_ip,arduino_port))
    elif adelante in data:
        print("adelante")
        mi_sokect.sendto(adelante.encode(), (arduino_ip,arduino_port))
        
    elif pare in data:
        print("pare")
        mi_sokect.sendto(pare.encode(), (arduino_ip,arduino_port))
        
    elif retroceda in data:
        print("retroceda")
        mi_sokect.sendto(retroceda.encode(), (arduino_ip,arduino_port))
        
    else:
        print("What? ->  " + data)


        
    
main()
