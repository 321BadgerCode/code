#!/bin/bash
url=$1
ext=${url##*.}
# child directory
# url=${url##*/}
# parent directory
# url_prefix=${1%/*}

url=${url%.*}
page=${url:-1}
page=$((last_char))
url=${url%?}

while [ true ]; do
	wget -q -nc --show-progress -O $page.$ext $url$page.$ext
	echo $url$page.$ext
	page=$((page+1))
	chars_gone=${#page}
	url=${1%.*}
	for ((i=0;i<$chars_gone;i++));do
		url=${url%?}
	done
done