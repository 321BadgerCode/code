#!/bin/bash
#badger
. ./etc/color.sh
. ./etc/device.sh
. ./etc/error.sh
. ./etc/file.sh
. ./etc/info.sh
. ./etc/key_word.sh
. ./etc/load_bar.sh

help(){
	echo -e "help:\n"
	echo -e "usage: compile '${blue}file dir. 2 be compiled${end}' [-o: out file] [-v||--verbose] [-q question]."
	echo -e "syntax: compile -[h|a|i|n|w|i2] || --[help|about|info|need|welcome|install].\n"
	echo "option:"
	echo -e "${red}o:\tout/compiled(.exe) file${end}"
	echo -e "${orange}v:\tinform user of actions"
	echo -e "${yellow}q:\tquestions at end 4 more options\n"
	echo -e "${red}h:\thelp.${end}"
	echo -e "${orange}a:\tabout.${end}"
	echo -e "${yellow}i:\tinfo.${end}"
	echo -e "${green}n:\tneed these programs installed, so they can be utilized by this program.${end}"
	echo -e "${blue}w:\twelcome.${end}"
	echo -e "${indigo}i2:\tinstall programs needed by this program.${end}"
}
about(){
	echo -e "about:\n"
	echo -e "${red}*${end}'compile' compiles a given bash(.sh) file into a stand-alone executable(binary) using 'shc'(.sh->.c) and 'gcc'(.c->bin.).${end}"
}
info(){
	echo -e "info.:\n"
	echo -e "author: ${blue}Badger Code${end}"
	echo -e "dir.: ${yellow}$(get_current_dir)/$(get_name_current_file)${end}"
}
need(){
	echo -e "need 4 program 2 work on your $(get_os_type)($(get_os_type2)) O.S.:\n"
	echo -e "'compile' needs the following programs installed(dependencies):"
	echo -e "1. ${red}shc${end}"
	echo -e "2. ${orange}gcc${end}"
	echo -e "\ntype '${green}compile -i2${end}' or '${green}compile --install${end}' 2 install the necessary components."
}
welcome(){
	load "computing..." 100 .001 true '#'

	clear

	echo -e "${green}[._.]:${end} ${blue}$(get_user)${end}${green}, welcome to the compiling program!${end}\n"
}
install(){
	try {
		sudo apt-get install gcc
	} catch {
		echo -e "${red}ERROR: [-.-]:${end} ${orange}GCC${end} ${red}HAD TROUBLE INSTALLING!${end}"
		exit 1
	}

	try {
		sudo add-apt-repository ppa:neurobin/ppa
		sudo apt-get update
		sudo apt-get install shc
	} catch {
		echo -e "${red}ERROR: [O_O]:${end} ${orange}SHC${end} ${red}HAD TROUBLE INSTALLING!${end}"
		exit 1
	}
}
compile(){
	local input_file2=$1
	local file22=$2
	local out_file2=$3

	shc -f $file22 -o $out_file2 2>/dev/null

	load "compiling..."

	echo -e "${green}[._.]:${end} ${blue}${input_file2}${end} ${green}is compiled;${end} ${blue}${input_file2}${end}${green}=>${end}${orange}${out_file2}${end}"
}

set_key_word "-h" help
set_key_word "-a" about
set_key_word "-i" info
set_key_word "-n" need
set_key_word "-w" welcome
set_key_word "-i2" install

set_key_word "--help" help
set_key_word "--about" about
set_key_word "--info" info
set_key_word "--need" need
set_key_word "--welcome" welcome
set_key_word "--install" install

set_error "run_time_error"

welcome

input_file=$1
out_file=$(get_key_word_input "-o")

a1=$(get_file_from_dir "$input_file")
file2="$(get_file_name_from_file "$a1")_tmp.sh"

if [ "$out_file" == '' ];then
	out_file="./$(get_file_name_from_file $a1).exe"
fi

if ! is_file_exist $input_file;then
	echo -e "*${red}[._.]:${end} '${yellow}${input_file}${end}' ${red} doesn't exist!${end}"
	echo "*check the file that u specified after running the 'compile' command to make sure that it is set and correct."
	echo "*try running 'compile -h' in your terminal 4 more info on the usage of this program."
	exit
fi

if [ $(get_file_extension_from_file "$input_file") != "sh" ];then
	echo -e "*${red}[._.]:${end} '${yellow}${input_file}${end}' ${red}is not a bash file!${end}"
	echo "*check the file that u specified after running the 'compile' command to make sure that it is set and correct."
	echo "*try running 'compile -h' in your terminal 4 more info on the usage of this program."
	exit
fi

