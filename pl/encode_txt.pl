#!/usr/bin/perl
use strict;
use warnings;

sub create_binary_matrix {
	my ($input_string) = @_;

	my @binary_matrix;
	for my $char (split //, $input_string) {
		my $binary_char = unpack('B8', $char);
		push @binary_matrix, [split //, $binary_char];
	}

	return \@binary_matrix;
}

my ($arg1)=@ARGV;
die "Usage: $0 <text to encode>" unless defined($arg1);
my $string = shift || $arg1;

my $binary_matrix_ref = create_binary_matrix($string);

my $i=0;
my $j=0;
foreach my $row (@$binary_matrix_ref){
	for my $col (@$row){
		print $col eq "1" ? "█" : " ";
		$j++;
	}
	my $chr=substr($string, $i, 1);
	print("\t:\t${chr}\n");
	$i++;
}