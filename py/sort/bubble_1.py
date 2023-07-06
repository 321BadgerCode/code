#badger
def bubble_sort(a1:int=[0]):
	n=len(a1)
  
	for a in range(n):
		for b in range(0,n-a-1):
			if a1[b]>a1[b+1] :
				a1[b],a1[b+1]=a1[b+1],a1[b]
  
if __name__=="__main__":
        a1:int=[64,34,25,12,22,11,90]
          
        bubble_sort(a1)
          
        print ("Sorted array is:")
        for a in range(len(a1)):
                print ("%d" %a1[a]),