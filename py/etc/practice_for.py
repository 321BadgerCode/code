#practice for
#1,3,6,10,15,21,28,...
tri_num=int(input("How many triangular numbers would you like?"))

total=0
for n in range(1,tri_num+1):
        total+=n
        print(total,end="")

        if n<tri_num:
                print(", ",end="")
        else:
                print(".")
