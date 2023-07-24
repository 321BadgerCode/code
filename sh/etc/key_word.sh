#badger
a1=$1
a2=$@

set_key_word(){
	local key_word="$1"
	local func=$2

	if [ "$a1" == "$key_word" ];then $func && exit
	fi
}

is_key_word(){
	local key_word="$1"

	[[ "$a2" =~ "$key_word" ]]
}

get_key_word_input(){
	local key_word="$1"

	local b1=''
	local b2=''

	if [[ "$a2" =~ "$key_word " ]];then
		b1="${a2##*${key_word} }"
		b2="${b1% *}"
	fi

	echo "$b2"
}