#badger
CC=g++

lib_path:=/home/badger/document/code/cpp/lib/rhino/include/
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