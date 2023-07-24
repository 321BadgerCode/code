#badger
black="\033[0;30m"
red="\033[0;31m"
orange="\033[0;33m"
yellow="\033[1;33m"
green="\033[1;32m"
blue="\033[1;34m"
indigo="\033[0;35m"
violet="\033[1;35m"
white="\033[1;37m"

black2="30"
red2="31"
green2="32"
yellow2="33"
dark_blue2="34"
purple2="35"
light_blue2="36"
white2="37"

normal='0'
light='1'
dark='2'
italic='3'
underline='4'
blink='5'
highlight='7'
strike_through='9'

begin="\033["
end="\033[0m"

set_color(){
	local text=$1
	local color=${2:-${white}}
	local type=${3:-${normal}}

	echo -e "${begin}${type};${color}m${text}${end}"
}

black3=(0 0 0)
red3=(255 0 0)
orange3=(255 125 0)
yellow3=(255 255 0)
green3=(0 255 0)
blue3=(0 0 255)
indigo3=(50 0 125)
violet3=(255 125 255)
white3=(255 255 255)

set_ansi(){ echo -e "\e[${1}m${*:2}\e[0m"; }
set_bold(){ set_ansi 1 "$@"; }
set_dim(){ set_ansi 2 "$@"; }
set_italic(){ set_ansi 3 "$@"; }
set_underline(){ set_ansi 4 "$@"; }
set_blink(){ set_ansi 5 "$@"; }
set_invisible(){ set_ansi 8 "$@"; }
set_strike_through(){ set_ansi 9 "$@"; }
set_underline2(){ set_ansi 21 "$@"; }
set_overline(){ set_ansi 53 "$@"; }

set_fg_color(){
	local text=$1
	local color=${2:-${white[@]}}

	echo -e "\e[38;2;${color[0]};${color[1]};${color[2]}m${text}\e[0m"
}
set_bg_color(){
	local text=$1
	local color=${2:-${black[@]}}

	echo -e "\e[48;2;${color[0]};${color[1]};${color[2]}m${text}\e[0m"
}