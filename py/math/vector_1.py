#badger
from var_1 import *
from math import sqrt
from multimethod import multimethod

class vector:
	x:int=0
	y:int=0
	z:int=0
	"""def __init__(self,x1:int=0,y1:int=0,z1:int=0):
		self.x=x1
		self.y=y1
		self.z=z1"""
	def __init__(self,a1:int):
		self.x=a1[0]
		self.y=a1[1]
		self.z=a1[2]
	"""def __init__(self,v3):
		self.x=v3.x
		self.y=v3.y
		self.z=v3.z"""
	def __eq__(self,v3:object):
		return self.x==v3.x and self.y==v3.y and self.z==v3.z
	def distance_1d(self,v1):#distance formula(1.D.)
		b1:int=absolute_value(self.x-v1.x)
		return b1
	def distance_2d(self,v2):#pythagorean theorem/distance formula(2.D.)
		x1:int=(self.x-v2.x)**2
		y1:int=(self.y-v2.y)**2
		b1:int=sqrt(x1+y1)
		return b1
	def distance_3d(self,v2):#pythagorean theorem/distance formula(3.D.)
		x1:int=(self.x-v2.x)**2
		y1:int=(self.y-v2.y)**2
		z1:int=(self.z-v2.z)**2
		b1:int=sqrt(x1+y1+z1)
		return b1
	def mid_point(self,v2):#mid-point formula
		x:int=(self.x+v2.x)/2
		y:int=(self.y+v2.y)/2
		return [x,y]