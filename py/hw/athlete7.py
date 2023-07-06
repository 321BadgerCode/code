#date: 10/21/2022.
#description:
	#input:
                #-get 1st name(string).
                #-get birth year(int).
	#output:
                #-min. & max. target heart rate.
#get input.
name=input("What is the Athletes Name: ")

#get age.
print("What year was",name,end="")
born=int(input(" born? "))

age=2022-born
print(name,"is ",end="")
print(age,"years old.")

while age<13 or age>=220:
        print("Age must be greater than or equal to 13(year 2009) and less than 220(year 1802) years old.")
        print("")
        print("What year was",name,end="")
        born=int(input(" born? "))

        age=2022-born
        print(name,"is ",end="")
        print(age,"years old.")

#get T.H.R..
mhr=220-age
min_thr=mhr*(50/100)
max_thr=mhr*(85/100)

#output T.H.R..
print("Minimum Heart Rate: ",end="")
print(round(min_thr,1),end="")
print(".")

print("Maximum Heart Rate: ",end="")
print(round(max_thr,1),end="")
print(".")
