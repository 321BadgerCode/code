#badger
CC=g++
MAKE=make -f ./test.mak

lib_path:=/home/badger/document/code/cpp/lib/rhino/include/

name:=type
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

all:compile run