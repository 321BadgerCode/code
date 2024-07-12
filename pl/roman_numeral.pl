#!/usr/bin/perl
use strict;
use warnings;

sub check_roman {
	my $roman=shift;
	if($roman=~m/^[MDCLXVI]+$/){
		return 1;
	}
	else{
		return 0;
	}
}

sub get_digit {
	my $digit=shift;
	if($digit eq "M"){
		return 1000;
	}
	elsif($digit eq "D"){
		return 500;
	}
	elsif($digit eq "C"){
		return 100;
	}
	elsif($digit eq "L"){
		return 50;
	}
	elsif($digit eq "X"){
		return 10;
	}
	elsif($digit eq "V"){
		return 5;
	}
	elsif($digit eq "I"){
		return 1;
	}
	else{
		return 0;
	}
}

sub roman_to_decimal {
	my $roman=shift;
	my $decimal=0;
	my $last_digit=0;
	my $current_digit=0;
	my $i=0;
	my $length=length($roman);
	while($i<$length){
		$current_digit=get_digit(substr($roman,$i,1));
		if($current_digit>$last_digit) {
			$decimal+=$current_digit-2*$last_digit;
		}
		else{
			$decimal+=$current_digit;
		}
		$last_digit=$current_digit;
		$i++;
	}
	return $decimal;
}

if(@ARGV==0){
	print("Please provide a Roman numeral as an argument.\n");
	exit;
}

my $roman=$ARGV[0];
if(check_roman($roman)){
		print(roman_to_decimal($roman)."\n");
}
else{
		print("Invalid roman numeral\n");
}