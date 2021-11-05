'badger

class robot
	private spv
	private gender
	public default function init(gender1)
		if gender1="m" then
			gender=0
		elseIf gender1="f" then
			gender=1
		end if
		set spv=createObject("sapi.spVoice")
		set init=me
	end function
	public function say(text):set spv.voice=spv.getVoices.item(gender):spv.speak(text):end function
end class
function celsius(fahrenheit)
	b1=(fahrenheit-32)/1.8
	celsius=b1
end function
sub main
	set r=(new robot)("m")
	a1=inputBox("Degree/number(fahrenheit) to be converted into celsius: ","Fahrenheit to celsius")
	num=cInt(a1)
	temp=celsius(num)
	msgbox(cStr(temp)+vbNewLine+"Rounded: "+cStr(round(temp)))
	r.say("Temperature in celsius is approximately "+cStr(round(temp))+"°")
end sub

main()