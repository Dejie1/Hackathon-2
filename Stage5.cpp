#include <string>
#include <Windows.h>
#include "Menu.h"
#include "Player.h"
#include "Creature.h"
#include "Inventory.h"
#include "Stage5.h"
#include "Stage6.h"
#include "Shop.h"
#include <iostream>
using namespace std;

Stage5::Stage5(Player *playerPassed, SaveLoad *s)
{
    player = playerPassed;
    savePtr = s;
}

Stage5::~Stage5() {}

void Stage5::newItemFromChest()
{
    string typePosition[3], itemPosition[3];
    string tempType, tempItem, newWeapon = player->getWeapon(), newArmour = player->getArmor(), newShoes = player->getShoe();
    int i = 0, chestPosition = 0, tempStats = 0, statsPosition[3], newAtk = player->getWeaponValue(), newDef = player->getArmorValue(), newSpeed = player->getShoeValue(), input;
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
                tempItem = "Katana";
                tempStats = 20;
                weapon.check = 1;
            }
            else if (chestPosition == 2 && armour.check == 0)
            {
                tempType = "DEF";
                tempItem = "Diamond_Armour";
                tempStats = 19;
                armour.check = 1;
            }
            else if (chestPosition == 3 && shoes.check == 0)
            {
                tempType = "SPEED";
                tempItem = "Diamond_Shoes";
                tempStats = 18;
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

    cout << "OMG, you beated the chamelon ! Ahis time, you found 3 diamond chests behind the chamelon. " << endl;
    cout << "These are the gold chest, so you have to choose wisely. Good luck." << endl;
    cout << "1. Diamond Chest" << endl;
    cout << "2. Diamond Chest" << endl;
    cout << "3. Diamond Chest" << endl;
    cout << "> ";
    cin >> input;
    system("cls");

    if (typePosition[input - 1] == "ATK")
    {
        newWeapon = "Katana";
        newAtk = 20;
        player->pickItem("weapon", "Katana", 20);
    }
    else if (typePosition[input - 1] == "DEF")
    {
        newArmour = "Diamond_Armour";
        newDef = 19;
        player->pickItem("armor", "Diamond_Armour", 19);
    }
    else if (typePosition[input - 1] == "SPEED")
    {
        newShoes = "Diamond_Shoes";
        newSpeed = 18;
        player->pickItem("shoe", "Diamond_Shoes", 18);
    }

    cout << "You got a \"" << itemPosition[input - 1] << "\". Your " << typePosition[input - 1] << " is increased to " << statsPosition[input - 1] << ".";
    cout << "\n\nYour inventory is UPDATED:" << endl;
    cout << "Current weapon - \"" << newWeapon << "\"" << endl;
    cout << "Current armour - \"" << newArmour << "\"" << endl;
    cout << "Current shoes - \"" << newShoes << "\"" << endl;
    cout << "\nYour stats is UPDATED:" << endl;
    cout << "ATK - " << newAtk << endl;
    cout << "DEF - " << newDef << endl;
    cout << "SPEED - " << newSpeed << endl;
    cout << "-------------------------------------------------";
    cout << "\n\nHere are all the chest items, see what you missed just now :)" << endl;
    cout << "1. Diamond Chest - " << itemPosition[0] << " (" << typePosition[0] << " - " << statsPosition[0] << ")" << endl;
    cout << "2. Diamond Chest - " << itemPosition[1] << " (" << typePosition[1] << " - " << statsPosition[1] << ")" << endl;
    cout << "3. Diamond Chest - " << itemPosition[2] << " (" << typePosition[2] << " - " << statsPosition[2] << ")";
}

void Stage5::loadLevel()
{
    printStory();
    startlevel();
}

void Stage5::startlevel()
{
    creature();
    console();
}

void Stage5::creature()
{
    chameleon.setAtk(monsterStats.atk);
    chameleon.setHP(monsterStats.hp);
    chameleon.setDefense(monsterStats.def);
    chameleon.setSpeed(monsterStats.speed);
}

