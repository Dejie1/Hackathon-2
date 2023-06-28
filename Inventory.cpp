#include "Inventory.h"
#include <string>
using namespace std;

Inventory ::Inventory() // Creatre 3 Node which has types of weapon, armor, shoe
{
    head = nullptr;
}

Inventory ::~Inventory() // detele nodes in inventory as program is closed, to deallocate memomry
{
    Node *nodePtr = nullptr, *curNode = nullptr;
    if (head)
    {
        nodePtr = head;
        while (nodePtr->next)
        {
            curNode = nodePtr;
            nodePtr = nodePtr->next;
            delete curNode;
        }
    }
}

void Inventory ::appendNode(string type, string name, int value) // use in constructor, to create 3 Nodes
{
    Node *nodePtr = nullptr;
    Node *newNode = new Node;
    newNode->itemType = type;
    newNode->itemValue = value;
    newNode->itemName = name;
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;
        while (nodePtr->next) // traverse to last Node
            nodePtr = nodePtr->next;
        nodePtr->next = newNode;
    }
}

void Inventory ::showInventory() // traverse the Linked List and print all the itemName and its value
{
    Node *nodePtr = head;
    if (nodePtr)
    {
        while (nodePtr)
        {
            if (nodePtr->itemType == "weapon")
            {
                cout << "Weapon: \"" << nodePtr->itemName << "\"" << endl;
                cout << "Attack: " << nodePtr->itemValue << endl;
                nodePtr = nodePtr->next;
            }
            else if (nodePtr->itemType == "armor")
            {
                cout << "Armor: \"" << nodePtr->itemName << "\"" << endl;
                cout << "Defense: " << nodePtr->itemValue << endl;
                nodePtr = nodePtr->next;
            }

            else if (nodePtr->itemType == "shoe")
            {
                cout << "Shoe: \"" << nodePtr->itemName << "\"" << endl;
                cout << "Speed: " << nodePtr->itemValue << endl;
                nodePtr = nodePtr->next;
            }
        }
    }
}

int Inventory ::getWeaponValue()
{
    return head->itemValue;
}

int Inventory ::getArmorValue()
{
    return head->next->itemValue;
}

int Inventory ::getShoeValue()
{
    return head->next->next->itemValue;
}

void Inventory::updateInventory(string type, string name, int value)
{
    Node *nodePtr;
    nodePtr = head;
    if (type == "weapon")
    {
        nodePtr->itemName = name;
        nodePtr->itemValue = value;
    }
    else if (type == "armor")
    {
        nodePtr->next->itemName = name;
        nodePtr->next->itemValue = value;
    }
    else if (type == "shoe")
    {
        nodePtr->next->next->itemName = name;
        nodePtr->next->next->itemValue = value;
    }
}

string Inventory ::getWeapon()
{
    return head->itemName;
}

string Inventory ::getArmor()
{
    return head->next->itemName;
}

string Inventory ::getShoe()
{
    return head->next->next->itemName;
}