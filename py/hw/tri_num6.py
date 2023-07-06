#date: 10/11/2022.
#description:
	#input: get how many tri. #'s usr. wants.
	#output: print tri. #'s.
#get input
quantity=int(input("How many triangular numbers would you like to display? "))

print("")

#print tri. #'s.
tri_num=0
i=1 #iterator
while i<=quantity:
	#set tri. #.
	tri_num=tri_num+i

	#print tri. # w/ comma if not last sequence index.
	#print tri. # w/ period if it is the last sequence index.
	if i<quantity:
		print(tri_num,end="")
		print(", ",end="")
	else:
		print(tri_num,end="")
		print(".")

	i=i+1 #next iteration
#restrictions:
	#can only use #'s: 0 & 1.
	#can't use formula/rule 4 tri. num(use adder).
#tri. #:
	#seq.: {1,3,6,10,15,21,28,36,...}.
	#rule: (n*(n+1))/2.
#https://en.wikipedia.org/wiki/Triangular_number