#Dylan
class my{
	[void]print([string]$A1){write-host $A1;}
	[void]echo([string]$A1){write-host $A1 -noNewLine;}
	[string]input([string]$A1){[string]$b1="";try{$b1=read-host $A1;}catch{}return $b1;}
	[void]leave(){try{write-host "Press any key to exit this program" -noNewLine;[console]::readKey();[console]::clear();}catch{}}
	[void]write([object]$A1,[string]$A2,[string]$A3){try{$A1.foregroundColor=$A2;write-host $A3;$A1.foregroundColor="white";}catch{}}
};
filter random(){
	begin{[sbyte]$b1=0;}
	process{try{$b1=get-random -minimum $_.min -maximum $_.max;}catch{throw "ERROR!";}}
	end{return $b1;}
};
[object]$val=@{min=0;max=100;};
[object]$values=@{min=$val.min;max=$val.max;};
function main{
$my=[my]::new();
$hui=$host.ui.rawUI;$hui.windowTitle="GUESS_2!";
[string]$a1=$my.input("Number for me to guess(0-100)");
[sbyte]$a2=0;
[sbyte]$a3=0;
while($true){
	$a2=$values|random;
	$a3+=1;
	if($a3 -gt $val.max){$my.write($hui,"red","Sorry, but I could not determine your number :(");break;}
	elseIf([sbyte]$a1 -lt $a2){$values.max=$a2;$my.write($hui,"red",[string]$a3+": "+[string]$a2+" > "+$a1);continue;}
	elseIf([sbyte]$a1 -gt $a2){$values.min=$a2;$my.write($hui,"red",[string]$a3+": "+[string]$a2+" < "+$a1);continue;}
	else{$my.write($hui,"green",[string]$a3+": "+[string]$a2+" = "+$a1);$my.write($hui,"green","Yay, I guessed the correct number that you created!");break;}
};
$my.print("The number was "+$a2);$my.print("It took me "+[string]$a3+" tries to figure out your number");
$my.leave();
};main;