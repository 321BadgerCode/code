#badger
from math import sqrt

class vector:
	x:float=0
	y:float=0
	z:float=0
	def __init__(self,x:float,y:float,z:float):
		self.x=x
		self.y=y
		self.z=z
	def __eq__(self,v3:object):
		return self.x==v3.x and self.y==v3.y and self.z==v3.z
	def distance_1d(self,v1):
		b1:float=abs(self.x-v1.x)
		return b1
	def distance_2d(self,v2):
		x1:float=(self.x-v2.x)**2
		y1:float=(self.y-v2.y)**2
		b1:float=sqrt(x1+y1)
		return b1
	def distance_3d(self,v2):
		x1:float=(self.x-v2.x)**2
		y1:float=(self.y-v2.y)**2
		z1:float=(self.z-v2.z)**2
		b1:float=sqrt(x1+y1+z1)
		return b1
	def mid_point(self,v2):
		x:float=(self.x+v2.x)/2
		y:float=(self.y+v2.y)/2
		return [x,y]

class square:
	def __get_density(self):
		return self.mass/self.volume
	def __get_volume(self):
		return self.mass/self.density
	def __get_mass(self):
		return self.density*self.volume
	def __get_acceleration(self):
		return self.force/self.mass
	def __get_force(self):
		return self.mass*self.acceleration
	def __get_velocity(self):
		return self.acceleration*self.time

	class collide:
		left:int=0
		right:int=1
		top:int=2
		bottom:int=3
	size:vector=vector(0,0,0)
	position:vector=vector(0,0,0)
	
	density:float=0
	volume:float=0
	mass:float=0
	acceleration:float=0
	force:float=0
	time:float=0
	velocity:float=0
	def __init__(self,mass:float,acceleration:float,time:float):
		self.mass=mass
		self.acceleration=acceleration
		self.force=self.__get_force()
		self.time=time
		self.velocity=self.__get_velocity()
	#def get_collide(self):

def find_pi(obj:square,obj2:square):
	return (((1/2)*obj.mass)*(obj.velocity**2))+((1/2)*obj2.mass)*(obj2.velocity**2)
	#return (obj.mass*obj.velocity)+(obj2.mass*obj2.velocity)

if __name__=="__main__":
	s1=square(100,5,7)
	s2=square(100,5,7)
	
	print(str(find_pi(s1,s2)))
#fix 'find_pi' function
#add visualizations
