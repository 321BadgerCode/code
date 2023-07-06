#date: 10/3/2022.
#description:
	#input: mom & dad age.
	#output: compare ages & print accordingly.
dad_age:int=46
mom_age:int=42

print("My dad is",dad_age)
print("My mom is",mom_age)
print('')

if dad_age>mom_age:
        print("My dad is older than my mom!")
elif dad_age<mom_age:
        print("My mom is older than my dad!")
else:
        print("My dad and mom are the same age!")
