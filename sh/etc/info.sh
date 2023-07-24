#badger
get_current_path(){
	echo "$PWD"
}

get_prev_path(){
	echo "$OLDPWD"
}

get_current_file_name(){
	echo "${0##*/}"
}