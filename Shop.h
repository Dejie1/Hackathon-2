#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include "Player.h"
using namespace std;

class Shop
{
private:
    Player playerObject;
    Player *player = &playerObject;
    struct ListNode
    {
        string ItemType;
        string ItemName;
        string Itemprice;
        ListNode *nextNode;
    };
    ListNode *head;

public:
    Shop(Player *);
    void appendList(string, string, string);
    void displayMenu();
    void displayPurchased();
    void clearOutput();
    void sellItem(string);
};

#endif
