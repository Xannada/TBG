#include "encounter.h"

Encounter::Encounter()
{name = ""; attackDesc = ""; hp = 1; damage = 0;}

Encounter::~Encounter(){}

void Encounter::set(QString n, QString s, int h, int d){
    name = n; attackDesc = s; hp = h; damage = d;
}

bool Encounter::takeDamage(int dmg){
    hp -= dmg;
    return hp > 0;
}

int Encounter::attack(){
    return damage;
}

QString Encounter::getName(){
    return name;
}

QString Encounter::atkDes(){
    return attackDesc;
}
