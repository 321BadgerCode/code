#!/bin/bash
#badger
. ./etc/color.sh
. ./etc/device.sh
. ./etc/error.sh
. ./etc/file.sh
. ./etc/info.sh
. ./etc/key_word.sh
. ./etc/load_bar.sh
. ./etc/math.sh

guess=0
get_random_num
number=$?
try=0

try_folder="./save"
try_file="${try_folder}/guess_try.txt"

help(){
	echo -e "help:\n"
	echo "usage: guess."
	echo -e "syntax: guess -[h|a|i|w|r|d|t:].\n"
	echo "option:"
	echo -e "${red}h:\thelp.${end}"
	echo -e "${orange}a:\tabout.${end}"
	echo -e "${yellow}i:\tinfo.${end}"
	echo -e "${green}w:\twelcome.${end}"
	echo -e "${blue}r:\tredo random #.${end}"
	echo -e "${indigo}d:\tdevice info..${end}"
	echo -e "${violet}t:\ttest(prints argument 2 console).${end}"
}

about(){
	echo -e "about:\n"
	echo -e "${red}*the robot(Billy) has chosen a # between 1 and 100.${end}"
	echo -e "${orange}*it's your job to guess what the # is.${end}"
	echo -e "${yellow}*you have unlimited tries.${end}"
	echo -e "${green}*if you guess the correct #, then you'll be congratulated.${end}"
	echo -e "${blue}*however, if you guess the wrong #, the robot will tell you if you're too low or too high.${end}"
	echo -e "${indigo}*good luck. :)${end}"
}

info(){
	echo -e "info.:\n"
	echo -e "author: ${blue}Badger Code${end}"
	echo -e "lines of code 2 make this: $(($(get_file_line_num "$0")+1))(excluding source files)."
	echo -e "dir.: ${yellow}$(get_current_path)/$(get_current_file_name)${end}."
	if ! is_file_exist $try_file;then echo -e "${red}you've yet to play the game, so you have no avg. try #.${end}"
	else echo -e "avg. try to get ans. correct: ${green}$(get_avg_try "$try_file")${end}."
	fi
	echo -e "current random #: ${red}${number}${end}."
}

welcome(){
	load

	clear

	echo -e "${green}[._.]: howdy there${end} ${blue}$(get_user)${end}${green}; welcome to the guessing game!${end}"
	echo -e "[._.]: type \"${orange}guess -h${end}\" in your terminal 4 help."
}

random(){
	echo -e "old random #: ${red}${number}${end}."
	get_random_num
	number=$?
	echo -e "new random #: ${blue}${number}${end}."
}

device(){
	echo -e "device info.:\n"
	echo -e "O.S.: ${red}$(get_os_type)${end}/${orange}$(get_os_type2)${end}."
	echo -e "I.P. address: ${yellow}$(get_ip)${end}."
}

error_invalid_input(){
	echo -e "${red}ERROR: INVALID INPUT!\n${end}"
	echo "possible issues:"
	echo "1. input wasn't an integer"
	echo "2. input was too low or too high"
}

check(){
	if [ "0$1" -lt $2 ];then echo -e "${red}[._.]: low.${end}"
	elif [ "0$1" -gt $2 ];then echo -e "${red}[._.]: high.${end}"
	elif [ "0$1" -eq $2 ];then echo -e "${green}[._.]: correct; it took you${end} ${blue}${try}${end} ${green}tries to get the ans.!${end}"
	else error_invalid_input
	fi
}

new_try_file(){
	local folder=$1
	local file=$2

	new_folder_if_not_exist $folder
	new_file_if_not_exist $file
}

set_try_file(){
	local folder=$1
	local file=$2
	local text=$3

	new_try_file $folder $file

	add_file_text $file "$text\n"
}

get_avg_try(){
	local file=$1

	local b1=''

	get_file_line $file b1
	
	echo $(get_avg ${b1[@]})
}

if is_key_word "-t";then echo "$(get_key_word_input "-t")";fi

set_key_word "-h" help
set_key_word "-a" about
set_key_word "-i" info
set_key_word "-w" welcome
set_key_word "-r" random
set_key_word "-d" device

set_error "run_time_error"

welcome

echo

while [ "0$guess" -ne $number ];do
	read -p "[._.]: guess a number between 1 and 100: " guess

	((try+=1))

	try {
		check $guess $number
	} catch {
		error_invalid_input
		break
	}
done

set_try_file $try_folder $try_file "$try"

exit 0
#add to path, so user can access from any path
#tell user where storing files
#fix get_ip
#add error handling: throw