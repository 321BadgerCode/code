#date: 4/26/2023.
#description:
	#input:
		#-r:rock,p:paper,s:scissors.
	#output:
		#-who won best out of 5 rounds.
import random

def split(txt,delimiters=[' ','\t','\n',',']):
	result=[]
	word=''

	for c in txt:
		if c not in delimiters:
			word+=c
		elif word:
			result.append(word)
			word=''

	if word:
		result.append(word)

	return result

def get_capitalize(txt):
	ans=''
	words=split(txt,[' '])

	for a in range(len(words)):
		ans+=words[a][0].upper()+words[a][1:].lower()
		if a<=len(words)-2:
			ans+=' '

	return ans

actions=["r","p","s"]
actions2=["rock","paper","scissors"]

name=get_capitalize(input("Please enter your name: "))
print(f"\n\nWelcome to Rock, Paper, Scissors ( {name} vs. Computer)---")

wins=0
losses=0

cont=True
game=1
rounds=5
while cont:
	print(f"\n\n_________________Game {game} __________________")
	action=input("Please choose Rock(R), Paper(P), or Scissors(S):").lower()

	while not action in actions:
		print("\n\nInvalid Choice, Please choose Rock(R), Paper(P), or Scissors(S):")
		action=input("Please choose Rock(R), Paper(P), or Scissors(S):").lower()

	action_comp=random.randint(0,2)
	print(f"{name} chose {get_capitalize(actions2[actions.index(action)])}.")
	print(F"Computer chose {get_capitalize(actions2[action_comp])}")

	if action==actions[action_comp-1]:
		print("Computer wins!")
		losses+=1
		game+=1
	elif action==actions[action_comp]:
		print("Tie")
	else:
		print(f"{name} wins!")
		wins+=1
		game+=1

	print("")

	if rounds-wins<=rounds//2:
		print("===End of Game===")
		print(f"{name} wins")
		cont=False
	elif rounds-losses<=rounds//2:
		print("===End of Game===")
		print("Computer wins")
		cont=False

print(f"{name} {wins}")
print(f"Computer {losses}")