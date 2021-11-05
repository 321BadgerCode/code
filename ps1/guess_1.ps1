#Dylan
class my{
	[void]print([string]$A1){write-host $A1;}
	[void]echo([string]$A1){write-host $A1 -noNewLine;}
	[string]input([string]$A1){[string]$b1="";try{$b1=read-host $A1;}catch{}return $b1;}
	[void]leave(){try{write-host "Press any key to exit this program" -noNewLine;[console]::readKey();[console]::clear();}catch{}}
	[void]write([object]$A1,[string]$A2,[string]$A3){try{$A1.foregroundColor=$A2;write-host $A3;$A1.foregroundColor="white";}catch{}}
};
filter random(){[sbyte]$b1=0;try{$b1=get-random -minimum $_.min -maximum $_.max;}catch{throw "ERROR!";}return $b1;};
[object]$values=@{min=0;max=100;};
function main{
$my=[my]::new();
$hui=$host.ui.rawUI;$hui.windowTitle="GUESS_1!";
[sbyte]$a1=$values|random;
[string]$a2="";
[sbyte]$a3=0;
$my.print("Type '' or 'exit' to see the random number that the computer came up with :D");
while($true){
	$a2=$my.input("Guess the number");
	$a3+=1;
	if($a2 -ieq "exit" -or $a2 -ieq ""){break;}
	elseIf($a1 -lt $a2){$my.write($hui,"red","Greater");continue;}
	elseIf($a1 -gt $a2){$my.write($hui,"red","Less");continue;}
	else{$my.write($hui,"green","Yay, you guessed the correct number that the computer created!");break;}
};
$my.print("The number was "+$a1.toString()+".");$my.print("It took you "+[string]$a3+" tries to figure out the random number that the computer had assembled.");
$my.leave();
};main;