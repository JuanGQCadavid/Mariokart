import socket
import traceback
import sys
import RPi.GPIO as IO
from threading import Thread


## Datos

IO.setmode(IO.BOARD)

pin_1, pin_2, pin_3, pin_4 = 29, 31, 33, 35
dir_1, dir_2 = 11, 13

#Pines de salida al RF
IO.setup(pin_1 , IO.OUT)
IO.setup(pin_2 , IO.OUT)
IO.setup(pin_3 , IO.OUT)
IO.setup(pin_4 , IO.OUT)

#Pines de salida Direccioanmento

IO.setup(dir_1 , IO.OUT)
IO.setup(dir_2 , IO.OUT)



mi_sokect = socket.socket( socket.AF_INET, socket.SOCK_DGRAM)
mi_sokect.bind(('192.168.1.100', 8000))
#mi_ sokect.listen(5)


def main():
    print("Iniciando servidor")

    print("Preparando Carro")
    set_up()
    print("Done..")

    while True:
        IO.output(pin_1,True)
        IO.output(pin_2,False)
        IO.output(pin_3,True)
        IO.output(pin_4,False)


def set_up():
    #Pines salida
    IO.output(pin_1,False)
    IO.output(pin_2,False)
    IO.output(pin_3,False)
    IO.output(pin_4,False)

    #Dir bus
    IO.output(dir_1,False)
    IO.output(dir_2,False)


    
main()
