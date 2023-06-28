#ifndef STAGE6_H
#define STAGE6_H
#include "Player.h"
#include "Creature.h"
#include "SaveLoad.h"
#include <iostream>
using namespace std;

class Stage6
{
private:
    Player playerObject;
    Player *player = &playerObject;
    SaveLoad save;
    SaveLoad *savePtr = &save;

    struct MonsterStats
    {
        int hp = 25, atk = 15, def = 8, speed = 6;
    };

public:
    struct MonsterStats monsterStats;
    Creature cultist;
    Stage6(Player *, SaveLoad *);
    ~Stage6();
    void printStory();
    void loadLevel();
    void startlevel();
    void console();
    void endlevel();
    void creature();
};

#endif