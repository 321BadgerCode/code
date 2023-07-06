#badger
import os
import time
import keyboard

def wait(sec:float=1)->None:
	time.sleep(sec)

def type(txt:str)->None:
	b1:str=""

	for a in range(len(txt)-1):
		b1+=txt[a]+','

	b1+=txt[-1]

	keyboard.send(b1)

discord_open_time:float=5

if __name__=="__main__":
	#get I.P. addr.
	ip:str=os.system("ipconfig")

	#copy I.P. 2 clip-board
	print(ip)
	wait()
	keyboard.send("CTRL+a")#select all
	wait()
	keyboard.send("CTRL+c")#copy
	wait()
	keyboard.send("ALT+SPACE+n")#minimize app.
	wait()

	#open Discord
	keyboard.send("CTRL+ESC")#win. start menu
	wait()
	type("discord")
	wait()
	keyboard.send("ENTER")
	wait(discord_open_time)

	#paste I.P. 2 Discord
	keyboard.send("CTRL+v")#paste
	wait()
	keyboard.send("ENTER")

	#close Discord
	keyboard.send("ALT+F4")#close app.