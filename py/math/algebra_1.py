#badger
from string import ascii_lowercase,digits

class math1:
	var=ascii_lowercase
	number=digits
	equal="="
	operator1=["+","*"]
	operator2=["-","/"]
	operator=equal+operator1+operator2

#def simplify():

def solve(equation:str):
        a1=algebra(equation)
        expression=a1[0]
        var=a1[1]
        equal=equation.find(math1.equal)
        for a in range(len(var)):
                if var[a]<equal:
                        if var[a] in expression[1]:
                                

def algebra(equation:str):
	var:str=[""]*len(equation)
	operator:str=[""]*len(equation)
	number:str=[""]*len(equation)
	expression:str=equation.split(math1.equal)
	for a in range(len(equation)):
		for b in range(len(math1.var)):
			if equation[a]==math1.var[b]:
				var[a]=math1.var[b]
		for b in range(len(math1.operator)):
			if equation[a]==math1.operator[b]:
				operator[a]=math1.operator[b]
		for b in range(len(math1.number)):
			if equation[a]==math1.number[b]:
				number[a]=math1.number[b]
	return [expression,var,operator,number]

if __name__=="__main__":
        print(algebra("a+b=b+5"))
#add simplify function to simplify each section(seperated by "=") of the equation
#make object oriented
#fix
#https://stackoverflow.com/questions/10499941/how-can-i-solve-equations-in-python