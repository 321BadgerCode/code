#date: 1/12/2023
#description:
	#input:name.
	#output:name(first,middle,last)(optional),capitalized.
def capitalize(name):
	return name[0].upper()+name[1:]

"""def num_spaces(txt):
	ans=0
	for a in range(len(txt)):
		if txt[a]==" ":
			ans+=1
	return ans

def split(txt,char,size):
	ans=[""]*size
	a=0
	i=0
	while i<len(txt):
		if txt[i]==char:
			ans[a]=txt[:i]
			txt=txt[i+1:]
		i+=1
	return ans"""
def split(txt,delimiters=[" ","\t","\n"]):
    result=[]
    word=""
    for c in txt:
	if c not in delimiters:
	    word+=c
	elif word:
	    result.append(word)
	    word=''

    if word:
	result.append(word)

    return result

#title.
print("***Capitalizing method***")

#continuous run.
done=False
while not done:
	#get input.
	name=input("Input name to be capitalized: ").lower().strip(" ")+" "

	#if usr. type 'done', then end program.
	if name=="done ":
		print("The End!")
		done=True
	else:
		#-split text into multiple words.
		#-output name every iteration with capitalized word.
		name2=split(name)
		for i in range(len(name2)):
			print(capitalize(name2[i])+" ",end="")
		print("")

	print("")
