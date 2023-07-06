#date: 10/31/2022.
#description:
	#input:
                #-get string.
	#output:
                #-length of string.
                #-string reversed.
                #-3rd through 7th characters of string.
#get input.
string=input("Please enter a String: ")

#output substrings from string manipulation.
print("String:",string)
print("length of String:",len(string))
print("The String reversed: ",end="")#string[::-1]

#last char..
#1st char..
#decrement by 1.
for i in range(len(string)-1,-1,-1):
        print(string[i],end="")
print("")

print("The 3rd through 7th characters are:",string[2:7])
