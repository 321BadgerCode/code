#badger
from os import system#pause
from ctypes import windll#title
from random import uniform#random

def pause():
	system("pause")

def set_title(text):
	windll.kernel32.SetConsoleTitleW(text)

def estimate_pi(a1:int)->complex:
	pt:int=0
	pt_total:int=0

	for a in range(a1):
		x:int=uniform(0,1)
		y:int=uniform(0,1)
		distance:int=x**2+y**2
		if distance<=1:
			pt+=1
		pt_total+=1

	return 4*(pt/pt_total)

if __name__=="__main__":
	set_title("FIND_PI_1!")

	pi:complex=estimate_pi(1000)
	print(str(pi))

	pause()