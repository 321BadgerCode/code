#badger
. /home/badger_code/document/code/sh/etc/color.sh
. /home/badger_code/document/code/sh/etc/device.sh
. /home/badger_code/document/code/sh/etc/info.sh
. /home/badger_code/document/code/sh/etc/key_word.sh
. /home/badger_code/document/code/sh/etc/load_bar.sh

help(){
cat <<EOF
                   .^~~^..             .::.
          .~JPBBBGB#@@@@##G5J7~~~!7J5GB#&&#BP?^.				|	help:
      .^75#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BY?77^				|
     7B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G!				|	usage: rhino.
    !@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y    ..^^		|	syntax: rhino -[h|a|i|w].
   ~&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&^~5B#&@?		|
  :&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@!		|	option:
  7@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#5?^			|		h:	help.
  J@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P			|		a:	about.
  J@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P			|		i:	info.
  5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@!			|		w:	welcome.
^BG5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.			|
!J..G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5J?.       ~:	|
   ^&@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@?     :?BG.	|
    B@@@@@@@B^..^?G&@@@@@@@@@#&@@@@@@@@@@@@@#P@@@@@@@@@@@@@@&Y?7?YG&@P.		|
   7@@@@@@@@G      :^^~~~!~^^.~@@@@@@@@@@@@B. ?&@@@@@@@@@@@@@@@@@@@B!		|
   G@@@@@@@@P                  B@@@@@@@@@@G:   ^Y#&@@@@@@@@@@@@@#P7.		|
   5@@@@@@@@@5:                5@@@@@@@@@G       .^?B@@@@@@@@@@@5		|
   :~77&@@@@@@#:               7@@@@@@@@@Y          .#@@@@@@@@@#~		|
      :5GGGBG57:               5@@@@@@@@@#?7.        ~G#@@@@&#G:		|
                              7@@@@@@@@@BGPY^          .^~~^..			|
                              !PGBPBB57~.					|
EOF
}
about(){
	echo -e "about:\n"
	echo -e "${red}* rhino is a lib. written in c++ made 4 linux O.S..${end}"
}
info(){
	echo -e "info.:\n"
	echo -e "author: ${blue}Badger Code${end}"
	echo -e "date created: ${orange}2022/8/19${end}"
	echo -e "version: ${green}1${end}"
	echo -e "dir.: ${yellow}$(get_current_path)/$(get_current_file_name)${end}."
}
welcome(){
	load

	clear

	echo -e "${blue}$(base64 -d <<<"H4sICB4aAGMCA3JoaW5vLnR4dAClVDuOxSAM7HOKIEuUdMgSDZEbS1S0aXwUn32B/JO3+xR2miiE
mQzY43F8wImqOHddC8ENp1dNmYiYYCoAYJ9QVQ0mX9asBcpRNoIT9G3fN9AcEWVhIU2vwKbxzPQa
c/PopP1Y7XsBK+rLoadYBEIHv1zg8qhHwKkT4GM9Qerl5/+SfS/ZDELcyQY3mOQcd5GtT3Frcw21
/HKUD+CVVmwqIRIvbb+1L5UkSeST7rVDIN88lQzEuezPTWdvB15sBpGaMxVxeomOG+On1qMWi/16
8jPtp5xxqFcwPxxis3JUyIe7yPGN9yESzwn2VSEo4qoNdwm85nEVOWoAuk6T4Jm59AuGXz1AxH16
KTcNCxyG8U8cDojzLI95+IVuMlOZiR7V/QBp9ZRZVAUAAA==" | gunzip)${end}\n"

	echo -e "${green}[._.]: howdy there${end} ${blue}$(get_user)${end}${green}; welcome to the rhino lib.!${end}"
	echo -e "[._.]: type \"${orange}rhino -h${end}\" in your terminal 4 help."
}

set_key_word "-h" help
set_key_word "-a" about
set_key_word "-i" info
set_key_word "-w" welcome

welcome