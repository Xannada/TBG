#ifndef PILGRIM_H
#define PILGRIM_H

#include <QString>


struct Gun{
    bool canHaveBayonet;
    bool hasbayonet;
    int ammo;
    int damage;
    bool have;
    bool shoot(){return (ammo > 0)?ammo--:false;}
};


struct melee{
    bool have;
    int damage;
    int numberOfAttacks;
};

//struct consumable{
//    bool have;
//    void use(){have = false;}
//};

class Pilgrim
{
public:
    // con decon
    Pilgrim();
    ~Pilgrim();

    //life methods
    int getHpBar();
    QString health();
    int getHp();
    int getMaxHp();

    //reward updaters
    void findKnife();
    void findHatchet();
    void findBayonet();
    void findMusket();
    void findFlintlock();
    void findAmmoBag();
    void atkUp();
    void accUp();
    void hpUp(int upby = 0);
    void maxUp();
    void kill();
    int getKills();


    //combat
    QString rangeWeapon();
    int rangeAttack(QString& s);
    QString meleeWeapon();
    int meleeAttack(QString& s);
    bool takedamage(int dmg);


private:
    //life
    int hp;
    int maxhp;

    //score base
    int kills;
    int turkeys;
    int indians;
    int bears;

    //weapons
    Gun musket;
    Gun flintlock;
    melee knife;
    melee hatchet;
    melee bayonet;

    //bonuses
    int bonusAttacks;
    int accuracyBonus;
};

#endif // PILGRIM_H
