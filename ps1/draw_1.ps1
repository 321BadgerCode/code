#badger
function global:console_position([int]$x,[int]$y){
	$position=$host.ui.rawui.cursorposition;

	$position.x=$x;
	$position.y=$y;

	$host.ui.rawui.cursorposition=$position;
}

function global:line([int]$x,[int]$y,[int]$length,[int]$vertical){
set-ConsolePosition $x $y;

write-host "*" -nonewline;

If ([boolean]$vertical) {$linechar="!";$vert=1;$horz=0;}
else{$linechar="-"; $vert=0;$horz=1;}

foreach ($count in 1..($length-1)) {
	set-ConsolePosition (($horz*$count)+$x) (($vert*$count)+$y);
	write-host $linechar -nonewline;
}

$count++;
set-ConsolePosition(($horz*$count)+$x)(($vert*$count)+$y);
write-host "*" -nonewline;
}

function global:box([int]$width,[int]$length,[int]$x,[int]$y){
foreach($box in 0..3){
     $side=$box%2;

     $vert=[int](($box-.5)/2);

     $totalside=$width+$length;


     $linelength=($vert*$length)+([int](!$vert)*$width);
     $result=$totalside-$linelength;

     $ypass=([int](!$vert)*$side*$result)+$y;
     $xpass=($vert*$side*$result)+$x;

     draw-line $xpass $ypass $linelength $vert;
}
}