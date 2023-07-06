#2. (1 pts) Comments including Header with name period and what the program does and the number of the requirement
#date: 12/07/2022
#description:
	#input: quarter 1 & 2 grades.
	#output: grade needed on semester exam for certain semester grades(A,B,C,D).
#1. (1 pts) Print Title
print("!*------Welcome to the Semester Exam Grade Calculator!------*!")
print("")

#6. (3 pts) Continuous run
abcd="ABCD"#string
cont=True#bool
while cont:#3. (3 pts) While or For
	#############################
	#####	get user input.	#####
	#############################
	qtr1=float(input("What is your first quarter grade percentage: "))#float

	#5. (3 pts) Logic
	#8. (5 pts) Error Proofing, grades cannot be less than 0 or greater than 100
	while qtr1<0 or qtr1>100:
		print("***That grade is unacceptable.***")
		qtr1=float(input("What is your first quarter grade percentage: "))

	qtr2=float(input("What is your second quarter grade percentage: "))

	while qtr2<0 or qtr2>100:
		print("***That grade is unacceptable.***")
		qtr2=float(input("What is your second quarter grade percentage: "))

	#####################################
	#####	print quarter grades.	#####
	#####################################
	print("_____________________________________________")
	print("First Qtr Grade: "+str(qtr1)+"\tSecond Qtr Grade: "+str(qtr2))
	print("_____________________________________________")

	#####################################################
	#####	print grades needed on semester exam.	#####
	#####################################################
	sem=89.5
	guarantee=0#int
	for a in range(0,len(abcd)):
		#10. (10 pts) Correct calculation of grades (rounded to tenths)
		sem_ex=round((sem-((.4*qtr1)+(.4*qtr2)))/.2,1)

		#9. (5pts) You will need extra credit to an A (if SemEx1 is &gt;100) this will print for every grade that will need EC.
		if sem_ex>100:
			print("You are going to need some extra credit to get a "+abcd[a])
		#(3 pts) You are guaranteed to get an C (if SemEx1 is negative) this will print once on the highest guaranteed grade.
		elif sem_ex<=0 and guarantee==0:
			print("You are guaranteed to get a "+abcd[a])
			guarantee=1

		print("To get an "+abcd[a]+" , you will need a "+str(sem_ex))
		if a<=len(abcd)-2:
			print("_____________________________________________")
		else:
			print("")
		sem-=10

	#4. (3 pts) If (else)
	#####################################################################
	#####	ask user if they want to calculate another grade.	#####
	#####################################################################
	ask=""
	while ask!="y" and ask!="yes" and ask!="n" and ask!="no":
		ask=input("Would you like to calculate another grade? ").lower()

		if ask=="n" or ask=="no":
			print("")
			print("")
			print("Thank you and Good Luck on your exam!")
			cont=False
		elif ask!="y" and ask!="yes":
			print("***That input is unacceptable.***")
		else:
			cont=True
#7. (6 pts) Use of 3 of the 4 data types (2 pts EC if you use all four)
#11. (10 pts) Runs without errors
#(had to delete)(2 pts) function implementation