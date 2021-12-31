//badger
#pragma once

#include ".\character_1.h"//character

player p1("player",100,25);

narrator n1("narrator",yellow2,p1);

enemy fuzzball("fuzzball",10,5);
enemy spiky("spiky",25,10);
enemy glooper("glooper",50,25);
enemy slimy("slimy",100,50);
enemy slimester("slimester",125,75);
enemy whiplash("whiplash",150,75);
enemy angry_taco("angry_taco",200,100);
enemy easy_enemy[4]={fuzzball,spiky,glooper,slimy};
enemy medium_enemy[2]={slimester,whiplash};
enemy hard_enemy[1]={angry_taco};
enemy total_enemy[4]={fuzzball,spiky,glooper,slimy};

boss goofball("goofball",100,100);
boss xublat("xublat",200,200);
boss zugblar("zugblar",300,300);
boss easy_boss[1]={goofball};
boss medium_boss[1]={xublat};
boss hard_boss[1]={zugblar};
boss total_boss[1]={goofball};

villager v1("villager",100,100);
villager todd("todd",100,100);
villager jim("jim",100,100);
villager john("john",100,100);
villager billy("billy",100,100);
villager bob("bob",100,100);
villager micheal("micheal",100,100);
villager total_villager[6]={todd,jim,john,billy,bob,micheal};

pet1 pet2("pet",100,10);