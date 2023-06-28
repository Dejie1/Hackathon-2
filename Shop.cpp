#include "Shop.h"
#include <iostream>
using namespace std;

void Shop::displayMenu()
{
    cout << "Good day... chosen one.. what do you want to buy?" << endl;
    cout << "-----------------------------------------------------------------------------\n";
    cout << "|      Item                              |            Price                 |\n";
    cout << "| --------------------------------------------------------------------------|\n";
    cout << "| 1. Health Potion                       |           3 Golds                |\n";
    cout << "| --------------------------------------------------------------------------|\n";
    cout << "| 2. Strength Tonic (adds 3 to attack)   |           5 Golds                |\n";
    cout << "| --------------------------------------------------------------------------|\n";
    cout << "| 3. Defense Tonic  (adds 3 to defense)  |           5 Golds                |\n";
    cout << "| --------------------------------------------------------------------------|\n";
    cout << "| 4. Speed Tonic    (adds 3 to speed)    |           5 Golds                |\n";
    cout << "| --------------------------------------------------------------------------|\n";
    cout << "You have " << player->getGold() << " gold." << endl;
    cout << "Enter the number of your desired item or enter '5' to quit." << endl;
    cout << "> ";
    string choice;
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
    {
        cout << "Invalid option." << endl;
        cout << "> ";
        cin >> choice;
    }

    if (choice == "1" && player->getGold() > 3)
    {
        cout << "Health Potion Bought ! " << endl;
        player->setGold(player->getGold() - 3);
    }

    else if (choice == "2" && player->getGold() > 5)
    {
        cout << "Strength tonic Bought! " << endl;
        player->setGold(player->getGold() - 5);
    }

    else if (choice == "3" && player->getGold() > 5)
    {
        cout << "Defense tonic Bought! " << endl;
        player->setGold(player->getGold() - 5);
    }

    else if (choice == "4" && player->getGold() > 5)
    {
        cout << "Speed tonic Bought! " << endl;
        player->setGold(player->getGold() - 5);
    }

    else if (choice == "5")
    {
        cout << "Exited." << endl;
    }
}

void Shop::displayPurchased()
{
    ListNode *nodePtr = head;

    // Check if the list is empty
    if (!nodePtr)
    {
        cout << "Did not purchase anything." << endl;
        return;
    }

    // Traverse the list and print node data
    while (nodePtr)
    {
        cout << "Name: " << nodePtr->ItemName << endl;
        cout << "Price: " << nodePtr->Itemprice << endl;
        nodePtr = nodePtr->nextNode;
    }

    cout << endl;
}

void Shop::appendList(string n, int p)
{ // Pointer for new node (Node to do operations with)
    ListNode *newNode;
    // Pointer to traverse through list
    ListNode *nodePtr;

    newNode = new ListNode;
    newNode->ItemName = n;
    newNode->Itemprice = p;
    newNode->nextNode = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;

        while (nodePtr->nextNode)
        {
            nodePtr = nodePtr->nextNode;
        }
        // After traversing, the nodePtr should be at the end of the list
        //  Add a new node.

        nodePtr->nextNode = newNode;
    }
}