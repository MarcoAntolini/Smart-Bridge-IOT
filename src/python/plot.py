import re
import serial
from tkinter import *
from matplotlib import pyplot as plt

Top = Tk()

# ser = serial.Serial('COM3', baudrate=9600, timeout=1)

x = []
y = []
func_id = None


def read_data():
    global func_id
    plt.ion()
    new_value = str(serial.readline().decode())
    new_value = new_value[:-2]
    if new_value == "":
        pass
    else:
        print(new_value)
        s = new_value.split(" ")
        print(s)
        if len(s) > 1:
            y.append(float(s[1]))
            x.append(float(s[0]))
            z = "LightSystem: " + s[2]
            text1.set(z)
            c = "State: " + s[3]
            text2.set(c)
            plt.plot(x, y, "r-")
            plt.show()
            plt.pause(0.0001)
    func_id = Top.after(100, read_data)


def close_plot():
    global func_id
    Top.after_cancel(func_id)
    plt.close()
    global x, y
    del x[:]
    del y[:]


def quit():
    Top.destroy()


Button(Top, text="Read", command=read_data).pack()
Button(Top, text="Close plot", command=close_plot).pack()
text1 = StringVar()
label1 = Label(Top, textvariable=text1)
label1.pack()
text2 = StringVar()
label2 = Label(Top, textvariable=text2)
label2.pack()
Button(Top, text="Quit", command=quit).pack()

mainloop()
