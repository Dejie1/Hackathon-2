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
        string ItemName;
        string Itemprice;
        ListNode *nextNode;
    };
    ListNode *head;

public:
    void appendList(string, int);
    void displayMenu();
    void displayPurchased();
    void CheckAffordable();
};

#endif
