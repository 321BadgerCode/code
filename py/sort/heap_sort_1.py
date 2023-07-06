#badger
def heapify(a1:int,n:int,i:int):
    largest=i
    l=2*i+1
    r=2*i+2
 
    if l<n and a1[largest]<a1[l]:
        largest=l
 
    if r<n and a1[largest]<a1[r]:
        largest=r
 
    if largest!=i:
        a1[i],a1[largest]=a1[largest],a1[i]
 
        heapify(a1,n,largest)
 
 
def heap_sort(a1:int=[0]):
    n=len(a1)
 
    for a in range(n//2-1,-1,-1):
        heapify(a1,n,a)
 
    for a in range(n-1,0,-1):
        a1[a],a1[0]=a1[0],a1[a]
        heapify(a1,a,0)
 
 
if __name__=="__main__":
        a1=[12,11,13,5,6,7]
        heap_sort(a1)
        print("Sorted array is")
        for a in range(len(a1)):
            print("%d"%a1[a]),
