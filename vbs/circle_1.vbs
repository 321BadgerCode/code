'badger
set wss=createObject("wScript.shell")
set cmd=wss.exec("%COMSPEC% /c date /t")

class math
	private pi

	public default function init()
		pi=3.14159265359
		set init=me
	end function
	public property get get_pi():get_pi=pi:end property
end class
class circle
	private math1

	public radius
	public default function init(radius1)
		set math1=(new math)()
		radius=radius1
		set init=me
	end function
	public function get_radius(diameter)
		r=diameter/2
		get_radius=r
	end function
	public function get_perimeter()
		c=(2*math1.get_pi())*radius
		get_perimeter=c
	end function
	public function get_circumference():get_circumference=get_perimeter():end function
	public function get_area()
		'a=math1.get_pi()*(radius^2)
		'get_area=a
		get_area=0
	end function
end class
function to_string(integer1):to_string=cStr(integer1):end function
function to_integer(string1):to_integer=cInt(string1):end function

set circle1=(new circle)(0)

cmd.stdIn.writeLine("cd/{enter}")
cmd.stdIn.writeLine("title circle_1{enter}")
cmd.stdIn.writeLine("set /p a1='Radius of circle: '{enter}")
circle1.radius=cmd.stdOut.read(1)
cmd.stdIn.writeLine("cls{enter}")
cmd.stdIn.writeLine("echo "+to_string(circle1.get_area())+"{enter}")



'cmd.sendKeys "cd/{enter}"
'cmd.sendKeys "title circle_1{enter}"
'cmd.sendKeys "set /p a1='Radius of circle: '{enter}"
'circle1.radius=to_integer(cmd.stdOut.readAll)
'cmd.sendKeys "cls{enter}"
'cmd.sendKeys "echo "+to_string(circle1.get_area())+"{enter}"
'fix