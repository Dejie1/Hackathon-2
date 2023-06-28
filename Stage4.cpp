#include <string>
#include <Windows.h>
#include "Menu.h"
#include "Player.h"
#include "Creature.h"
#include "Inventory.h"
#include "Stage4.h"
#include "Stage5.h"
#include <iostream>
using namespace std;

Stage4::Stage4(Player *playerPassed, SaveLoad *s)
{
    player = playerPassed;
    savePtr = s;
}

Stage4::~Stage4() {}

void Stage4::newItemFromChest()
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
                tempItem = "Sword";
                tempStats = 14;
                weapon.check = 1;
            }
            else if (chestPosition == 2 && armour.check == 0)
            {
                tempType = "DEF";
                tempItem = "Gold_Armour";
                tempStats = 13;
                armour.check = 1;
            }
            else if (chestPosition == 3 && shoes.check == 0)
            {
                tempType = "SPEED";
                tempItem = "Gold_Shoes";
                tempStats = 12;
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

    cout << "You beated the golem ! You found 3 gold chests behind the golem." << endl;
    cout << "Hmm ... which one would you like to open ?" << endl;
    cout << "1. Gold Chest" << endl;
    cout << "2. Gold Chest" << endl;
    cout << "3. Gold Chest" << endl;
    cout << "> ";
    cin >> input;

    while (input != 1 && input != 2 && input != 3)
    {
        cout << "Invalid input. Please try again !" << endl;
        cout << "> ";
        cin >> input;
    }

    system("cls");

    if (typePosition[input - 1] == "ATK")
    {
        newWeapon = "Sword";
        newAtk = 14;
        player->pickItem("weapon", "Sword", 14);
    }
    else if (typePosition[input - 1] == "DEF")
    {
        newArmour = "Gold_Armour";
        newDef = 13;
        player->pickItem("armor", "Gold_Armour", 13);
    }
    else if (typePosition[input - 1] == "SPEED")
    {
        newShoes = "Gold_Shoes";
        newSpeed = 12;
        player->pickItem("shoe", "Gold_Shoes", 12);
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
    cout << "-------------------------------------------------------------";
    cout << "\nHere are all the chest items, see what you missed just now :)" << endl;
    cout << "1. Gold Chest - " << itemPosition[0] << " (" << typePosition[0] << " - " << statsPosition[0] << ")" << endl;
    cout << "2. Gold Chest - " << itemPosition[1] << " (" << typePosition[1] << " - " << statsPosition[1] << ")" << endl;
    cout << "3. Gold Chest - " << itemPosition[2] << " (" << typePosition[2] << " - " << statsPosition[2] << ")";
}

void Stage4::loadLevel()
{
    printStory();
    startlevel();
}

void Stage4::startlevel()
{
    creature();
    console();
}

void Stage4::creature()
{
    golem.setAtk(monsterStats.atk);
    golem.setHP(monsterStats.hp);
    golem.setDefense(monsterStats.def);
    golem.setSpeed(monsterStats.speed);
}

void Stage4::printStory()
{
    system("cls");
    cout << " Stage 4: The Fiery Abyss " << endl;
    cout << "The ground beneath you gives way, and you find yourself in a fiery abyss. " << endl;
    cout << "Lava flows and deadly flames surround you, testing your courage and determination." << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void Stage4::console()
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
        cout << "Type 'exit' to exit the game..." << endl;
        cout << endl;
        cout << "> ";
        cin >> cmd;
        cout << endl;
        // cheats for dev
        // if (cmd == "cheat")
        // {
        //     player->setHP(player->getMaxHealth());
        // }
        while (cmd != "walk" && cmd != "wait" && cmd != "view" && cmd != "stats" && cmd != "exit")
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
                cout << player->getName() << " found a door ...\n";
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
                cout << " !! Encountered a golem !! " << endl;
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
                player->battle(golem);

                // if there are no goblins left in the dungeon found an exit and end the level.

                if (player->getHP() > 0)
                {
                    system("cls");
                    cout << "Battle won !!\n";
                    cout << player->getName() << " Leveled up ! " << endl;
                    cout << "You gained 5 MAX health. " << endl;
                    player->levelup();
                    int temp = 1 + (rand() % 5);
                    cout << "You also gained " << temp << " gold ! " << endl;
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
                cout << player->getName() << " found a glowing statue ..." << endl;
                cout << "\"Young man ... give me 5 health of yours ...\" " << endl;
                cout << "\"and I shall give u 5 golds ... \"" << endl;
                cout << "\nChoose ..." << endl;
                cout << "1. Here's the bloods ..." << endl;
                cout << "2. Leave the statue ..." << endl;
                string choice;
                cout << "> ";
                cin >> choice;
                while (choice != "1" && choice != "2")
                {
                    cout << "Enter again ..." << endl;
                    cin >> choice;
                    cout << "> ";
                }
                if (choice == "1")
                {
                    cout << player->getName() << " gained 5 golds and lost 5  HP !" << endl;
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
                    cout << "\n5 Health recovered.\n";
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
                cout << " !! It was the Golem !!  " << endl;

                system("pause");
                system("cls");
                player->battle(golem);

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
        if (cmd == "exit")
        {
            char choice;
            cout << "Exit the game ? Enter 'y' or 'n' " << endl;
            cin >> choice;
            if (tolower(choice) == 'y')
            {
                exit(3);
            }
            else if (tolower(choice) == 'n')
            {
                cout << "The game continues..." << endl;
                system("pause");
                system("cls");
            }
        }
        cmd = "dummy";
    }
    Menu objMenu;
    system("cls");
    objMenu.gameOver();
    system("pause");
    objMenu.ShowMenu();
}

void Stage4::endlevel()
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
    cout << "Congratulations you finished the fourth level of the dungeon! \n";
    cout << "-------------------------------------------------------------\n";
    savePtr->push(5, player);
    system("pause");

    system("cls");

    Stage5 stage5(player, savePtr);
    stage5.loadLevel();
}