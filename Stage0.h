#ifndef STAGE0_H
#define STAGE0_H
#include "Player.h"
#include <iostream>
#include "SaveLoad.h"
using namespace std;

class Stage0
{
private:
    string control;
    string name;
    Player playerObject;
    Player *player = &playerObject;
    SaveLoad save;
    SaveLoad *SaveLoadPtr = &save;

public:
    Stage0();
    ~Stage0();
    void loadLevel();
    void printStory();
    void setPlayer();
};

#endif