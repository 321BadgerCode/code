//badger
#pragma once

void fight(){
	unsigned int enemy_num=get_random(0,3);
	enemy* e=&total_enemy[enemy_num];
	cout<<n1.set_say("you've encountered a "+e->info->name+".")<<endl;

	while(p1.info->health>0&&e->info->health>0){
		cout<<"1: attack\n2: defend"<<endl;
		string choice="";
		option o=option::none;
		while(true){
			cout<<n1.set_say("what would you like to do? ");
			cin>>choice;
			if(choice=="1"){o=option::attack;break;}
			else if(choice=="2"){o=option::defend;break;}
			else{cout<<n1.set_say("you did not input a valid option.")<<endl;}
		}
		switch(o){
			case(option::attack):
				cout<<n1.set_say("you attack the "+e->info->name+".")<<endl;
				p1.set_attack(*e);
				cout<<e->get_info()<<endl;
				break;
			case(option::defend):
				cout<<n1.set_say("you defend yourself.")<<endl;
				p1.set_defend();
				cout<<p1.get_info()<<endl;
				break;
		}
		unsigned int enemy_choice=get_random(0,1);
		if(enemy_choice==0){
			cout<<n1.set_say("the "+e->info->name+" attacks you.")<<endl;
			e->set_attack(p1);
			cout<<p1.get_info()<<endl;
		}
		else{
			cout<<n1.set_say("the "+e->info->name+" defends itself.")<<endl;
			e->set_defend();
			cout<<e->get_info()<<endl;
		}
	}
	if(p1.info->health<=0){cout<<set_color(red2,"you have died.")<<endl;}
	else if(e->info->health<=0){cout<<set_color(green2,"you have defeated the "+e->info->name+"! congratulations :)")<<endl;p1.info->health+=e->info->attack;}
}