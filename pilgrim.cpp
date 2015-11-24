#include "pilgrim.h"

Pilgrim::Pilgrim()
{
    //life
    hp = 10;
    maxhp = 10;

    //score base
    kills = 0;
    turkeys = 0;
    indians = 0;
    bears = 0;

    //weapons
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

    bayonet.have = true;
    bayonet.damage = 2;
    bayonet.numberOfAttacks = 1;

    //bonuses
    bonusAttacks = 0;
    accuracyBonus = 1;
}

Pilgrim::~Pilgrim(){}

/*********************************************************************************
 *
 * Life methods
 *
**********************************************************************************/

int Pilgrim::getHpBar(){
    return int((float(hp)/maxhp)*100);
}

QString Pilgrim::health(){
    QString s;
    return s.setNum(hp) + "/" + s.setNum(maxhp);
}

int Pilgrim::getHp(){
    return hp;
}

int Pilgrim::getMaxHp(){
    return maxhp;
}

/*********************************************************************************
 *
 * Reward methods
 *
**********************************************************************************/

void Pilgrim::findKnife(){
    knife.have = true;
}

void Pilgrim::findHatchet(){
    hatchet.have = true;
}

void Pilgrim::findBayonet(){
    bayonet.have = true;
    if(musket.have)
        musket.hasbayonet = true;
}

void Pilgrim::findMusket(){
    musket.have = true;
    musket.ammo += 10;
    if(bayonet.have)
        musket.hasbayonet = true;
}

void Pilgrim::findFlintlock(){
    flintlock.have = true;
    flintlock.ammo += 10;
}

void Pilgrim::findAmmoBag(){
    flintlock.ammo += 5;
    musket.ammo += 5;
}

void Pilgrim::atkUp(){
    bonusAttacks++;
}

void Pilgrim::accUp(){
    accuracyBonus++;
}

void Pilgrim::hpUp(int upby){
    if(upby == 0)
        upby = int(maxhp * .1);
    hp += upby;
    if(hp > maxhp)
        hp = maxhp;
}

void Pilgrim::maxUp(){
    maxhp += 5;
    hp +=5;
}

/*********************************************************************************
 *
 * Combat methods
 *
**********************************************************************************/

QString Pilgrim::rangeWeapon(){
    QString name = "No ranged weapon";
    if(flintlock.have){
        name = "Flintlock pistol";
    }
    else if (musket.have){
        name = "Musket";
        if(musket.hasbayonet){
            name += " with bayonet";
        }
    }
    return name;
}

int Pilgrim::rangeAttack(QString &s){
    int damage = 0;
    QString temp;
    if(musket.have && musket.shoot()){
        damage = musket.damage * accuracyBonus;
        temp.setNum(damage);
        s = "Your musket does " + temp + " damage";
        if(bayonet.have){
            damage += bayonet.damage * (bayonet.numberOfAttacks + bonusAttacks);
            temp.setNum(bayonet.damage);
            s += " and your bayonet adds " + temp + " damage";
        }
    }
    else if (flintlock.have && flintlock.shoot()){
        damage = flintlock.damage * accuracyBonus;
        temp.setNum(damage);
        s = "Your flintlock pistol does " + temp + " damage";
    }
    else{
        s = "No range weapon";
    }

    return damage;
}

QString Pilgrim::meleeWeapon(){
    QString name = "No melee weapon";
    if(hatchet.have){
        name = "Hatchet";
    }
    else if (knife.have){
        name = "Knife";
    }
    else if(bayonet.have){
        name = "Bayonet";
    }
    return name;
}

int Pilgrim::meleeAttack(QString &s){
    int damage = 0;
    QString temp;
    if(hatchet.have){
        damage = hatchet.damage * (hatchet.numberOfAttacks + bonusAttacks);
        temp.setNum(damage);
        s = "Your hatchet does " + temp + " damage";
    }
    else if (knife.have){
        damage = knife.damage * (knife.numberOfAttacks + bonusAttacks);
        temp.setNum(damage);
        s = "Your knife does " + temp + " damage";
    }
    else if (bayonet.have){
        damage = bayonet.damage * (bayonet.numberOfAttacks + bonusAttacks);
        temp.setNum(damage);
        s = "Your knife does " + temp + " damage";
    }
    else{
        s = "No melee weapon";
    }

    return damage;
}

bool Pilgrim::takedamage(int dmg){
    hp -= dmg;
    return hp > 0;
}
