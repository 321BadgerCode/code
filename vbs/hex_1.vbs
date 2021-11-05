'badger
function to_string(var):to_string=cStr(var):end function
function to_hex(num):to_hex=hex(num):end function

sub main
	wScript.echo(_
	"Hex value of '25': "+to_string(to_hex(25))+vbNewLine+_
	"Hex value of '10': "+to_string(to_hex(10))+vbNewLine+_
	"Hex value of '5': "+to_string(to_hex(5))
end sub

main()