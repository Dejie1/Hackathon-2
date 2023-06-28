#include "Inventory.h"
#include "Creature.h"
// #include "Player.h"
// #include "Stage0.h"
// #include "Stage1.h"
// #include "Stage2.h"
// #include "Stage3.h"
// #include "Stage4.h"
// #include "Stage5.h"
// #include "Stage6.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    // Inventory PlayerINV;
    string name = "Anson";
    int lvl, hp, atk, def, spd, pt;
    int value1, value2;
    lvl = 1;
    hp = 20;
    atk = 5;
    def = 5;
    spd = 2;
    pt = 1;
    value1 = 10;
    value2 = 10;
    cout << "Hello";

    /*Player Oniichan(name, lvl, hp, atk, def, spd, pt); // default stas of a player
    Oniichan.pickItem("weapon", "Sword", value1);
    Oniichan.pickItem("armor", "jacket", value2);
    Oniichan.setAtk(value1);
    Oniichan.setDefense(value2);
    PlayerINV.showInventory();
    Creature Slime(20, 6, 1, 0);
    Oniichan.battle(Slime);*/
    return 0;
}