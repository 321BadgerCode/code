#Dylan
class my{
	[void]sleep([sbyte]$A1){start-sleep $A1;}
	[string]date(){[string]$b1="";try{$b1=get-date;}catch{throw "ERROR!";}return $b1;}
	[void]beep([int16]$A1,[sbyte]$A2){[int16]$b1=$A2*1000;if($A1 -ge 190 -or $A1 -le 8500){try{[console]::beep($A1,$b1);}catch{throw "ERROR!";}}}
	[void]leave(){try{write-host "Press any key to exit this program" -noNewLine;[console]::readKey();[console]::clear();}catch{throw "ERROR!";}}
};
class con{
	[object]$private:ui;
	[void]init([object]$A1,[string]$A2){$this.ui=$A1;$this.ui.windowTitle=$A2;}
	#Allow echo/-noNewLine for string with no "@" for print function
	[void]print([string]$A1,[string]$A2){[string[]]$b1=$A2.split("@");try{$this.ui.foregroundColor=$A1;for([sbyte]$b=0;$b -lt $b1.length;$b++){write-host $b1[$b];}$this.ui.foregroundColor="white";}catch{}}
	[string]for_do([string]$A1,[char]$A2){[string]$b1="";[sbyte]$b2=0;[string]$b3=$A1.replace("@","");try{while($b2 -lt $b3.length){if($b3[$b2] -eq ' '){$b1+=" ";}else{$b1+=$A2;}$b2+=1;}}catch{}return $b1;}
	[string]for_do2([string]$A1,[char]$A2){[string]$b1="";[sbyte]$b2=0;[string]$b3=$A1.replace("@","");try{while($b2 -lt $b3.length){if($b3[$b2] -eq ' '){$b1+=" ";}else{$b1+=$A2;}$b2+=1;}}catch{}return $A1+"@"+$b1;}
};
[object]$clr=@{w="white";r="red";g="green";b="blue";y="yellow";b2="black";};
function main{
$my=[my]::new();$con=[con]::new();
$hui=$host.ui.rawUI;$con.init($hui,"INFO_1!");
$my.beep(500,1);
$con.print($clr.w,"Today is ");$con.print($clr.y,$my.date());
$con.print($clr.g,"I hope that you have a great day today :D");
$con.print($clr.r,"Bye, I'll see you later :D");
$my.sleep(3);
$con.print($clr.g,$con.for_do("Sike, now you can leave the program :D",'_'));
$con.print($clr.y,$con.for_do2("Sike, now you can leave the program :D",'-'));
$my.leave();
};main;