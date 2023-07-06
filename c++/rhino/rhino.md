<!--badger-->
<style>
	body{
		background: radial-gradient(#8a8a8a,#505050);
	}
</style>

# rhino

## summary
---
* `rhino` is a <abbr title="library">lib.</abbr> written in c++ 4 linux <abbr title="operating system">O.S.</abbr>.
* the <abbr title="manual">man.</abbr> page 4 the `rhino` lib. can be accessed by typing "`man rhino`" in the linux terminal/<abbr title="console">con.</abbr>.
* type "`rhino -h`" 2 get help on how to use the rhino lib. & type "`rhino`" 2 get more <abbr title="information">info.</abbr> on the lib..

## author
---
<img src="./recource/badger.jpg" title="profile pic." width="50"/>

social media:
* [Github profile](https://github.com/321BadgerCode/).

## capability
---
* define
* etc
* file
* math
* secure
* system
* type
* ui
* window

## usage
---
><abbr title="you">u</abbr> can delete `using namespace rhino;` 2, but then you'd have 2 specify `rhino::` <abbr title="before">b4</abbr> it's members.  
this is an <abbr title="example">ex.</abbr> of a program written in c++ using the `rhino` lib.:
```
//badger
#include <rhino/system/main.h>

using namespace rhino;

int main(){
	console con("SYSTEM!");

	con.print(color::get_ui(color::get_ui(color::get_ui("SYSTEM!",color::type::fg,color::blue),color::type::under_line),color::type::over_line));
	console::print("");

	console::print("[._.]: "+info::device::get_os(info::device::get_os())+" con. type: "+console::get_type());

	$S a1=console::get_input(new console::text{.a="[._.]: how are you doing today? ",.fg=color::red});

	console::print("[._.]: you inputted: \""+a1+"\"");

	console::pause();

	console::clear();

	return 0;
}
```
`rhino` also supports graphics(using the S.F.M.L. lib.), so u can make games & such.
however, if u use graphics, u have 2 compile the code w/ S.F.M.L. lib. linked(as shown in makeFile down below in <a href="## make">make</a>).
>ex. of `rhino` graphics:
```
//badger
#include <rhino/window/main.h>

using namespace rhino;

int main(){
	window* w1=new window("WINDOW!");

	rectangle* r1=new rectangle();
	circle* c1=new circle(color::blue,100,rhino::vector<>(100,100));

	while(w1->isOpen()){
		sf::Event e1;

		while(w1->pollEvent(e1)){
			if(e1.type==sf::Event::Closed){w1->close();}
		}

		w1->clear();

		w1->draw(r1->get());
		w1->draw(c1->get());

		w1->display();
	}

	return 0;
}
```

## make
---
<abbr title="variable">var.</abbr> 2 change 4 use:

* lib_path.
* name.

>ex. of a make(.mak) file 4 compiling & running a program using the `rhino` lib.:
```
#badger
CC=g++

lib_path:=/home/badger_code/document/code/cpp/lib/rhino/include/
path=/usr/local/bin/
man_path:=/usr/share/man/man1/

man=test.1

name:=test
file:=./$(name).cpp
out:=./$(name).exe

default:compile run

compile:$(file)
	$(CC) $(file) -o $(out) -I $(lib_path)

sfml:
	$(CC) $(file) -o $(out) -I $(lib_path) -lsfml-graphics -lsfml-window -lsfml-system
	$(MAKE) run

run:
	$(out)

clean:
	rm $(out)

path:
	cp $(out) $(path)$(name)

man:
	cp $(man) $(man_path)$(man)
	gzip $(man_path)$(man)
```

## file
---
file	|	description			|	path
:---	|	:---:				|	---:
man.	|	type "`man rhino`"		|	/usr/share/man/man1/rhino.1.gz
app.	|	type "`rhino -h`"		|	/usr/local/bin/rhino

## color
---
`rhino` uses a 4-bit, 8-bit, & 24-bit <abbr title="color">clr.</abbr> <abbr title="system">sys.</abbr> as shown in this table:

<div class="color">

|				|	intensity		|	blue		|	green		|	red		|
|	:---:			|	:---:			|	:---:		|	:---:		|	:---:		|
|	abbreviation		|	I			|	B		|	G		|	R		|
|	bits			|	8			|	4		|	2		|	1		|
|	bin.(4-bit)		|	0b1000			|	0b0100		|	0b0010		|	0b0001		|
|	dec.(8-bit)		|	8			|	12		|	10		|	196		|
|	hex.(24-bit)		|	0x8			|	0x0000ff	|	0x00ff00	|	0xff0000	|

</div>

<style>
	.color table{background:grey;}

	.color th{opacity:75%;}

	.color td:nth-child(3){color:blue;}
	.color td:nth-child(4){color:green;}
	.color td:nth-child(5){color:red;}
</style>