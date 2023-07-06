#date: 9/23/2022.
#description:
	#input: 2 #'s.
	#output: print 5 operations between the #'s(+,-,*,/,%).

#get input from usr..
num1:int=int(input("What is the first number? "))
num2:int=int(input("What is the second number? "))

print("")

#print output of operations between #'s.
out:float=0

out=num1+num2
print(num1,"+",num2,"=",out)

out=num1-num2
print(num1,"-",num2,"=",out)

out=num1*num2
print(num1,"x",num2,"=",out)

out=num1/num2
print(num1,"\u00F7",num2,"=",out)#÷(from win+.)

out=num1%num2
print(num1,"mod",num2,"=",out)
