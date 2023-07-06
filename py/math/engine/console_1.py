#badger
import os#system
import time#time
import pyttsx3#speech
import msvcrt#key presses
import ctypes#kernel/console/title,etc

def print(text):
	print(text)
def print_list(text):
	for a in range(len(text)):
		print(text[a])
def echo(text):
	print(text,flush=true)
def input(text):
	return input(text)
def pause():
	msvcrt.getch()
def continue():
	print("Press any key to continue...",end="",flush=True)
	msvcrt.getch()
	os.system('cls')
def wait(time):
	return time.sleep(time)
def clear():
	return os.system('cls')
def exit():
	return exit()
def title(text):
	ctypes.windll.kernel32.SetConsoleTitleW(text)