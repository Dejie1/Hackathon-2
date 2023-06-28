#ifndef STAGE1_H
#define STAGE1_H
#include "Player.h"
#include "Creature.h"
#include "SaveLoad.h"
#include <iostream>
using namespace std;

class Stage1
{
private:
    string name;
    int numMonster;

    Player playerObject;
    Player *player = &playerObject;
    SaveLoad save;
    SaveLoad *savePtr = &save;

    struct MonsterStats
    {
        int hp = 10, atk = 2, def = 1, speed = 0;
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
    Creature slime;

    Stage1(Player *, SaveLoad *);
    ~Stage1();
    void newItemFromChest();
    void printStory();
    void loadLevel();
    void startlevel();
    void console();
    void endlevel();
    void creature();
};

#endif
