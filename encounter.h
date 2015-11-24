#ifndef ENCOUNTER_H
#define ENCOUNTER_H

#include <QString>

class Encounter
{
public:
    Encounter();
    ~Encounter();

    void set(QString n, QString s, int h, int d);
    bool takeDamage(int dmg);
    int attack();
    QString getName();
    QString atkDes();

private:
    QString name;
    QString attackDesc;
    int hp;
    int damage;

};

#endif // ENCOUNTER_H
