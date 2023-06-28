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
    fstream infile("SaveGame.txt", ios::in);
    string obj;
    if (infile)
    {
        infile >> obj >> obj;
        cout << "\n\nThe latest saved progress." << endl;
        cout << "Name:" << obj << endl;
        infile >> obj >> obj;
        cout << "Stage: " << obj << endl;
        infile >> obj >> obj;
        cout << "Level : " << obj << endl;
        cout << "\n\nDo you want to load this progress? " << endl;
        cout << "Press 'y' / 'yes' to proceed. " << endl;
        cout << "Or press 'n' / 'No' to back to Main Menu\n"
             << endl;
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
    if (outfile)
    {
        outfile << "name " << stackTop->player.getName();
        outfile << "\nstage " << stackTop->stage;
        outfile << "\nlevel " << stackTop->player.getLvl();
        outfile << "\nhp " << stackTop->player.getHP();
        outfile << "\nMaxHP " << stackTop->player.getMaxHealth();
        outfile << "\nattack " << stackTop->player.getWeaponValue();
        outfile << "\ndefense " << stackTop->player.getArmorValue();
        outfile << "\nspeed " << stackTop->player.getShoeValue();
        outfile << "\npotion " << stackTop->player.getPotions();
        outfile << "\ngold " << stackTop->player.getGold();
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

int SaveLoad ::loadfile(Player *ply)
{
    fstream infile("SaveGame.txt", ios::in);
    string object, equip = "";
    int value, stage = 0;
    if (infile)
    {
        cout << "Reading file..." << endl;
        ply->initialiseInventory();
        while (infile >> object)
        {
            if (object == "name")
            {
                infile >> equip;
                ply->setName(equip);
            }
            if (object == "MaxHP")
            {
                infile >> value;
                ply->setMaxHP(value);
            }

            if (object == "stage")
            {
                infile >> value;
                stage = value;
            }
            else if (object == "level")
            {
                infile >> value;
                ply->setLevel(value);
            }
            else if (object == "hp")
            {
                infile >> value;
                ply->setHP(value);
            }
            else if (object == "attack")
            {
                infile >> value;
                ply->setAtk(value);
            }
            else if (object == "defense")
            {
                infile >> value;
                ply->setDefense(value);
            }
            else if (object == "speed")
            {
                infile >> value;
                ply->setSpeed(value);
            }
            else if (object == "potion")
            {
                infile >> value;
                ply->setPotions(value);
            }
            else if (object == "gold")
            {
                infile >> value;
                ply->setGold(value);
            }
            else if (object == "weapon")
            {
                infile >> equip;
                ply->pickItem("weapon", equip, ply->getAtk());
            }
            else if (object == "armor")
            {
                infile >> equip;
                ply->pickItem("armor", equip, ply->getDefense());
            }
            else if (object == "shoe")
            {
                infile >> equip;
                ply->pickItem("shoe", equip, ply->getSpeed());
            }
        }
    }
    else
    {
        cout << "SaveGame.txt not exist." << endl;
    }

    return stage;
}
