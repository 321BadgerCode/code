#date: 9/21/2022.
#description:
	#input: 4 #'s.
	#output: print #'s in 1 line w/ spaces between, print each # in new line, print sum of #'s.

#get input from usr..
num1:int=int(input("What is the first number? "))
num2:int=int(input("What is the second number? "))
num3:int=int(input("What is the third number? "))
num4:int=int(input("What is the fourth number? "))

#output what usr. inputted on same line.
print(num1,num2,num3,num4)

#output what usr. inputted on different lines.
print(num1)
print(num2)
print(num3)
print(num4)

#output sum(∑) of inputted #'s.
sum:int=num1+num2+num3+num4
print("The sum is",sum)
