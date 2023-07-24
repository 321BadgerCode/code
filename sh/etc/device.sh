#badger
get_os_type(){
	echo $(uname)
}

get_os_type2(){
	echo "$OSTYPE"
}

get_user(){
	echo "$USER"
}

get_ip(){
	ifconfig eth0 | grep "inet " | cut -c 14-26

	echo "$?"
}