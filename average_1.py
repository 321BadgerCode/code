#badger
from os import system#pause
from ctypes import windll#title

def pause():
	system("pause")

def set_title(text):
	windll.kernel32.SetConsoleTitleW(text)

def get_average(a1:int=[0]):
	b1:int=0

	for a in range(len(a1)):
		b1+=a1[a]

	b1/=len(a1)

	return b1

def get_average_2(a1:int=[0]):
	return sum(a1)/len(a1)

if __name__=="__main__":
	set_title("AVERAGE TEST!")

	print(str(get_average([5,100])))
	print(str(get_average_2([5,100])))
        
	pause()