# TODO prendere la porta giusta
# ports = serial.tools.list_ports.comports()

# for port, desc, hwid in sorted(ports):
#     print("{}: {} [{}]".format(port, desc, hwid))
#

# TODO deve riportare grafico situazione acqua + smart lights on/off + alarm situation

# -*- coding: utf-8 -*-
"""
Created on Mon Nov 21 17:57:33 2022

@author: daniel
"""
import re
import serial
from tkinter import *
from matplotlib import pyplot as plt

Top = Tk()

ser = serial.Serial('COM5', baudrate=9600, timeout=1)

x = []
y = []
func_id = None


def read_data():
    global func_id
    plt.ion()
    new_value = str(ser.readline())
    if new_value == '':
        pass
    else:
        s = re.findall(r'\b\d+\b', new_value[2:][:-5])
        y.append(int(s[1]))
        x.append(int(s[0]))
        plt.plot(x, y, 'r-')
        plt.show()
        plt.pause(0.0001)
    func_id = Top.after(100, read_data)


def close_plot():
    global func_id
    # to no longer update the plot
    Top.after_cancel(func_id)
    plt.close()
    global x, y
    del x[:]
    del y[:]


def quit():
    Top.destroy()


def critic_mod():
    print("critic mod, bisogna mandare segnale ad arduiono")
    ser.write(slider.getint())


def slider_value():
    print("slider valore")
    ser.write(slider.getint())


Button(Top, text='Read', command=read_data).pack()
Button(Top, text='Close plot', command=close_plot).pack()
slider = Scale(Top, from_=0, to=100)
slider.pack()
slider.on_changed(slider_value)
Button(Top, text='critic mod', command=close_plot).pack()
Button(Top, text='Quit', command=quit).pack()

mainloop()
