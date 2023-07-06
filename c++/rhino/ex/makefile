#badger
CC=g++
MAKE=make -f ./makefile

lib_path:=/home/badger/document/code/cpp/lib/rhino/include/

name:=clr
file:=./$(name).cpp
out:=./$(name).exe

default:compile run

compile:$(file)
	$(CC) $(file) -o $(out) -w -I $(lib_path)

run:
	$(out)

clean:
	rm $(out)