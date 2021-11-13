#badger
class polygon:
	side:int=0
	def __init__(self,side:int)->None:
		self.side=side
	def get_shape(self)->str:
		if self.side>=1 and self.side<=20:
			return shape[self.side]
		else:
			return str(self.side)+"-gon"
	def get_sum_int_angle_polygon(self)->int:
		b1:int=(self.side-2)*180
		return b1
	def get_sum_ext_angle_polygon(self)->int:
		return 360

shape:dict={
	1:"monogon",
	2:"digon",
	3:"triangle",
	4:"quadrilateral",
	5:"pentagon",
	6:"hexagon",
	7:"heptagon",
	8:"octagon",
	9:"nonagon",
	10:"decagon",
	11:"hendecagon",
	12:"dodecagon",
	13:"tridecagon",
	14:"tetradecagon",
	15:"pentadecagon",
	16:"hexadecagon",
	17:"heptadecagon",
	18:"octadecagon",
	19:"nonadecagon",
	20:"icosagon",
}

if __name__=="__main__":
	a1:str=input("number side poly.: ")
	p1=polygon(int(a1))
	print("shape: "+str(p1.get_shape()))
	print("sum int. ∠ poly.: "+str(p1.get_sum_int_angle_polygon())+"°")
	print("sum ext. ∠ poly: "+str(p1.get_sum_ext_angle_polygon())+"°")