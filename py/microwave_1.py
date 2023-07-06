#badger
from os import system#pause
from ctypes import windll#title

class time:
	second:int=0
	minute:int=0
	text:str=""
	def __init__(self,second:int=0,text:str=""):
		self.second=second
		self.minute=self.get_minute()
		self.second-=self.get_second()
		self.text=text
	def get_second(self):
		b1:int=self.minute*60
		return b1
	def get_minute(self):
		b1:int=round(self.second/60)
		return b1
	def to_string(self):
		b1:str=str(self.minute)+" : "+str(self.second)
		return b1
	def to_int(self):
		b1:str=self.text.replace(" ","").split(":")
		self.minute=int(b1[0])
		self.second=int(b1[1])
		b2:int=self.second+self.get_second()
		return b2

def convert_wattage_time(user_wattage:int,wattage:int,second:int):
	time:int=(wattage/user_wattage)*second
	return time

def pause():
	system("pause")

def title(text):
	windll.kernel32.SetConsoleTitleW(text)

if __name__=="__main__":
	title("MICROWAVED!")

	user_wattage:str=input("Your wattage: ")
	wattage:str=input("Wattage(on food package): ")
	second:str=input("Time recommended to cook food(on food package): ")
	print(           "____________________________________________________")

	time1=time(0,second)

	new_second:int=convert_wattage_time(int(user_wattage),int(wattage),time1.to_int())
	new_time=time(new_second,"")

	print("Time to cook food: "+new_time.to_string())
	print("Minutes to cook food: "+str(new_time.minute))
	print("Seconds to cook food: "+str(new_time.second))
	print("Total seconds to cook food: "+str(new_time.second+new_time.get_second()))

	pause()