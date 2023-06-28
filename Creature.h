#ifndef CREATURE_H
#define CREATURE_H

class Creature
{
private:
    int HP;
    int Atk;
    int Defense;
    int Speed;
    int MonsterNumber;

public:
    Creature(int, int, int, int);
    Creature();
    ~Creature();
    bool StageEnemyAlive();
    int getMonsterNumber();
    int getHP();
    int getAtk();
    int getSpeed();
    int getDefense();
    void setHP(int);
    void setAtk(int);
    void setSpeed(int);
    void setDefense(int);
};

#endif