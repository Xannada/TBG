#ifndef PILGRIM_H
#define PILGRIM_H


struct Gun{
    bool canHaveBayonet;
    bool hasbayonet;
    int ammo;
    int damage;
    bool have;
    void shoot(){ammo--;}
};


struct melee{
    bool have;
    int damage;
    int numberOfAttacks;
};

class Pilgrim
{
public:
    Pilgrim();
    ~Pilgrim();
    void findKnife();
    void findHatchet();
    void findBayonet();
    void findMusket();
    void findFlintlock();
private:
    int hp;
    int maxhp;

    int kills;
    int turkeys;

    Gun musket;
    Gun flintlock;
    melee knife;
    melee hatchet;
    melee bayonet;
};

#endif // PILGRIM_H
