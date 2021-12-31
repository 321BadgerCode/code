//badger
#pragma once

#include ".\other_1.h"//other

void set_name(){
	cout<<n1.get_greeting()<<endl;

	while(true){
		string check="";
		cout<<n1.get_name()+" ";
		cin>>p1.info->name;
		n1.p->info->name=p1.info->name;
		cout<<n1.get_confirm_name()+" ";
		cin>>check;
		if(check=="y"){break;}
		else{system("cls");}
	}
	system("cls");
	cout<<n1.get_approve_name()<<endl;
	cout<<n1.get_greeting2()<<endl;
}

void set_villager(){
	for(int a=0;a<6;a++){
		cout<<to_string(a+1)+": "+total_villager[a].info->name<<endl;
	}

	while(true){
		cout<<"what villager do you want(input number)? ";
		string ans="";
		cin>>ans;
		v1=total_villager[stoi(ans)-1];
		cout<<"are you sure that you want your villager companion to be: "+v1.info->name+"(y,n)? ";
		string check="";
		cin>>check;
		if(check=="y"){break;}
		else{system("cls");}
	}
	system("cls");
	cout<<"ok, you're villager is: "+v1.info->name<<endl;
}

void set_pet(){
	for(int a=0;a<30;a++){
		cout<<to_string(a+1)+": "+pet[a]<<endl;
	}

	while(true){
		cout<<"what pet do you want(input number)? ";
		string ans="";
		cin>>ans;
		pet2.type=pet[stoi(ans)-1];
		cout<<"are you sure that you want your pet to be a "+pet2.type+"(y,n)? ";
		string check="";
		cin>>check;
		if(check=="y"){break;}
		else{system("cls");}
	}
	while(true){
		cout<<"name of pet: ";
		string name="";
		cin>>name;
		pet2.info->name=name;
		cout<<"are you sure that you want your pet's name to be: "+pet2.info->name+"(y,n)? ";
		string check2="";
		cin>>check2;
		if(check2=="y"){break;}
		else{system("cls");}
	}
	system("cls");
	cout<<"ok, you're pet "+pet2.type+"'s name is \""+pet2.info->name+"\""<<endl;
}

void setup(){
	set_name();
	set_villager();
	set_pet();
}