#date: 10/18/2022.
#description:
	#input:
                #-get invest over year quantity(float).
                #-get annual interest rate(float).
                #-get year quantity(int).
	#output:
                #-print year(int).
                #-print amount on deposit(float).
                #-seperated by tabs.
#get input.
invest=float(input("How much would you like to invest? "))
while invest<=0:
        print("")
        print("Investment must be greater than 0.")
        invest=float(input("How much would you like to invest? "))

interest=float(input("What is the annual interest rate? "))
while interest<=0 or interest>=20:
        print("")
        print("Investment rate must be greater than 0 and less than 20%.")
        interest=float(input("What is the annual interest rate? "))

years=int(input("How long would you like to invest? "))
while years<=0:
        print("")
        print(" Time for Investment must be greater than 0")
        years=int(input("How long would you like to invest? "))

#set deposit.
deposit=invest

print("Year\t    Amount on Deposit")

#output deposit quantity.
for i in range(1,years+1):
        deposit+=deposit*(interest/100)

        print(i,"\t     ",end="")
        print(round(deposit,2))
