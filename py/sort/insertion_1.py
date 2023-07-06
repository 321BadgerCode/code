#badger
def insertion_sort(a1:int=[0]):
    for a in range(1,len(a1)):
        key:int=a1[a]

        b:int=a-1
        
        while b>=0 and key<a1[b] :
                a1[b+1]=a1[b]
                b-=1
                
        a1[b+1]=key
 
 
if __name__=="__main__":
        a1:int=[12,11,13,5,6]
        
        insertion_sort(a1)
        
        for a in range(len(a1)):
            print("% d"%a1[a])
