import re
import serial
import numpy as np
import matplotlib.pyplot as plot

ser = serial.Serial("COM7", 9600)
plot.ion()

x = []
y = []

ser.close()
ser.open()
while True:
    new_value = str(ser.readline().decode())
    new_value = new_value[:-2]
    print(new_value)
    if new_value == "":
        pass
    else:
        print(new_value)
        s = new_value.split(" ")
        if len(s) > 1:
            y.append(float(s[1]))
            x.append(float(s[0]))
            plot.plot(x, y, "r-")
            m = float(s[0])
            plot.axis([0, m, 0, 60])
            plot.show()
            plot.pause(1)