if ! is_file_exist $file2;then set_file_text $file2 "#!/bin/bash\n\n"
else
	echo -e "${red}[._.]:${end} '${yellow}${file2}${end}' ${red}already exists!${end}"
	read -r -p "do you want to over-write it? [y/n] " over_write
	clear

	if [ "$over_write" = 'y' ];then
		set_file_text $file2 "#!/bin/bash\n\n"
	else
		echo -e "${green}[._.]:${end} '${blue}${file2}${end}' ${green}is not over-written!${end}"

		read -n 1 -r -p "compile existing file(y/n)? " compile_exist

		if [ "$compile_exist" = 'y' ];then compile "$input_file" "$file2" "$out_file";fi

		exit
	fi
fi

source_file=("$input_file")

for (( a=0; a<${#source_file[@]}; a++ ));do
	get_file_line "${source_file[$a]}" source_line

	for (( b=0; b<${#source_line[@]}; b++ ));do
		if [[ "${source_line[$b]}" =~ ^\.\s* ]];then
			source_file+=($(echo "${source_line[$b]}" | sed "s/^\.\s*//"))
		#elif [[ $line =~ ^source\s* ]];then
			#source_file+=($(echo $line | sed "s/^\source\s*//"))
		fi
	done
done

echo -e "[._.]: ${blue}${input_file}${end} is being compiled 2 ${green}${out_file}${end}...\n"
echo "[._.]: the following files will be included in the compiled file:"
for (( a=0; a<${#source_file[@]}; a++ ));do
	echo -n -e "$(set_color "$((a+1))" "${red2}" "${light}").\t"

	if [ $a == 0 ];then echo "$(set_blink $(set_overline $(set_underline $(set_italic "${green}${source_file[$a]}${end}"))))"
	else echo -e "${green}${source_file[$a]}${end}";fi
done

for (( a=$((${#source_file[@]}-1)); a>=1; a-- ));do
	file="${source_file[$a]}"

	if ! is_file_exist $file;then
		echo -e "*${red}[._.]:${end} '${yellow}${file}${end}' ${red}doesn't exist!${end}"
		echo "*check the file that u specified in your script and make sure that it is correct."
		echo -e "*a possible issue could be that this program cannot access the source file because u used \"./\" 4 the source file in your script and this program is not located in the local dir.."
		echo "*try running 'compile -h' in your terminal 4 more info. on the usage of this program."
		exit
	elif [ $(get_file_extension_from_file "$file") != "sh" ];then
		echo -e "*${red}[._.]:${end} '${yellow}${file}${end}' ${red}is not a bash file!${end}"
		echo "*check the file that u specified in your script and make sure that it is correct."
		echo "*try running 'compile -h' in your terminal 4 more info. on the usage of this program."
		exit
	fi

	add_file_text $file2 "#####\n#[._.]: ${file}(source file):\n#####\n\n"
	add_file_to_file $file $file2
	add_file_text $file2 "\n\n"
done

add_file_text $file2 "#####\n#[O-O]: ${input_file}(main/input file):\n#####\n\n"
add_file_to_file $input_file $file2

all_line=();get_file_line $file2 all_line

for (( a=0; a<${#all_line[@]}; a++ ));do
	if [[ ${all_line[$a]} =~ ^\.\s* ]];then
		set_file_line $file2 $a "#${all_line[$a]} #[._.]: this line has been edited(commented out) by ./compile.sh."
		
		if is_key_word "-v" || is_key_word "--verbose";then
			echo -e "\n${blue}${file2}${end}(line ${red}$((a+1))${end}):"
			echo -e "\"${yellow}${all_line[$a]}${end}\""
			echo -e "\t${yellow}-${end}${orange}>${end}"
			echo -e "\"${orange}$(get_file_line2 $file2 $a)${end}\""
		fi
	fi
done

if is_key_word "-q";then
	read -n 1 -r -p "change text in file that contain old file name(y/n)? " change_name
	echo

	if [ "$change_name" = "y" ];then
		sed -i "s|${input_file}|${out_file}|g" "$file2"
	fi

	read -n 1 -r -p "change text in file, so \"source\"->'.'(y/n)? " change_source
	echo

	if [ "$change_source" = "y" ];then
		sed -i "s/source /. /g" "$file2"
	fi
fi

compile "$input_file" "$file2" "$out_file"

read -n 1 -r -p "delete temporary(tmp) file(${file2}) && .c file(${file2}.x.c)(y/n)? " delete_tmp
echo

if [ "$delete_tmp" = "y" ];then
	delete_file $file2
	delete_file $file2.x.c
fi

if is_key_word "-q";then
	read -n 1 -r -p "run compiled file(y/n)? " run_file
	echo

	if [ "$run_file" = "y" ];then
		./$out_file
	fi
fi
#make more stuff->func.
#get_file_line $file2: make so don't need var. input 2 set