from tkinter import *
from tkinter import ttk

root=Tk()

frm=ttk.Frame(root,padding=10)
frm.grid()

ttk.Label(frm,text="program: encrypt data.").grid(row=0,column=0)

def get_encrypt(msg:str,key:int=5)->str:
        b1:str=''

        for a in range(len(msg)):
                b1+=chr(ord(msg[a])^key)

        return b1

def set_msg(msg:str)->None:
        ttk.Label(frm,text=get_encrypt(msg)).grid(row=1,column=3)

i1=Entry(frm)

b1=Button(frm,text="encrypt",command=set_msg("test"),fg="grey",bg="black").grid(row=0,column=2)

root.mainloop()
