#badger
set_file_text(){
	local file=$1
	local text=${2:-''}

	echo -n -e $text > $file
}

#set_file_text2(){
#	local file=$1
#	local text=${2:-''}
#
#	cat > $file <<EOF
#	{
#		"contact": {
#			"name": "xyz",
#			"phone_num": "xxx-xxx-xxxx"
#		}
#	}
#EOF
#}

#get_file_text(){
#	local file=$1
#
#	echo -e $(cat $file)
#}

add_file_text(){
	local file=$1
	local text=${2:-''}

	echo -n -e $text >> $file
}

is_file_exist(){
	local file=$1

	[ -f $file ] && [ -e $file ]
}

set_file_permission(){
	local file=$1

	chmod u+x $file
}

delete_file(){
	local file=$1

	rm $file
}

new_file_if_not_exist(){
	local file=$1
	local text=${2:-''}

	test -e $file || echo -n -e $text > $file
}

add_file_to_file(){
	local file=$1
	local file2=$2
	
	cat $file >> $file2
}

get_file_line_num(){
	local file=$1

	local b1=()

	mapfile -t b1 < $file

	echo "$((${#b1[@]}-1))"
}

get_file_line(){
	local file=$1
	local var=$2

	mapfile -t $var < $file
}

get_file_line2(){
	local file=$1
	local index=$2

	local b1=()

	mapfile -t b1 < $file

	echo "${b1[$index]}"
}

set_file_line(){
	local file="$1"
	local line_num="$2"
	local replace="$3"

	sed -i "$((line_num+1)) c \\${replace}" "$file"
}

is_folder_exist(){
	local folder=$1

	[ -d $folder ]
}

new_folder(){
	local folder=$1

	mkdir -p $folder
}

new_folder_if_not_exist(){
	local folder=$1

	if [ ! -d $folder ];then mkdir -p $folder
	fi
}

get_file_from_dir(){
	local dir=$1

	echo "${dir##*/}"
}

get_file_name_from_file(){
	local file=$1

	echo "${file%.*}"
}

get_file_extension_from_file(){
	local file=$1

	echo "${file##*.}"
}