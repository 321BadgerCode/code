#date: 11/14/2022
#description:
    #input:roll quantity.
    #output: 20 iterations of simulation of 2 dice rolls.
import random

#get input.
rolls=int(input("How many rolls? "))

print("roll\t\tdie 1\t\tdie 2")
print("----\t\t-----\t\t-----")

#output 20 iterations dice rolls.
for roll in range(1,rolls+1):
    print(roll,"\t\t",end="")

    #output 2 dice rolls.
    for a in range(1,3):
        die=random.randint(1,6)
        print(die,"\t\t",end="")

    print("")
#snake eyes
#ballerina
#brooklyn forest
#square pair
#puppy paws
#box cars
