#date: 10/6/2022.
#description:
        #input: student quantity & their grades as int..
        #output: print class average.
#get # of students in class.
student=int(input("How many students are in the class?"))

#get sum of students' grades.
sum1=0

i=0 #iterator/counter
while i<student:
        #get grade.
        print("Input grade",i+1,end="")
        grade=float(input(" :"))

        #check if grade is acceptable.
        if grade<0:
                print("That grade is unacceptable")
        elif grade>100:
                print("That grade is unacceptable")
        else:
                #add grade to sum.
                #move to next iteration/student's grade.
                sum1+=grade
                i=i+1

#get average of class grade.
avg=sum1/student #average
print("The class average is ",avg)
