#badger
import sys
import atexit
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
	def __init__(self,shape:str="square",color:str="white",size:vector=vector(1,1))->None:
		turtle.Turtle.__init__(self)
		self.shape(shape)
		self.color(color)
		self.shapesize(size.x,size.y)
		self.penup()
		self.speed(0)

def get_sum_angle(side:int)->int:
	return (side-2)*180
def get_angle(side:int)->int:
	return get_sum_angle(side)/side
def get_side(sum_angle:int)->int:
	return (sum_angle/180)+2
def exit_event()->None:
	print("app. has been exited.")
def help()->None:
	print("usage: shape")
	print("syntax: shape [# of sides] [perimeter/size] [side width]")

if __name__=="__main__":
	#detect exit
	atexit.register(exit_event)

	#help
	print("type \"shape -h\" 4 help.")
	print("")

	#get side input
	side:int=0
	perimeter:int=300
	size:vector=vector(3)

	try:
		if len(sys.argv)>1 and sys.argv[1]=="-h":
			help()
			exit()
		elif len(sys.argv)>1:
			side=int(sys.argv[1])

			if len(sys.argv)>2:
				perimeter=int(sys.argv[2])

				if len(sys.argv)>3:
					size.x=int(sys.argv[3])
		else:
			side=int(input("# of sides 4 polygon: "))
	except ValueError as e1:
		print("[._.]: ERROR: AN ERROR OCCURED IN THE PROGRAM!\n")
		print("possible issues:")
		print("\t1. input is not an integer.")
		exit(1)

	#get shape var.s
	sum_angle:int=get_sum_angle(side)
	angle:int=get_angle(side)
	size.y=perimeter/side

	#print var.s
	print("side: "+str(side))
	print("sum angle: "+str(sum_angle))
	print("angle: "+str(angle))
	print("perimeter: "+str(perimeter))
	print("side width: "+str(size.x))
	print("side length: "+str(size.y))

	#get window
	win=turtle.Screen()
	win.title("SHAPE!")
	win.bgcolor("black")
	win.setup(500,500)
	win.tracer(0)

	#get shape
	shape=entity()
	shape.hideturtle()
	shape.forward(-size.y/2)
	shape.pendown()
	shape.pensize(size.x)

	#make shape according 2 sides inputed by user
	shape.fillcolor("grey")
	shape.begin_fill()

	for a in range(side):
		shape.forward(size.y)
		shape.left(180-angle)

	shape.end_fill()

	#get radius(d=c/(pi);c=2*(pi)*r)
	r1=entity()
	r1.hideturtle()
	r1.pendown()
	r1.color("red")
	r1.forward(perimeter/6)#(perimeter/3)/2=>50

	#loop 2 update screen 4 changes
	while True:
		win.update()