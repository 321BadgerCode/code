#badger
class my{
	[void]leave(){try{write-host "Press any key to close this program..." -noNewLine;[console]::readKey();[console]::clear();}catch{}}
};
class robot{
	[void]get_voice(){try{Add-Type -AssemblyName System.speech;}catch{}}
	[object]voice(){[object]$b1="";try{$b1=New-Object System.Speech.Synthesis.SpeechSynthesizer;}catch{$b1="";}return $b1;}
	[void]say([object]$A1,[string]$A2){try{$A1.speak($A2);}catch{}write-host($A2);}
	[string]ask([object]$A1,[string]$A2){try{$A1.speak($A2);}catch{}return read-host $A2;}
};
function main{
[object]$my=[my]::new();[object]$robot=[robot]::new();
$robot.get_voice();
[object]$voice=$robot.voice();
[string]$a1=$robot.ask($voice,"What do you want the robot to say?");
$robot.say($voice,$a1);
$my.leave();
};
main;