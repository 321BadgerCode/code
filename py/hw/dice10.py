#date: 11/14/2022
#description:
	#input: roll quantity.
	#output: iterations of simulation of 2 dice rolls.
import random

#get input.
rolls=int(input("How many times would you like to roll 2 dice? "))
while rolls<=0:
        print("Rolls must be more than 0.")
        rolls=int(input("How many times would you like to roll 2 dice? "))

print("Count\tDie1\tDie2\tName")
print("-----\t----\t----\t----")

#output iterations of dice rolls.
n1=0
n2=0
n3=0
n4=0
n5=0
n6=0
for roll in range(1,rolls+1):
        #output current roll.
	print(roll,"\t",end="")

	#output 2 dice rolls.
	die1=random.randint(1,6)
	print(die1,"\t",end="")

	die2=random.randint(1,6)
	print(die2,"\t",end="")

	#pair logic conditions.
	name=""
	if die1==die2:
		if die1==1:
			name="Snake Eyes"
			n1+=1
		elif die1==2:
			name="Ballerina"
			n2+=1
		elif die1==3:
			name="Brooklyn Forest"
			n3+=1
		elif die1==4:
			name="Square Pair"
			n4+=1
		elif die1==5:
			name="Puppy Paws"
			n5+=1
		elif die1==6:
			name="Box Cars"
			n6+=1
	print(name)

#total=n1+n2+n3+n4+n5+n6
print("\nAfter 10 rolls, there are :")
print(str(n1)+" pairs of ones. That is "+str((n1/rolls)*100)+"%")
print(str(n2)+" pairs of twos. That is "+str((n2/rolls)*100)+"%")
print(str(n3)+" pairs of threes. That is "+str((n3/rolls)*100)+"%")
print(str(n4)+" pairs of fours. That is "+str((n4/rolls)*100)+"%")
print(str(n5)+" pairs of fives. That is "+str((n5/rolls)*100)+"%")
print(str(n6)+" pairs of sixes. That is "+str((n6/rolls)*100)+"%")

"""
pair+="1"
a1=0
for a in range(1,6):
	for b in range(0,len(pair))
		if pair[b]==str(a):
			a1+=1
	print(str(a1)+" pairs of ones. That is "+str())
"""
