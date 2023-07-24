#!/bin/bash
#badger
for (( a=30; a<=37; a++ ));do
	echo "${a}:"

	for (( b=0; b<=9; b++ ));do
		echo -n -e "${b}: \033[${b};${a}mtest\033[0m : "
		echo "\033[${b};${a}m"
	done;echo
done

for (( a=0; a<=255; a++ ));do
	echo -n -e "${a}: \033[38;5;${a}mtest\033[0m : "
	echo "\033[38;5;${a}m"
done

echo
echo "\"\033[48;5;9mbg text\033[0m\"(the '48' rather than '38' prefix is bg txt. vs. fg txt.) & it looks like:"
echo -e "\033[48;5;9mbg text\033[0m"