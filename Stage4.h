#ifndef STAGE4_H
#define STAGE4_H
#include "Player.h"
#include "Creature.h"
#include "SaveLoad.h"
#include <iostream>
using namespace std;

class Stage4
{
private:
    Player playerObject;
    Player *player = &playerObject;
    SaveLoad save;
    SaveLoad *savePtr = &save;
    struct MonsterStats
    {
        int hp = 20, atk = 4, def = 10, speed = 3;
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
    Creature golem;

    Stage4(Player *, SaveLoad *);
    ~Stage4();
    void newItemFromChest();
    void printStory();
    void loadLevel();
    void startlevel();
    void console();
    void endlevel();
    void creature();
};

#endif