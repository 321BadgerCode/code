#badger
load(){
	local text=${1:-"loading..."}
	local percent=${2:-100}
	local wait_time=${3:-.01}
	local is_percent_max=${4:-true}
	local char=${5:-'.'}
	local border=${6:-'|'}
	local border2=${7:-'|'}

	local b1=80 b2=0 b3=0;shift

	for (( a=1; a<=$percent; a++ ));do
		b2="$a"

		if [ "$is_percent_max" = false ];then b3=100
		else b3=$percent
		fi

		printf -v dot "%*s" "$(( $b1*$b2/$b3 ))" "";dot=${dot// /$char}
		printf "\r\e[K${border}%-*s${border2} %3d%% %s" "$b1" "$dot" "$b2" "$text"

		sleep $wait_time
	done;echo
}