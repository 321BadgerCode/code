'badger

class robotz
	private spv
	public default function init():set spv=createObject("sapi.spVoice"):set init=me:end function
	public function say(A1,A2):set spv.voice=spv.getVoices.item(A1):spv.speak(A2):end function
end class
public sub main
	message=inputBox("Type what you want the synthesised voice to say","TEXT_TO_SPEECH!")
	set robot=(new robotz)()
	robot.say 0,message
end sub
main()