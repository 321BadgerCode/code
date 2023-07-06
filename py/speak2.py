#badger
import pyttsx3
from time import sleep

def say(A1):
	b1=pyttsx3.init()
	print(A1)
	b1.say(A1)
	b1.runAndWait()
def ask(A1):
	b1=pyttsx3.init()
	b1.say(A1)
	b1.runAndWait()
	b2=input(A1)
	return b2
say("Howdy there :D")
i1=ask("What would you like the speech synthesize robot thing to say? ")
say(i1)
sleep(1)