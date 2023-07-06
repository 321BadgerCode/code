#date: 1/9/2023
#description:
	#input:grades.
	#output:max,min,avg..
#return max. of list.
def getMax(mylist):
	big=mylist[0]
	for a in mylist:
		if a>big:
			big=a
	return big
#return min. of list.
def getMin(mylist):
	smol=mylist[0]
	for a in mylist:
		if a<smol:
			smol=a
	return smol
#return avg. of list.
def getAvg(mylist):
	sum1=0
	for a in mylist:
		sum1+=a
	return sum1/len(mylist)

#input iterations.
n_grade=int(input("How many grades would you like to input? "))
grades=[]

#get grades.
i=1
while i<=n_grade:
        #get grade.
	grade=float(input("Enter Grade "+str(i)+" : "))
	while grade<0 or grade>100:
		print("That grade is unacceptable, please enter a grade from 0-100")
		grade=float(input("Enter Grade "+str(i)+" : "))

        #add grade to list.
	grades.append(grade)

	i+=1

#calculate min.,max.,&avg.
print("There are "+str(n_grade)+" grades.")
print("The maximum grade is: "+str(getMax(grades)))
print("The minimum grade is: "+str(getMin(grades)))
print("The average grade is: "+str(getAvg(grades)))
