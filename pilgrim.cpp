#include "pilgrim.h"

Pilgrim::Pilgrim()
{
    hp = 10;
    maxhp = 10;

    kills = 0;
    turkeys = 0;

    musket.ammo = 0;
    musket.canHaveBayonet = true;
    musket.damage = 10;
    musket.hasbayonet = false;
    musket.have = false;

    flintlock.ammo = 0;
    flintlock.canHaveBayonet = false;
    flintlock.damage = 8;
    flintlock.hasbayonet = false;
    flintlock.have = false;

    knife.have = false;
    knife.damage = 2;
    knife.numberOfAttacks = 2;

    hatchet.have = false;
    hatchet.damage = 6;
    hatchet.numberOfAttacks = 1;

    bayonet.have = false;
    bayonet.damage = 2;
    bayonet.numberOfAttacks = 1;
}

Pilgrim::~Pilgrim(){}

void Pilgrim::findKnife(){
    knife.have = true;
}

void Pilgrim::findHatchet(){
    hatchet.have = true;
}

void Pilgrim::findBayonet(){

}

void Pilgrim::findMusket(){
    bayonet.have = true;
    if(musket.have)
        musket.hasbayonet = true;
}

void Pilgrim::findFlintlock(){
    flintlock.have = true;
}


