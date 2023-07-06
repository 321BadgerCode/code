#date: 10/4/2022.
#description:
	#input: 5 ints.
	#output: print largest, smallest, & mean of the inputted #'s.
#get input from usr..
num1=int(input("Please enter in first number: "))
num2=int(input("Please enter in second number: "))
num3=int(input("Please enter in third number: "))
num4=int(input("Please enter in fourth number: "))
num5=int(input("Please enter in fifth number: "))

#print('')

#print largest.
large=num1

if large<num2:
        large=num2
if large<num3:
        large=num3
if large<num4:
        large=num4
if large<num5:
        large=num5

print("The largest number is:",large)

#print smallest.
small=num1

if small>num2:
        small=num2
if small>num3:
        small=num3
if small>num4:
        small=num4
if small>num5:
        small=num5

print("The smallest number is:",small)

#print mean(∑/n; n=len.(5)).
mean=(num1+num2+num3+num4+num5)/5

print("The mean of the 5 numbers is:",mean)
