'badger
function to_string(var):to_string=cStr(var):end function

sub main
	wScript.echo(_
	"Year: "+to_string(year(date))+vbNewLine+_
	"Date: "+to_string(date)+vbNewLine+_
	"Time: "+to_string(now)+vbNewLine+_
	"Universal hour: "+to_string(hour(now)))+vbNewLine
end sub

main()