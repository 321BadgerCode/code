#Dylan
class my{
	[string]date(){[string]$b1="";try{$b1=get-date;}catch{throw "ERROR!";}return $b1;}
	[void]beep([int16]$A1,[sbyte]$A2){[int16]$b1=$A2*1000;if($A1 -ge 190 -or $A1 -le 8500){try{[console]::beep($A1,$b1);}catch{throw "ERROR!";}}}
	[void]leave(){try{write-host "Press any key to exit this program" -noNewLine;[console]::readKey();[console]::clear();}catch{throw "ERROR!";}}
};
function [void]write(){
	[cmdLetBinding()]
	param([parameter(mandatory=$true)][string]$A1,[parameter(mandatory=$false)][bool]$A2,[parameter(mandatory=$false)][object]$A3,[parameter(mandatory=$false)][string]$A4);
	[bool]$b1=$false;
	try{$b1=$A2;}catch{}
	try{$A3.foregroundColor=$A4;}catch{}
	try{if($b1 -eq $false){write-host $A1;}else{write-host $A1 -noNewLine;}}catch{throw "ERROR!";}
	try{$A3.foregroundColor="white";}catch{}
};
function main{
$my=[my]::new();
$hui=$host.ui.rawUI;$hui.windowTitle="INFO_1!";
$my.beep(500,1);
write("Today is",$true);
write($my.date(),$hui,"blue");
write("I hope that you have a great day today :D");
write("Bye, I'll see you later :D");
$my.leave();
};main;