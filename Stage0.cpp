#include <string>
#include <Windows.h>
#include "Player.h"
#include "Stage0.h"
#include "Stage1.h"
#include "SaveLoad.h"
#include <iostream>
using namespace std;

Stage0::Stage0() {}
Stage0::~Stage0() {}

void Stage0::loadLevel()
{
    player->setHP(10000);
    setPlayer();
    player->initialiseInventory();
    printStory();
}

void Stage0::setPlayer()
{
    player->setHP(30);
    player->setLevel(0);
    system("cls");
    cout << "Exile, whats your name? " << endl;
    cout << "> ";
    cin.ignore();
    getline(cin, name);
    player->setName(name);
    if (name == "")
    {
        name = "player";
    }
    player->setName(name);
}

void Stage0::printStory()
{
    system("cls");
    cout << "You wakes up in a mysterious room with no memory of how you get here ..." << endl;
    cout << "\"Damn ... Its cold in here\" You said as you slowly close your eyes once again ... " << endl;
    cout << "You heard voices ..." << endl;
    cout << endl;
    cout << "\"Wake up, son ... Wake up, " << player->getName() << ". You dont have much time left ...\"" << endl;
    cout << "\"Is that ... God ? I don't care ... let me be ...\"" << endl;
    cout << endl;
    Sleep(3000);
    cout << "Choose:" << endl;
    cout << "1. Slowly gets up ..." << endl;
    cout << "2. Continue sleeping" << endl;
    cout << "> ";
    cin >> control;
    while (control != "1" && control != "2")
    {
        cout << "Invalid command. Choose again !\n";
        cout << "> ";
        cin >> control;
    }

    if (control == "1")
    {
        // Start the story + level1
        Stage1 stage1(player, SaveLoadPtr);
        stage1.loadLevel();
    }
    if (control == "2")
    {
        // Load the game
        cout << "\"I didn't know you're such a weakling " << player->getName() << " ...\" Says the voice." << endl;
        cout << "I am disappointed. Stay in hell. " << endl;
        cout << endl;
        Sleep(2000);
        cout << " ####     ##    #    #  ######     ####   #    #  ######  #####  " << endl;
        cout << "#    #   #  #   ##  ##  #         #    #  #    #  #       #    # " << endl;
        cout << "#       #    #  # ## #  #####     #    #  #    #  #####   #    # " << endl;
        cout << "#  ###  ######  #    #  #         #    #  #    #  #       #####  " << endl;
        cout << "#    #  #    #  #    #  #         #    #   #  #   #       #   #  " << endl;
        cout << " ####   #    #  #    #  ######     ####     ##    ######  #    # " << endl;
        return;
    }
}