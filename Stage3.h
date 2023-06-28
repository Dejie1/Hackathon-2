#ifndef STAGE3_H
#define STAGE3_H
#include "Player.h"
#include "Creature.h"
#include "SaveLoad.h"
#include "Shop.h"
#include <iostream>
using namespace std;

class Stage3
{
private:
    Player playerObject;
    Player *player = &playerObject;
    SaveLoad save;
    SaveLoad *savePtr = &save;
    struct MonsterStats
    {
        int hp = 16, atk = 5, def = 4, speed = 10;
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
    Creature skeleton;

    Stage3(Player *, SaveLoad *);
    ~Stage3();
    void newItemFromChest();
    void printStory();
    void loadLevel();
    void startlevel();
    void console();
    void endlevel();
    void creature();
};

#endif