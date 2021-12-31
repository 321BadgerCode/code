'badger
function random(a1,a2):randomize:b1=int((a2-a1+1)*rnd+1):random=b1:end function

num=random(1,100)

wScript.echo num

do
	a1=inputBox("Guess the number that the computer created(1-100)")
	guess=cint(a1)
	if guess<num then
		wScript.echo("LESS!")
	elseIf guess>num then
		wScript.echo("GREATER!")
	else
		wScript.echo("CORRECT!")
		exit do
	end if
loop until num=guess