num=[12,17,19,31]

for n in range(len(num)):
        a=1
        while a<10:
                if 10%a==0:
                        print(a)
                        if num[n]>=a-2 or num[n]<=a+2:
                                print(a,num[n])
                                a=10
                a+=1
