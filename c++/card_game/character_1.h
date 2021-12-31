//badger
#pragma once

#include ".\other_1.h"//other

using namespace std;

/*enum pet{none,cat,dog,bird,fish,mouse,turtle,snake,lizard,horse,cow,pig,sheep,chicken,squirrel,rabbit,deer,wolf,bear,panda,tiger,lion,elephant,giraffe,rhino,monkey,penguin,dolphin,whale,shark,octopus};
const char* pet3[]={
	get_string(cat),
	get_string(dog),
	get_string(pig),
	get_string(rabbit),
	get_string(snake),
	get_string(turtle)
};
for(int a=0;a<30;a++){
	cout<<to_string(a+1)+": "+pet3[a]<<endl;
}

string ans="";
cout<<"what pet do you want? ";
cin>>ans;
cout<<pet3[(stoi(ans)-1)]<<endl;
cout<<(pet)(stoi(ans)-1)<<endl;*/
const string pet[]={"cat","dog","bird","fish","mouse","turtle","snake","lizard","horse","cow","pig","sheep","chicken","squirrel","rabbit","deer","wolf","bear","panda","tiger","lion","elephant","giraffe","rhino","monkey","penguin","dolphin","whale","shark","octopus"};

class character{
private:
	string color;
public:
	stat1* info;
	character(const string color1,stat1* info1){color=color1;info=info1;}
	string get_info(){
		return set_color(color,"name: "+info->name+"\n"+
		"health: "+to_string(info->health)+"\n"+
		"attack: "+to_string(info->attack));
	}
	void set_attack(character& ch1){ch1.info->health-=info->attack;}
	void set_defend(){info->health+=info->attack;}
};

class player:public character{
public:
	player(string name1,int health1,int attack1):character(blue2,new stat1{name1,health1,attack1}){}
};

class enemy:public character{
public:
	enemy(string name1,int health1,int attack1):character(red2,new stat1{name1,health1,attack1}){}
	enemy():character(red2,new stat1{"",0,0}){}
};

class boss:public character{
public:
	boss(string name1,int health1,int attack1):character(purple2,new stat1{name1,health1,attack1}){}
};

class villager:public character{
public:
	villager(string name1,int health1,int attack1):character(green2,new stat1{name1,health1,attack1}){}
};

class pet1:public character{
public:
	string type="";
	pet1(string name1,int health1,int attack1):character(green2,new stat1{name1,health1,attack1}){}
};

class narrator{
public:
	string name="";
	string color="";
	player* p;
	narrator(const string name1,const string color1,player& player1){name=name1;color=color1;p=new player(player1.info->name,player1.info->health,player1.info->attack);}
	string set_say(const string a1){return set_color(color,name+": "+a1);}
	string get_greeting(){return set_say("hello, "+p->info->name+".");}
	string get_greeting2(){return set_say("howdy there, "+p->info->name+"!");}
	string get_name(){return set_say("what would you like your name to be "+p->info->name+"?");}
	string get_confirm_name(){return set_say("are you sure that you want your name to be: "+p->info->name+"(y,n)?");}
	string get_approve_name(){return set_say("ok, your new name is: "+p->info->name+".");}
};