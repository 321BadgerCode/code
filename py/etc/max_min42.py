#date: 10/4/2022.
#description:
	#input: 5 ints.
	#output: print largest, smallest, & mean of the group.
#get input.
num1:int=int(input("#: "))
num2:int=int(input("#: "))
num3:int=int(input("#: "))
num4:int=int(input("#: "))
num5:int=int(input("#: "))


#print largest.
large:int=0

if num1>num2:
        large=num1
elif num2>num3:
        large=num2
elif num3>num4:
        large=num3
elif num4>num5:
        large=num4
elif num5>num1:
        large=num5

print(large)

#print smallest.
small:int=0

if num1<num2:
        small=num1
elif num2<num3:
        small=num2
elif num3<num4:
        small=num3
elif num4<num5:
        small=num4
elif num5<num1:
        small=num5

print(small)

#print mean(∑/n).
mean:float=(num1+num2+num3+num4+num5)/5
print(mean)
