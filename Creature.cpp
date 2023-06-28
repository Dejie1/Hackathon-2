#include "Creature.h"
#include <iostream>
Creature ::Creature(int hp, int atk, int df, int spd)
{
    HP = hp;
    Atk = atk;
    Defense = df;
    Speed = spd;
}
Creature ::Creature()
{
    HP = 0;
    Atk = 0;
    Defense = 0;
    Speed = 0;
}

Creature ::~Creature()
{
}

int Creature::getMonsterNumber()
{
    return MonsterNumber;
}

int Creature ::getHP()
{
    return HP;
}

int Creature ::getAtk()
{
    return Atk;
}

int Creature ::getSpeed()
{
    return Speed;
}

int Creature ::getDefense()
{
    return Defense;
}

void Creature ::setHP(int hp)
{
    HP = hp;
}

void Creature ::setAtk(int atk)
{
    Atk = atk;
}
void Creature ::setDefense(int defense)
{
    Defense = defense;
}
void Creature ::setSpeed(int speed)
{
    Speed = speed;
}

bool Creature ::StageEnemyAlive()
{
    if (HP <= 0)
        return false;
    else
        return true;
}