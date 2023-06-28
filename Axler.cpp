#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stage0.h"
using namespace std;

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

int main()
{
    ChestConfig weapon, armour, shoes;
    Chest chest1, chest2, chest3;
    string typePosition[3], itemPosition[3];
    string tempType, tempItem, newWeapon = "Rusty_Knife", newArmour = "Leather_Armour", newShoes = "Leather_Shoes";
    int i = 0, chestPosition = 0, tempStats = 0, statsPosition[3], newAtk = 0, newDef = 0, newSpeed = 0, input;
    unsigned seed = time(0);
    srand(seed);

    while (chestPosition == 0)
    {
        if (weapon.check == 1 && armour.check == 1 && shoes.check == 1)
            break;
        else
        {
            chestPosition = rand() % 4;

            if (chestPosition == 1 && weapon.check == 0)
            {
                tempType = "ATK";
                tempItem = "Sharp_Knife";
                tempStats = 6;
                weapon.check = 1;
            }
            else if (chestPosition == 2 && armour.check == 0)
            {
                tempType = "DEF";
                tempItem = "Bone_Armour";
                tempStats = 5;
                armour.check = 1;
            }
            else if (chestPosition == 3 && shoes.check == 0)
            {
                tempType = "SPEED";
                tempItem = "Bone_Shoes";
                tempStats = 4;
                shoes.check = 1;
            }

            if (chestPosition != 0 && chest1.check == 0)
            {
                chest1.type = tempType;
                chest1.item = tempItem;
                chest1.stats = tempStats;
                chest1.check = 1;
            }
            else if (chestPosition != 0 && chest2.check == 0)
            {
                chest2.type = tempType;
                chest2.item = tempItem;
                chest2.stats = tempStats;
                chest2.check = 1;
            }
            else if (chestPosition != 0 && chest3.check == 0)
            {
                chest3.type = tempType;
                chest3.item = tempItem;
                chest3.stats = tempStats;
                chest3.check = 1;
            }

            if (chestPosition != 0 && tempType != "" && tempItem != "" && tempStats != 0)
            {
                typePosition[i] = tempType;
                itemPosition[i] = tempItem;
                statsPosition[i] = tempStats;
                i++;
            }

            tempType = "";
            tempItem = "";
            tempStats = 0;
            chestPosition = 0;
        }
    }

    cout << "Wow, there are 3 chests here ! But ... which one would you like to open ?" << endl;
    cout << "1. Red Chest" << endl;
    cout << "2. Blue Chest" << endl;
    cout << "3. Yellow Chest" << endl;
    cin >> input;
    system("cls");

    if (typePosition[input - 1] == "ATK")
    {
        newWeapon = "Sharp_Knife";
        newAtk = 6;
    }
    else if (typePosition[input - 1] == "DEF")
    {
        newArmour = "Bone_Armour";
        newDef = 5;
    }
    else if (typePosition[input - 1] == "SPEED")
    {
        newShoes = "Bone_Shoes";
        newSpeed = 4;
    }

    cout << "Wow you got a \"" << itemPosition[input - 1] << "\" ! Your " << typePosition[input - 1] << " is increased to " << statsPosition[input - 1] << ".";
    cout << "\n\nYour inventory is updated:" << endl;
    cout << "Current weapon - \"" << newWeapon << "\"" << endl;
    cout << "Current armour - \"" << newArmour << "\"" << endl;
    cout << "Current shoes - \"" << newShoes << "\"";
    cout << "\n\nYour stats is updated:" << endl;
    cout << "ATK - " << newAtk << endl;
    cout << "DEF - " << newDef << endl;
    cout << "SPEED - " << newSpeed;
    cout << "\n\nHere are all the chest items, see what you missed just now :)" << endl;
    cout << "1. Red Chest - " << itemPosition[0] << " (" << typePosition[0] << " - " << statsPosition[0] << ")" << endl;
    cout << "2. Blue Chest - " << itemPosition[1] << " (" << typePosition[1] << " - " << statsPosition[1] << ")" << endl;
    cout << "3. Yellow Chest - " << itemPosition[2] << " (" << typePosition[2] << " - " << statsPosition[2] << ")";

    return 0;
}