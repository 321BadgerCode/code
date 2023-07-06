#badger
from os import system
from var_1 import *
from vector_1 import *

if __name__=="__main__":
	v3:vector=vector(pt_inpt(1))
	v3_2:vector=vector(pt_inpt(2))

	"""mid=mid_point(pt1,pt2)
	dis_1d=distance_1d(pt1[0],pt1[1])
	dis_2d=distance_2d(pt1,pt2)"""

	print("Mid point: "+str(v3.mid_point(v3_2)))
	print("1.D. distance: "+str(v3.distance_1d(v3_2)))
	print("2.D. distance: "+str(v3.distance_2d(v3_2)))
	print("3.D. distance: "+str(v3.distance_3d(v3_2)))

	system("pause")
#add 3.D distance function
#try adding segment addition postulate function
#visualize the points(turtle module)
#U.I.(tkinter module)
#https://stackoverflow.com/questions/10457240/solving-polynomial-equations-in-python
#https://stackoverflow.com/questions/10499941/how-can-i-solve-equations-in-python