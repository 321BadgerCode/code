#2. (1 pts) Comments including Header with name period and what the program does and the number of the requirement
#date: 12/07/2022
#description:
	#input: quarter 1 & 2 grades.
	#output: grade needed on semester exam for certain semester grades.
"""
msg:prompt for usr..

return:grade.
"""
def get_grade(msg):
	grade=float(input(msg))

	#3. (3 pts) While or For
	#5. (3 pts) Logic
	#8. (5 pts) Error Proofing, grades cannot be less than 0 or greater than 100
	while grade<0 or grade>100:
		print("***That grade is unacceptable.***")
		grade=float(input(msg))

	return grade

"""
qtr1:quarter 1 grade.
qtr2:quarter 2 grade.
sem:grade wanted for semester.

return:grade needed on semester exam to get desired semester grade.
"""
def get_sem_ex(qtr1,qtr2,sem):
	return round((sem-((.4*qtr1)+(.4*qtr2)))/.2,1)

#1. (1 pts) Print Title
print("!*------Welcome to the Semester Exam Grade Calculator!------*!")
print("")

#6. (3 pts) Continuous run
abcd="ABCD"
cont=True
while cont:
	qtr1=get_grade("What is your first quarter grade percentage: ")
	qtr2=get_grade("What is your second quarter grade percentage: ")
	print("_____________________________________________")
	print("First Qtr Grade: "+str(qtr1)+"\tSecond Qtr Grade: "+str(qtr2))
	print("_____________________________________________")

	sem=89.5
	guarantee=False
	for a in range(0,len(abcd)):
		sem_ex=get_sem_ex(qtr1,qtr2,sem)

		if sem_ex>100:
			print("You are going to need some extra credit to get a "+abcd[a])
		elif sem_ex<=0 and guarantee==False:
			print("You are guaranteed to get a "+abcd[a])
			guarantee=True

		print("To get an "+abcd[a]+" , you will need a "+str(sem_ex))
		if a<=len(abcd)-2:
			print("_____________________________________________")
		else:
			print("")
		sem-=10

	#4. (3 pts) If (else)
	ask=""
	while ask!="y" and ask!="yes" and ask!="n" and ask!="no":
		ask=input("Would you like to calculate another grade? ").lower()

		if ask=="n" or ask=="no":
			print("\n\nThank you and Good Luck on your exam!")
			cont=False
		elif ask!="y" and ask!="yes":
			print("***That input is unacceptable.***")
		else:
			cont=True
