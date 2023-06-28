#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Inventory
{
private:
    // int numItem;
    // string item;
    struct Node
    {
        string itemType;
        string itemName = "None";
        int itemValue = 0;
        Node *next = nullptr;
    };

    Node *head = nullptr;

public:
    Inventory();
    ~Inventory();
    // void useItem(string, string, int);
    void appendNode(string, string, int);
    void showInventory();
    int getWeaponValue();
    int getArmorValue();
    int getShoeValue();
    void updateInventory(string, string, int);
    string getWeapon();
    string getArmor();
    string getShoe();

    // Inventory();
    // ~Inventory();
    // void pickupItem(string);
    // void listItem();
};

#endif