#include "SaveLoad.h"
#include <iostream>
using namespace std;

SaveLoad ::SaveLoad() // constuctor
{
    stackTop = nullptr;
}

SaveLoad ::~SaveLoad()
{
    while (stackTop)
    {

        pop();
    }
}

void SaveLoad ::push(int stage, Player *ply)
{
    Node *newNode;
    newNode = new Node;
    newNode->stage = stage;
    newNode->player = *ply;

    cout << "Your Game Progress is saved!" << endl;

    if (!stackTop)
    {
        newNode->next = nullptr;
        stackTop = newNode;
    }
    else
    {
        newNode->next = stackTop;
        stackTop = newNode;
    }
    savefile();
}

void SaveLoad ::show()
{
    if (stackTop)
    {
        cout << "The latest saved progress." << endl;
        cout << "Stage: " << stackTop->stage << endl;
        cout << "Name:" << stackTop->player.getName() << endl; // show player stats and inventory.
        cout << "Weapon: " << stackTop->player.getWeapon() << endl;
    }
    else
    {
        cout << "Your Save List is empty!" << endl;
    }
}

// void SaveLoad :: pop(int& num, Player& ply)
// {
//     Node *NodePtr;
//     NodePtr =stackTop;
//     num = stackTop->stage;
//     ply = stackTop->player;
//     stackTop = stackTop->next;
//     delete NodePtr;
// }

void SaveLoad ::pop()
{
    Node *NodePtr;
    NodePtr = stackTop;
    // num = stackTop->stage;
    // ply = stackTop->player;
    stackTop = stackTop->next;
    delete NodePtr;
}

void SaveLoad ::savefile()
{
    fstream outfile;
    outfile.open("SaveGame.txt", ios ::out);
    if (outfile.is_open())
    {
        outfile << "stage " << stackTop->stage;
        outfile << "\nlevel " << stackTop->player.getLvl();
        outfile << "\nhp " << stackTop->player.getHP();
        outfile << "\nattack " << stackTop->player.getWeaponValue();
        outfile << "\ndefense " << stackTop->player.getArmorValue();
        outfile << "\nspeed " << stackTop->player.getShoeValue();
        outfile << "\npotion " << stackTop->player.getPotions();
        outfile << "\nweapon ";
        if (stackTop->player.getWeapon() == "")
            outfile << "0";
        else
            outfile << stackTop->player.getWeapon();

        outfile << "\narmor ";
        if (stackTop->player.getArmor() == "")
            outfile << "0";
        else
            outfile << stackTop->player.getArmor();

        outfile << "\nshoe ";
        if (stackTop->player.getShoe() == "")
            outfile << "0";
        else
            outfile << stackTop->player.getShoe();
    }
    else
    {
        cout << "Error. Save System crashed." << endl;
    }
    cout << "Game saved file succesfully, you can load the game progress at future." << endl;
}

void SaveLoad ::loadfile(int &stag, Player *ply)
{
    fstream infile("SaveGame.txt", ios::in);
    string object;
    int value;
    if (infile)
    {
        cout << "Reading file..." << endl;
        while (infile >> object)
        {
            cout << object << " ";
            infile >> value;
            cout << value;
            if (object == "stage")
            {
                stag = value;
            }
            else if (object == "level")
            {
                ply->setLevel(value);
            }
            else if (object == "hp")
            {
                ply->setHP(value);
            }
            else if (object == "attack")
            {
                ply->setAtk(value);
            }
            else if (object == "defense")
            {
                ply->setDefense(value);
            }
            else if (object == "speed")
            {
                ply->setSpeed(value);
            }
            else if (object == "potion")
            {
                ply->setPotions(value);
            }
            else if (object == "weapon")
            {
                if (value)
                    ply->pickItem("weapon", to_string(value), ply->getAtk());
                else
                    ply->pickItem("weapon", "", ply->getAtk());
            }
            else if (object == "armor")
            {
                if (value)
                    ply->pickItem("armor", to_string(value), ply->getDefense());
                else
                    ply->pickItem("armor", "", ply->getDefense());
            }
            else if (object == "shoe")
            {
                if (value)
                    ply->pickItem("shoe", to_string(value), ply->getSpeed());
                else
                    ply->pickItem("shoe", "", ply->getSpeed());
            }
        }
        cout << "Player: " << ply->getName();
        cout << "Level: " << ply->getLvl();
    }
    else
    {
        cout << "suck my cock" << endl;
    }
}