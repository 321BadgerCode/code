'badger
function convert_wattage_time(user_wattage,wattage,second)
	b1=(wattage/user_wattage)*second
	convert_wattage_time=b1
end function

sub main
	user_wattage=inputBox("Your microwave wattage: ")
	wattage=inputBox("Microwave wattage(on package): ")
	time_second=inputBox("Time(second) on package: ")
	a1=convert_wattage_time(cInt(user_wattage),cInt(wattage),cInt(time_second))
	msgbox("New time: "+cStr(a1)+" seconds")
end sub

main()