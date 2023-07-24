#badger
import turtle

class vector:
	x:int=0
	y:int=0
	z:int=0

	def __init__(self,x2:int=0,y2:int=0,z2:int=0)->None:
		self.x=x2
		self.y=y2
		self.z=z2
class entity(turtle.Turtle):
	def __init__(self,spiral:str="square",color:str="white",size:vector=vector(2,2))->None:
		turtle.Turtle.__init__(self)
		self.shape(spiral)
		self.color(color)
		self.shapesize(size.x,size.y)
		self.penup()
		self.speed(0)

def get_size(a1:list,a2:int):
	return reduce(lambda x,y:x+y,[[el]*a2 for el in a1])

if __name__=="__main__":
	#set-up window
	win=turtle.Screen()
	win.title("SPIRAL!")
	win.bgcolor("black")
	win.setup(500,500)
	win.tracer(0)

	#set-up spiral
	spiral=entity()
	spiral.hideturtle()
	spiral.pendown()
	spiral.pensize(3)

	#make spiral
	#chaos
	"""for a in range(1000):
		spiral.forward(1+a)
		spiral.left(1+a)"""
	#spike wheel
	"""for a in range(100):
		spiral.forward(1+a)
		spiral.left(1+a)"""
	#sphere blow-up
	for a in range(100):
		spiral.forward(2*a)
		spiral.left(2*a)
	#spiral
	"""b1:float=0
	for a in range(1000):
		spiral.forward(b1)
		b1+=.01
		spiral.left(5)"""
	#spiral2
	"""b1:float=0
	for a in range(1000):
		spiral.pensize(2+b1)
		spiral.forward(b1)
		b1+=.01
		spiral.right(3)"""
	#...
	"""b1:float=0
	for a in range(100):
		spiral.forward(b1)
		b1+=a*a
		spiral.left(a*a)"""
	#...2
	"""b1:float=0
	for a in range(100):
		spiral.forward(b1)
		b1+=a*a
		spiral.left(5*a)"""
	#...3
	"""k:float=1
	x:list=[2]*101
	for a in range(10):
		x[a+1]=k*x[a]*(1-x[a])
		print(x[a])

		#spiral.forward(x[a])
		#spiral.left(10)"""

	#loop 2 update screen 4 changes
	while True:
		win.update()