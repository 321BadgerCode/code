#!/usr/bin/perl
use strict;
use warnings;

sub is_clr_fmt {
	my ($colour)=@_;
	return $colour=~/^rgb\(\d{1,3},\d{1,3},\d{1,3}\)$/;
}

sub print_clr_fmt {
	print("[._.]: VALID COLOR FORMAT IS THE PREFIX \"rgb(\" PROCEEDED BY 3 NUMBERS WITH 1-3 DIGITS WHICH ARE SEPARATED BY COMMAS, THEN AN ENDING \")\".\n");
	print("\n[._.]: EXAMPLE: perl ./clr.pl rgb\\(0,0,0\\) rgb\\(255,255,255\\)\n");
	print("[._.]: EXAMPLE: perl ./clr.pl \"rgb(0,0,0)\" \"rgb(255,255,255)\"\n");
	print("[._.]: EXAMPLE: perl ./clr.pl rgb\\(255,0,0\\) rgb\\(0,255,0\\)\n");
	print("[._.]: EXAMPLE: perl ./clr.pl \"rgb(255,0,0)\" \"rgb(0,255,0)\"\n");
	print("\n[._.]: REGEX FOR THE COLOR FORMAT: ^rgb\\(\\d{1,3},\\d{1,3},\\d{1,3}\\)\$\n");
}

sub get_rgb {
	my ($colour)=@_;
	my @rgb=$colour=~/(\d{1,3})/g;
	return @rgb;
}

for(my $i=0;$i<(scalar @ARGV);$i++){
	if($ARGV[$i] eq "-h"){
		print("HELP MENU:\n\n");
		print_clr_fmt();
		die;
	}
}

my ($c1,$c2)=@ARGV;
die "Usage: $0 <rgb_color> <rgb_color>" unless defined($c1)&&defined($c2);

if(not is_clr_fmt($c1) or not is_clr_fmt($c2)){
	if(not is_clr_fmt($c1)){print("> 1st color is invalid : ${c1}\n");}
	if(not is_clr_fmt($c2)){print("> 2nd color is invalid : ${c2}\n");}
	print("\n");
	print_clr_fmt();
	die "\nFix input colors & run program again.";
}

my @rgb1=get_rgb($c1);
my @rgb2=get_rgb($c2);

for(my $i=0;$i<=100;$i++){
	my $r=int($rgb1[0]+($rgb2[0]-$rgb1[0])*$i/100);
	my $g=int($rgb1[1]+($rgb2[1]-$rgb1[1])*$i/100);
	my $b=int($rgb1[2]+($rgb2[2]-$rgb1[2])*$i/100);
	print("\e[38;2;$r;$g;${b}mrgb($r,$g,$b)\e[0m\t:\t");
	print("\e[38;2;$r;$g;${b}m".sprintf("#%02x%02x%02x",$r,$g,$b)."\e[0m\n");
}