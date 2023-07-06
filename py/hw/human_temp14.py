#date: 1/05/2023
#description:
        #input: patient's temp..
        #output: what to do & celcius.
#title.
print("***Human Temperature Observation***\n")

#continuous loop.
cont=True
while cont:
        #get input(patient's temp.).
	f=float(input("What is the patient's temperature (in Fahrenheit)? "))

	#convert patient's temp. in fahrenheit to celcius.
	c=(5/9)*(f-32)
	c=round(c,1)

        #determine what to do from temp..
	if f<90 or f>105:
		print("\n\n**********************************************************")
		print("***Take the patient to the Emergency Room Immediately!!***")
		print("**********************************************************\n\n")
	elif f>=90 and f<95:
		print("The patient potentially has hypothermia!")
		print(" Cover with Blankets.")
		print("Monitor Breathing. Provide warm Beverages!")
	elif (f>=95 and f<97.7) or (f>=99.5 and f<100.9):
		print("Observe Patient!")
	elif f>=97.7 and f<99.5:
		print("The patient is in the normal range of temperature.")
	elif f>=100.9 and f<105:
		print("The patient has a fever!")
		print("Rest and drink plenty of fluids. Medication isn't needed.")
		print("Call the doctor if the fever is accompanied by a sever headache, stiff neck, shortness of breath, or other unusual signs or symptoms.")

        #temp. in celcius.
	print("\nThe patient's temperature in Cel is  "+str(c)+" C")

        #ask to run again.
	cont2=""
	while cont2!="no" and cont2!="yes":
		cont2=input("type yes to continue ").lower()

		if cont2=="no":
			print("the end")
			cont=False
		elif cont2!="yes":
			print("that input isn't valid")
	print("\n")
"""
???
The "observation necessary" must be a single statement using logic (and / or / not) and
"Take to Emergency Room" must be a single statement using logic (and / or / not).
"""
