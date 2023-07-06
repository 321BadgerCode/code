#badger
from math import sqrt

class circle:
	def __init__(self,radius:float):
		self.radius:float=radius
		self.circumference:float=get_circumference(radius)
		self.area:float=get_area(radius)
		self.diameter:float=get_diameter(radius)
		self.perimeter:float=get_perimeter(radius)
		self.surface_area:float=get_surface_area(radius)
		self.volume:float=get_volume(radius)
	def __str__(self):
		b1:str="circle:\nradius: "+str(self.radius)
		"\ncircumference: "+str(self.circumference)
		"\narea: "+str(self.area)
		"\ndiameter: "+str(self.diameter)
		"\nperimeter: "+str(self.perimeter)
		"\nsurface area: "+str(self.surface_area)
		"\nvolume: "+str(self.volume)
		return b1

def get_pi(accurate:int=5)->complex:
	a1:float=[1]*accurate
	b1:float=[1/sqrt(2)]*accurate
	t1:float=[1/4]*accurate
	p1:float=[1]*accurate
	pi:complex=0

	for a in range(accurate-1):
		a1[a+1]=(a1[a]+b1[a])/2
		b1[a+1]=sqrt(a1[a]*b1[a])
		t1[a+1]=t1[a]-p1[a]*(a1[a]-a1[a+1])**2
		p1[a+1]=2*p1[a]
		pi=(a1[a]+b1[a])**2/(4*t1[a])

	return pi

def get_pi_2(circumference:float,diameter:float)->complex:
	return circumference/diameter

def get_radius(diameter:float)->complex:
	return diameter/2

def get_circumference(radius:float)->complex:
	return 2*radius*get_pi()

def get_area(radius:float)->complex:
	return radius**2*get_pi()

def get_diameter(radius:float)->complex:
	return 2*radius

def get_perimeter(radius:float)->complex:
	return 2*radius*get_pi()

def get_surface_area(radius:float)->complex:
	return 4*get_pi()*radius**2

def get_volume(radius:float)->complex:
	return (4/3)*get_pi()*radius**3

if __name__=="__main__":
	c=circle(5)
	print("π="+str(get_pi()))
	"""print("circumference="+str(get_circumference(5)))
	print("area="+str(get_area(5)))
	print("diameter="+str(get_diameter(5)))
	print("perimeter="+str(get_perimeter(5)))
	print("surface area="+str(get_surface_area(5)))
	print("volume="+str(get_volume(5)))"""
	print(c)
#pi=circumference/diameter
#pi=22/7