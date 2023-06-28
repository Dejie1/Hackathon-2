#include <string>
#include <Windows.h>
#include "Menu.h"
#include "Player.h"
#include "Creature.h"
#include "Inventory.h"
#include "Stage6.h"
#include <iostream>
using namespace std;

Stage6::Stage6(Player *playerPassed, SaveLoad *s)
{
    player = playerPassed;
    savePtr = s;
}

Stage6::~Stage6() {}

void Stage6::loadLevel()
{
    printStory();
    startlevel();
}

void Stage6::startlevel()
{
    creature();
    console();
}

void Stage6::creature()
{
    cultist.setAtk(monsterStats.atk);
    cultist.setHP(monsterStats.hp);
    cultist.setDefense(monsterStats.def);
    cultist.setSpeed(monsterStats.speed);
}

void Stage6::printStory()
{
    system("cls");
    cout << " Stage 6: The Final Confrontation " << endl;
    cout << "At long last, you reach the heart of the dungeon, where the ultimate challenge awaits. " << endl;
    cout << "Face the powerful and mysterious cultist and prove your strength to claim your freedom." << endl;
    cout << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void Stage6::console()
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
        cin.ignore();
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

            RNG = 1 + (rand() % 3);
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
                cout << " !! Encountered a cultist !! " << endl;
                cout << "-------------------------------------------------\n";
                system("pause");
                system("cls");
                player->battle(cultist);

                if (player->getHP() > 0)
                {
                    system("cls");
                    cout << "\n\nBattle won !!\n";
                    system("pause");
                    system("cls");
                    endlevel();
                }
                //}
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
                    cout << "health recovered to maximum.\n";
                }
                else if (player->getHP() <= player->getMaxHealth())
                {
                    cout << "\n 5 health recovered.\n";
                    player->setHP(player->getHP() + 5);
                }
                else
                {
                    cout << "health recovered to maximum.\n";
                }

                system("pause");
                system("cls");
            }
            else if (RNG == 6)
            {
                cout << "\"What's that sound..?\"\n";
                cout << "it sounds like a footstep... " << endl;
                cout << " !! It was the cultist !!  " << endl;
                system("pause");
                system("cls");
                player->battle(cultist);

                if (player->getHP() > 0)
                {
                    cout << " Battle won !\n";
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

void Stage6::endlevel()
{
    cout << "You found torches surrounding a weird pattern ...\n";
    Sleep(3000);
    cout << "\"What's this pattern ?\" You said as you slowly walks towards it. \n";
    cout << endl;
    cout << "\"ò¥ΓûæΓΓûæòÉΓò¥Γ\" You heard the portal chanting itself \n";
    cout << endl;
    cout << "Swoooosh. You got teleported to the surface. \n";
    cout << endl;
    cout << "You finally got out. \n";
    system("pause");
    system("cls");
    Menu objMenu;
    objMenu.congratMessage();
    savePtr->push(5, player);
    savePtr->savefile();
    system("pause");
    system("cls");
    exit(3);
}