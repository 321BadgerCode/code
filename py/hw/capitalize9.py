#date: 11/2/2022.
#description:
	#input:
		#-get full name(1st,middle,last).
	#output:
		#-capitalized 1st char. of every name.
#continuous loop asking for full name, then outputting capitalized name.
done=False
while not done:
        #get input.
	name=input("What is the name? ").lower()+" "

        #if usr. type 'done', then end program.
	if name=="done ":
		print("The End!")
		done=True
	else:
                #-find da 3 spaces.
                #-output name every iteration with capitalized 1st char..
                #-set name=rest of name without sub-name.
		for i in range(0,3):
			index=name.find(" ")

			print(name[0].upper()+name[1:index+1],end="")
			name=name[index+1:]
		#print(name)#john john john the great(no more than 3 words; don't need)
		print("")

	print("")
