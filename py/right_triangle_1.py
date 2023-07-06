#badger
import msvcrt#key
import ctypes#kernel,console,title

class my:
	def input(a1):
		b1=0
		try:
			b1=int(input(a1))
		except:
			b1=0
		return b1
	def style(a1,a2):
		b1=""
		for a in range(len(a1)):
			b1+=a2
		return a1+"\n"+b1
	def solve(a1):
		b1=0
		if a1==a:
			b1=c**2-b**2
		elif a1==b:
			b1=c**2-a**2
		elif a1==c:
			b1=a**2+b**2
		b1=sqrt(b1)
		return b1
	def pause():
		msvcrt.getch()
	def title(a1):
		ctypes.windll.kernel32.SetConsoleTitleW(a1)

my.title("PYTHAGOREAN'S THEOREM!")
print("Pythagorean's Theorem:")
print("______________________")
print("Definition(Glossary):")
print("_____________________")
print("Legs=variables/sides that are conncected to the right angle(90°)")
print("Hypotenuse=variable/side that is on the opposite side from the right triangle(right triangle is 'shooting' at this side)")
print("_____________________")
print(my.style("Extra/bonus:","_"))
print("Type 'joke' for the first input to see a funny joke")
print("Type 'x' for the variable that is supposed to be solved for/found(value that is not known/null)")

a=my.input("Leg 1: ")
b=my.input("Leg 2: ")
c=my.input("Hypotenuse: ")
area=(a*b)/2
x=0
if str(a)=="joke":
	print("'Hypotenuse'; more like 'I wish I was high on pot...nuse'. This was in a Key and Peele sketch. Lol :)")
else if str(a)=="x":
        my.solve(a)
else if str(b)=="x":
        my.solve(b)
else if str(c)=="x":
        my.solve(c)
print(str(a2))
my.pause()
#solve function, height of triangle, solve each variable