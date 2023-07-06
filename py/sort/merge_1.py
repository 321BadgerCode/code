#badger
def merge_sort(a1:int=[0]):
	if len(a1)>1:
  
		mid = len(a1)//2
  
		L = a1[:mid]
  
		R = a1[mid:]
  
		merge_sort(L)
  
		merge_sort(R)
  
		a=b=c=0
		
		while a<len(L) and b<len(R):
			if L[a]<R[b]:
				a1[c]=L[a]
				a+=1
			else:
				a1[c]=R[b]
				b+=1
			c+=1
  
		while a<len(L):
			a1[c]=L[a]
			a+=1
			c+=1
  
		while b<len(R):
			a1[c]=R[b]
			b+=1
			c+=1
  
def print_list(arr):
	for a in range(len(arr)):
		print(arr[a],end=" ")
	print()

if __name__=="__main__":
	a1:int=[12,11,13,5,6,7]
	print("Given array is",end="\n")
	print_list(a1)
	merge_sort(a1)
	print("Sorted array is: ",end="\n")
	print_list(a1)