void Stage5::printStory()
{
    system("cls");
    cout << " Stage 5: The Dark Corridor " << endl;
    cout << "As you venture further into the dungeon, you find yourself in a long, dark corridor. " << endl;
    cout << "The only source of light is your torch, casting eerie shadows on the walls." << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void Stage5::console()
{
    string cmd = "dummy";
    int RNG;
    int potionRNG;
    srand(time(0));

    while (player->alive())
    {
        cout << "Type 'walk' to move forward ..." << endl;
        cout << "Type 'wait' to rest ..." << endl;
        cout << "Type 'view' to view inventory ..." << endl;
        cout << "Type 'stats' to view current stats... " << endl;
        cout << endl;
        cout << "> ";
        cin >> cmd;
        cout << endl;
        // cheats for dev
        // if (cmd == "cheat")
        // {
        //     player->setHP(player->getMaxHealth());
        // }
        while (cmd != "walk" && cmd != "wait" && cmd != "view" && cmd != "stats")
        {
            cout << "Invalid action. Please try again !\n";
            cout << "> ";
            cin >> cmd;
        }
        if (cmd == "walk")
        {
            cout << "Walking down the path ...\n";
            Sleep(3000);
            cout << player->getName() << " moved few steps forward." << endl;

            RNG = 1 + (rand() % 4);
            potionRNG = 1 + (rand() % 5);

            if (RNG == 1)
            {
                cout << "You found a door ...\n";
                cout << "Entering the door ..." << endl;
                Sleep(2000);
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
            }
            else if (RNG == 2 && potionRNG == 2)
            {
                cout << "Found a health potion !\n";
                cout << "-------------------------------------------------\n";
                player->setPotions(player->getPotions() + 1);
                system("pause");
                system("cls");
            }
            else if (RNG == 2 || RNG == 3)
            {
                cout << "\n\"Grr Grr Grr ...\" " << endl;
                cout << "\"Whats that sound ?\"\n";
                cout << " !! Encountered a chameleon !! " << endl;
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
                player->battle(chameleon);

                // if there are no goblins left in the dungeon found an exit and end the level.

                if (player->getHP() > 0)
                {
                    system("cls");
                    cout << "Battle won !!\n";
                    cout << player->getName() << " Leveled up ! " << endl;
                    cout << "You gained 5 MAX health. " << endl;
                    player->levelup();
                    int temp = 1 + (rand() % 5);
                    cout << "You also gained " << temp << " gold! " << endl;
                    player->setGold(player->getGold() + temp);
                    system("pause");
                    system("cls");
                    newItemFromChest(); // Behind the monster has 3 chests, you may choose 1.
                    cout << endl;
                    system("pause");
                    system("cls");
                    endlevel();
                }
            }
            else if (RNG == 4)
            {
                cout << player->getName() << " found a glowing statue.." << endl;
                cout << "\"Young man.. give me 5 health of yours..\" " << endl;
                cout << "\" and I shall give u 5 golds.. \"" << endl;
                cout << "\n Choose... " << endl;
                cout << "1. Here's the bloods..." << endl;
                cout << "2. Leave the statue..." << endl;
                string choice;
                cin >> choice;
                cout << "> ";
                while (choice != "1" && choice != "2")
                {
                    cout << "Enter again.." << endl;
                    cin >> choice;
                    cout << "> ";
                }
                if (choice == "1")
                {
                    cout << player->getName() << " gained 5 golds and lost 5  HP!" << endl;
                    player->setGold(player->getGold() + 5);
                    player->setHP(player->getHP() - 5);
                    system("pause");
                    system("cls");
                }
                else if (choice == "2")
                {
                    system("pause");
                    system("cls");
                }
            }
        }
        if (cmd == "wait")
        {
            cout << "Now waiting ...\n";
            Sleep(5000);
            cout << "While " << player->getName() << " was waiting ..." << endl;
            RNG = 1 + (rand() % 6);

            if (RNG == 1 || RNG == 2 || RNG == 3 || RNG == 4 || RNG == 5)
            {
                if ((player->getMaxHealth() - player->getHP()) < 5)
                {
                    player->setHP(player->getMaxHealth());
                    cout << endl;
                    cout << "Health recovered to maximum.\n";
                }
                else if (player->getHP() <= player->getMaxHealth())
                {
                    cout << "\n5 health recovered.\n";
                    player->setHP(player->getHP() + 5);
                }
                else
                {
                    cout << "Health recovered to maximum.\n";
                }

                system("pause");
                system("cls");
            }
            else if (RNG == 6)
            {
                cout << "\"What's that sound..?\"\n";
                cout << "It sounds like a footstep... " << endl;
                cout << " !! It was the Chameleon !!  " << endl;
                system("pause");
                system("cls");
                player->battle(chameleon);

                if (player->getHP() > 0)
                {
                    cout << "Battle won ! You decide to continue moving on.\n";
                    int temp = 1 + (rand() % 5);
                    cout << "You also gained " << temp << " gold! " << endl;
                    player->setGold(player->getGold() + temp);
                }
                system("pause");
                system("cls");
            }
        }
        if (cmd == "view")
        {
            player->showInventory();
            system("pause");
            system("cls");
        }
        if (cmd == "stats")
        {
            player->showStats();
            system("pause");
            system("cls");
        }
        cmd = "dummy";
    }
    Menu objMenu;
    system("cls");
    objMenu.gameOver();
    system("pause");
    objMenu.ShowMenu();
}

void Stage5::endlevel()
{
    cout << "You found torches surrounding a weird pattern ...\n";
    Sleep(3000);
    cout << "\"What's this pattern ?\" You said as you slowly walks towards it. \n";
    cout << endl;
    cout << "\"ò¥ΓûæΓΓûæòÉΓò¥Γ\" You heard the portal chanting itself \n";
    cout << endl;
    cout << "Swoooosh. You got teleported to another level. \n";
    cout << endl;
    cout << "This dungeon looked even scarier than the one before. \n";
    cout << endl;
    cout << "You proceed to go forward because this was the only way you could go. \n";
    system("pause");
    system("cls");
    cout << "\"Cough, cough..\" You heard someone coughing behind the walls.. " << endl;
    cout << " \"Hey Granny ! What are you doing here? \" You walks towards her";
    cout << " and you saw her carrying a bag of items..." << endl;

    Shop shopObject(player);
    Shop *shop = &shopObject;
    shop->displayMenu();
    system("pause");
    system("cls");
    cout << "Congratulations you finished the fifth level of the dungeon! \n";
    cout << "------------------------------------------------------------\n";
    savePtr->push(6, player);
    savePtr->savefile();
    system("pause");

    system("cls");

    Stage6 stage6(player, savePtr);
    stage6.loadLevel();
}