#badger
class my{
	[void]pause(){write-host "Press any key to continue..." -noNewLine;[console]::readKey();[console]::clear();}
	[string]input([string]$A1){[string]$b1=read-host $A1;return $b1;}
};
class robot{
	[object]$private:v;
	[void]gv(){Add-Type -AssemblyName System.speech;}
	[void]sv(){try{$this.v=New-Object System.Speech.Synthesis.SpeechSynthesizer;}catch{write-host "ERROR WITH ROBOT BEING SETUP!";}}
	[void]say([string]$A1){try{$this.v.speak($A1);}catch{write-host "ERROR WITH ROBOT SPEAKING!";}finally{write-host($A1);}}
};
function main{
$my=[my]::new();$robot=[robot]::new();
$robot.gv();$robot.sv();
$a1=$my.input("String for robot to say");$robot.say($a1);
$my.pause();
};
main;