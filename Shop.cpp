#include "Shop.h"
#include <iostream>
using namespace std;

Shop::Shop(Player *playerPassed)
{
    head = nullptr;
    player = playerPassed;
}

void Shop::displayMenu()
{
    string choice;
    bool exitShop = false;
    while (!exitShop)
    {
        cout << "\n\"Good day... chosen one.. what do you want to buy?\"" << endl;
        cout << "-----------------------------------------------------------------------------\n";
        cout << "|      Item                              |            Price                 |\n";
        cout << "| --------------------------------------------------------------------------|\n";
        cout << "| 1. Health_Potion                       |           3 Golds                |\n";
        cout << "| --------------------------------------------------------------------------|\n";
        cout << "| 2. Strength_Tonic (adds 3 to attack)   |           5 Golds                |\n";
        cout << "| --------------------------------------------------------------------------|\n";
        cout << "| 3. Defense_Tonic  (adds 3 to defense)  |           5 Golds                |\n";
        cout << "| --------------------------------------------------------------------------|\n";
        cout << "| 4. Speed_Tonic    (adds 3 to speed)    |           5 Golds                |\n";
        cout << "| --------------------------------------------------------------------------|\n";
        cout << "You have " << player->getGold() << " gold." << endl;
        cout << "Enter the number of your desired item" << endl;
        cout << "Enter '5' to view Purchased Item." << endl;
        cout << "Enter '6' to sell items." << endl;
        cout << "Enter '7' to quit." << endl;
        cout << "> ";
        cin >> choice;

        if (choice == "1" && player->getGold() >= 3)
        {
            cout << "Health Potion Bought ! " << endl;
            player->setPotions(player->getPotions() + 1);
            player->setGold(player->getGold() - 3);
            appendList("", "Health_Potion", "3");
            clearOutput();
        }
        else if (choice == "2" && player->getGold() >= 5)
        {
            cout << "Strength tonic Bought! " << endl;

            player->buffWeapon("weapon", 3);
            player->setGold(player->getGold() - 5);
            appendList("weapon", "Strength_Tonic", "5");
            clearOutput();
        }
        else if (choice == "3" && player->getGold() >= 5)
        {
            cout << "Defense tonic Bought! " << endl;
            player->buffArmor("armor", 3);
            player->setGold(player->getGold() - 5);
            appendList("armor", "Defense_Tonic", "5");
            clearOutput();
        }
        else if (choice == "4" && player->getGold() >= 5)
        {
            cout << "Speed tonic Bought! " << endl;
            player->buffShoe("shoe", 3);
            player->setGold(player->getGold() - 5);
            appendList("shoe", "Speed_Tonic", "5");
            clearOutput();
        }
        else if (choice == "5")
        {
            cout << "Purchased Item.." << endl;
            displayPurchased();
            clearOutput();
        }
        else if (choice == "6")
        {
            string name;
            cout << "Enter the name of the purchased item to sell. ( Remember the underscore! )" << endl;
            cin >> name;
            sellItem(name);
        }
        else if (choice == "7")
        {
            cout << "Exited." << endl;
            exitShop = true;
        }
        else
        {
            cout << "Invalid option." << endl;
        }
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
        cout << "\nName: " << nodePtr->ItemName << endl;
        cout << "Price: " << nodePtr->Itemprice << endl;
        nodePtr = nodePtr->nextNode;
    }

    cout << endl;
}

void Shop::appendList(string t, string n, string p)
{ // Pointer for new node (Node to do operations with)
    ListNode *newNode;
    // Pointer to traverse through list
    ListNode *nodePtr;

    newNode = new ListNode;
    newNode->ItemType = t;
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

void Shop::sellItem(string n)
{
    ListNode *nodePtr = head;
    ListNode *prevNode = nullptr;

    // Traverse the list to find the node to delete
    while (nodePtr != nullptr && nodePtr->ItemName != n)
    {
        prevNode = nodePtr;
        nodePtr = nodePtr->nextNode;
    }

    // If the node to delete is found
    if (nodePtr != nullptr)
    {
        // If the node to delete is the head node
        if (prevNode == nullptr)
        {
            head = nodePtr->nextNode;
        }
        else
        {
            prevNode->nextNode = nodePtr->nextNode;
        }
        player->setGold(player->getGold() + stoi(nodePtr->Itemprice));
        player->nerfEquipment(nodePtr->ItemType);
        // Delete the node
        delete nodePtr;
        cout << "Item \"" << n << "\" sold." << endl;
    }
    else
    {
        cout << "Item \"" << n << "\" not found." << endl;
    }
    clearOutput();
}

void Shop::clearOutput()
{
    cout << "Press enter to continue . . .";
    cin.ignore();
    cin.get();
    cout << "\033[2J\033[1;1H";
}