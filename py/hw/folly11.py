#date: 11/16/2022
#description:
	#input: money quantity.
	#output:
		#iterations of simulation of 2 dice rolls.
		#if sum==7: money+=4.
		#else: money-=1.
import random

#intro..
print("*** Welcome to Lucky Seven Dice Game! ***")
print("If the sum of the Dice is 7, you win $4. Otherwise, you lose $1.")
print("")

#get input.
money=int(input("How much money do you have?"))

print("")

#output iterations of dice rolls.
cont=True
roll=1
high_money=money
high_roll=0
while cont:
	print("--------------------------------")

	#output current roll.
	"""
	if roll<10:
		print("Roll# "+str(roll)+" ",end="")
	else:
		print("Roll# "+str(roll)+"\t",end="")
	"""
	print("Roll# "+str(roll)+" ",end="")

	#output 2 dice rolls.
	die1=random.randint(1,6)
	print("Die 1: "+str(die1)+"\t",end="")

	die2=random.randint(1,6)
	print("Die 2: "+str(die2))

	print("")

	#conditional logic for gain/lose money.
	if die1+die2==7:
		money+=4
	else:
		money-=1
	print("You have $"+str(money)+".")

	#high score.
	if money>high_money:
		high_money=money
		high_roll=roll

	#if broke.
	if money<=0:
		print("You are broke after "+str(roll)+" rolls.")
		print("You should have quit after "+str(high_roll)+" rolls when you had $ "+str(high_money)+".")
		cont=False
	else:
		print("")

	roll+=1
