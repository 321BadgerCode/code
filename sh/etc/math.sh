#badger
get_random_num(){
	local min=${1:-1}
	local max=${2:-100}
	
	local num=$((($RANDOM%$max)+$min))

	return $num
}

get_int(){
	echo ${$1%.*}
}

get_sum(){
	local array=("$@") total=${#array[@]} sum=0

	for (( a=0; a<$total; a++ ));do
		((sum+=${array[$a]}))
	done

	echo "$sum"
}

get_avg(){
	local array=("$@") total=${#array[@]} sum=0

	for (( a=0; a<$total; a++ ));do
		((sum+=${array[$a]}))
	done

	echo "$(($sum/$total))"
}