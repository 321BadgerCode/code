#date: 3/2/2023.
#description:
	#input:
                #-get usr. input of msg. they want encoded/decoded.
	#output:
		#-encoded/decoded txt..

#return cipher-text or plain-text of input depending which is inputted.
#symmetric encryption(same algorithm to encode & decode).
def get_cipher(in2):
        reverse=in2[::-1] #get reverse of input str.
        new="" #new string to return

        #set 'new' msg. to be 'reverse' consecutive letters swapped.
        for a in range(1,len(reverse),2):
                new+=reverse[a]+reverse[a-1]

        return new

#usr. can type "done" to end continuous run program.
print("type \"done\" to quit program.")

#continuous run.
cont=True
while cont:
        #get input.
        msg=input("in: ")

        #end program if usr. type "done".
        if msg=="done":
                cont=False
        else:
                #if 'msg' length is odd, make even by adding " ", so 'get_cipher' can work properly.
                if len(msg)%2!=0:
                        msg+=" "

                print("new msg.: "+get_cipher(msg)) #output encoded/decoded msg.
