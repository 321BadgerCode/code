#badger
def absolute_value(num:int):
	b1:int=0
	try:
		if num<0:
			b1=num*-1
		else:
			b1=num
	except:
		b1=abs(num)
	return b1
def inpt(text:str):
	b1:int=0
	try:
		b1=int(input(text))
	except:
		b1=0
	return b1
def pt_inpt(pt_num):
	x1:int=inpt("Point "+str(pt_num)+" x: ")
	y1:int=inpt("Point "+str(pt_num)+" y: ")
	z1:int=inpt("Point "+str(pt_num)+" z: ")
	return [x1,y1,z1]