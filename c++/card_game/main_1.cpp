//badger
#include <iostream>//basic
#include <windows.h>//title
#include <time.h>//time
#include ".\asset_1.h"//asset
#include ".\character_1.h"//character
#include ".\fight_1.h"//fight
#include ".\other_1.h"//other
#include ".\setup_1.h"//setup

using namespace std;

int main(){
	SetConsoleTitle("CARD_GAME!");

	//memcpy(total_enemy,easy_enemy,sizeof(total_enemy));
	//copy(begin(easy_enemy),end(easy_enemy),begin(total_enemy));
	//memmove(total_enemy,easy_enemy,sizeof(total_enemy));

	system("color 07");

	cout<<set_color(green2,"welcome to \"card_game\"!")<<endl;

	setup();

	fight();

	//enemy* total_enemy=new enemy[6];
	/*cout<<get_length(total_enemy)<<endl;
	cout<<get_length(medium_enemy)<<endl;
	cout<<get_length(hard_enemy)<<endl;
	//for(int a=0;a<get_length(medium_enemy);a++){total_enemy[a]=medium_enemy[a];}
	//copy(begin(medium_enemy),end(medium_enemy),begin(total_enemy));
	//for(int a=0;a<get_length(total_enemy);a++){cout<<total_enemy[a].info->name<<endl;}*/

	cout<<set_color(green2,"goodbye!")<<endl;
	cout<<set_color(green2,"thank you for playing \"card_game\"!")<<endl;

	system("pause");

	return 0;
}
//add text change
//unsigned short val = ((r<<8) & 0xf800) | ((g<<3) & 0x07e0) | (b>>3);