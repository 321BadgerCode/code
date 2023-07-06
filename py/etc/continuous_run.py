#continuous run.
done=False
while not done:
        string=input("What is the name? ")

        if string=="finish":
                print("Thank you for playing")
                done=True
        else:
                front=string[0]
                back=string[1:]
                front=front.upper()
                print(front+back)
