#!/bin/bash
function get_file_name(){
	echo "./" | echo $1 | sed -r 's/[^a-zA-Z0-9]+/_/g' | sed -r 's/^_//g' | sed -r 's/_$//g' | tr '[:upper:]' '[:lower:]'
}
function align(){
	echo $1 | sed -r 's/=/\&=/g'
}

cat << "EOF"
  _         _____   __  __
 | |    __ |_   _|__\ \/ /
 | |   / _` || |/ _ \\  /
 | |__| (_| || |  __//  \
 |_____\__,_||_|\___/_/\_\
EOF

echo "* Example: 2x^2+3x+1=0"
echo "* Example: \frac{1}{2}x^2+3x+1=0"
read -p "Enter the math equation (in LaTeX code): " equation
echo -e "\n* Example: Output svg image scale: 100"
echo -e "\n* Example: Output svg image scale: 100,100"
read -p "Output svg image scale: " output_scale
equation=$(align $equation)
file_name=$(get_file_name $equation)
file_tex=$file_name.tex
file_dvi=$file_name.dvi

default_time_out=5

echo "\\documentclass[12pt]{article}
\\usepackage{amsmath}
\\usepackage{amssymb}
\\usepackage{amsfonts}
\\usepackage{tikz}
\\usepackage{pgfplots}
\\usepackage{tikz-3dplot}
\\usepackage{tkz-euclide}

\\begin{document}
\\begin{align*}
	$equation
\\end{align*}
\\end{document}" > $file_tex

timeout $default_time_out latex -no-shell-escape -interaction=nonstopmode -halt-on-error $file_tex
timeout $default_time_out dvisvgm --no-fonts --clipjoin --scale=${output_scale} $file_dvi