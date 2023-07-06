#badger
from os import system
from colorama import Fore,Style,init

def list(text_array):#['glove','wrench','fruit','apple','paper']
	b1=""
	for a in range(len(text_array)):
		if a<len(text_array)-1:
			b1+=text_array[a]+", "
		else:
			b1+=text_array[a]
	return b1

def abbreviate(text):#'U.S.A.',...
        b1=""
        for a in range(len(text)):
                b+=text[a].upper()+"."
        return b1

def shorten(text):#'ft.','cm.',...
        b1=text+"."
        return b1

class color:
        red=Fore.RED
        #orange=Fore.ORANGE
        yellow=Fore.YELLOW
        green=Fore.GREEN
        blue=Fore.BLUE
        #indigo=Fore.INDIGO
        #violet=Fore.VIOLET
        end=Style.RESET_ALL

class text(str):
	def __init__(self,text:str):
		super()
		self._text=str(text)
	def __capitalize(self,char):
		sentence=self._text.split(char+" ")
		lower_case=[""]*len(sentence)
		upper_case=[""]*len(sentence)
		b1=""
		for a in range(len(sentence)):
			upper_case[a]=sentence[a][0].upper()
			lower_case[a]=sentence[a][1:len(sentence[a])].lower()
			if a<len(sentence)-1:
				b1+=upper_case[a]+lower_case[a]+char+" "
			else:
				b1+=upper_case[a]+lower_case[a]
		return b1
	def capitalize(self):
		punctuation_mark=[".","!","?"]
		b1=""
		for a in range(len(punctuation_mark)):
			b1=self.__capitalize(punctuation_mark[a])
		return b1
	def __for_do(self,char):
		b1=""
		for a in range(len(self._text)):
			b1+=char
		return b1
	def for_do(self,char):
		b1=self.__for_do(char)
		return self._text+"\n"+b1
	def under_line(self):
		b1=self.for_do("_")
		return b1
	def print(self,color1):
		print(f"{color1}"+self._text+f"{color.end}")

if __name__=="__main__":
	init(convert=True)
#fix capitalization function
#try, except