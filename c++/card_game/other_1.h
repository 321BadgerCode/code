//badger
#pragma once

using namespace std;

#define get_string(a1) # a1

enum class option{none,attack,defend};

struct stat1{string name;int health;int attack;};

unsigned int get_random(unsigned int min,unsigned int max){
	srand(time(NULL));
	unsigned int r=rand()%(max-min+1)+min;
	return r;
}

template<typename a> int get_length(a a1[]){
	return sizeof(a1);
}

string get_list(character a1[]){
	string b1="";

	for(int a=0;a<get_length(a1);a++){
		b1+=a1[a].info->name+"\n";
	}

	return b1;
}

const string black2="\x1B[30m";
const string red2="\x1B[31m";
const string green2="\x1B[32m";
const string yellow2="\x1B[33m";
const string dark_blue2="\x1B[34m";
const string purple2="\x1B[35m";
const string blue2="\x1B[36m";
const string white2="\x1B[37m";
const string end2="\033[0m";

string set_color(string color,string text){string b1=color+text+end2;return b1;}