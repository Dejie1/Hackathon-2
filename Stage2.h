#ifndef STAGE2_H
#define STAGE2_H
#include "Player.h"
#include "Creature.h"
#include "SaveLoad.h"
#include <iostream>
using namespace std;

class Stage2
{
private:
    Player playerObject;
    Player *player = &playerObject;
    SaveLoad save;
    SaveLoad *savePtr = &save;

    struct MonsterStats
    {
        int hp = 15, atk = 4, def = 2, speed = 1;
    };

    struct ChestConfig
    {
        bool check = 0;
    };

    struct Chest
    {
        string type, item;
        int stats = 0;
        bool check = 0;
    };

public:
    struct MonsterStats monsterStats;
    struct ChestConfig weapon, armour, shoes;
    struct Chest chest1, chest2, chest3;
    Creature wolf;

    Stage2(Player *, SaveLoad *);
    ~Stage2();
    void newItemFromChest();
    void printStory();
    void loadLevel();
    void startlevel();
    void console();
    void endlevel();
    void creature();
};

#endif