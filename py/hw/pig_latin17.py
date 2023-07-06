#date: 1/18/2023.
#description:
	#input:
                #-get choice of converting english to pig latin or vise-versa.
		#-get word.
	#output:
		#-translate word to pig latin or vise-versa.

##2 pts Get word function
##	Ask “What is your word?” (1 pt.)
##	Return answer (1 pt.)
def getWord():
	word=input("What is your word? ")
	return word

##5 pts English to Pig Latin function
##	Print title
##	Get front of word (1 pt.)
##	If front part of the word is a blend (‘ch’, ‘sh’, ‘th’, ‘wh’, ‘st’ or ‘str’) (3 pt.)
##		Then the blend is the front
##	Get the rest of the word (1 pt.)
##	Return rest of word then space then front with an ‘ay’
def engToPig(word):
	print("English to Pig Latin")
	ans=""
	blend=["ch","sh","th","wh","st","str"]
	front=word[:1]
	if word[:3]=="str":
		front=word[:3]
	else:
		for a in blend:
			if a==word[:2]:
				front=word[:2]
	ans=word[len(front):]+" "+front+"ay"
	return ans

##7 pts Pig Latin to English function (7 pt.)
##	Takes “yler tay” to “tyler”
##	Takes “at whay” to “what”
##	Takes “ing stay” to “sting”
##	Takes “ing stray” to “string”
##	Takes “og day” to “dog”
##	And others…
def pigToEng(word):
	print("Pig latin to English")
	ans=""
	blend=["ch","sh","th","wh","st","str"]
	space=word.find(" ")
	front=word[space+1:space+2]
	if word[space+1:space+4]=="str":
		front=word[space+1:space+4]
	else:
		for a in blend:
			if a==word[space+1:space+3]:
				front=word[space+1:space+3]
	ans=front+word[:space]
	return ans

menu_opt=-1
#11 pts while menu choice does not equal 3
while menu_opt!=3:
	#Print title (1 pt.)
	print("-----PIG LATIN TRANSLATOR-----")
	#Print menu (1 pt.)
	print("Press 1 for English to Pig Latin")
	print("Press 2 for Pig Latin to English")
	print("Press 3 to end!")
	word=""
	#Input menu choice (1 pt.)
	menu_opt=int(input("Choice: "))
	#If menu choice is 1 then (3 pt.)
		#Get word
		#Call English to Pig Latin function
	if menu_opt==1:
		word=getWord()
		print("")
		print(word+" >>>> "+engToPig(word))
		print("")
		print("")
	#If menu choice is 2 then (3 pt.)
		#Get word
		#Call Pig Latin to English function
	elif menu_opt==2:
		word=getWord()
		print("")
		print(word+" >>>> "+pigToEng(word))
		print("")
		print("")
	#If menu choice is 3 then (1 pt.)
		#Print “The End”
	elif menu_opt==3:
		print("The End!")
	#If menu choice is anything other than 1, 2 or 3 then (1 pt.)
		#Print error message
	else:
		print("invalid input, please choose again")
		print("")
		print("")






##11 pts while menu choice does not equal 3
##	Print title (1 pt.)
##	Print menu (1 pt.)
##	Input menu choice (1 pt.)
##	If menu choice is 1 then (3 pt.)
##		Get word
##		Call English to Pig Latin function
##	If menu choice is 2 then (3 pt.)
##		Get word
##		Call Pig Latin to English function
##	If menu choice is 3 then (1 pt.)
##		Print “The End”
##	If menu choice is anything other than 1, 2 or 3 then (1 pt.)
##		Print error message
##
##2 pts Get word function
##	Ask “What is your word?” (1 pt.)
##	Return answer (1 pt.)
##
##5 pts English to Pig Latin function
##	Print title
##	Get front of word (1 pt.)
##	If front part of the word is a blend (‘ch’, ‘sh’, ‘th’, ‘wh’, ‘st’ or ‘str’) (3 pt.)
##		Then the blend is the front
##	Get the rest of the word (1 pt.)
##	Return rest of word then space then front with an ‘ay’
##
##7 pts Pig Latin to English function (7 pt.)
##	Takes “yler tay” to “tyler”
##	Takes “at whay” to “what”
##	Takes “ing stay” to “sting”
##	Takes “ing stray” to “string”
##	Takes “og day” to “dog”
##	And others…
