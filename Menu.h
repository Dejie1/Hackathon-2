#ifndef MENU_H
#define MENU_H
#include "Stage0.h"
#include "Player.h"
#include "SaveLoad.h"

class Menu
{
private:
    string MenuControl;
    Stage0 stage0Object;
    Stage0 *stage0 = &stage0Object;
    SaveLoad save;
    SaveLoad *SavePtr = &save;
    Player playerObject;
    Player *plyPtr = &playerObject;

public:
    Menu();
    ~Menu();
    void ShowMenu();
    void gameOver();
    void congratMessage();
};

#endif