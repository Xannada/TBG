#ifndef PILGRIM_H
#define PILGRIM_H


struct Gun{
    bool canHaveBayonet;
    bool hasbayonet;
    int ammo;
    int damage;
    bool have;
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
