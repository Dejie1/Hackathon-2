#ifndef PLAYER_H
#define PLAYER_H
#include "Inventory.h"
#include "Creature.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class Player : public Creature
{
private:
    string name;
    int level;
    int potions = 0;
    int gold = 0;
    int maxHP = 30;
    string dummyVariable;
    Inventory inventoryObject;
    Inventory *inventory = &inventoryObject;

public:
    Player();
    ~Player();
    // Player(int, int, int, int, int);
    Player(string, int, int, int, int, int, int);
    void battle(Creature);
    void showBattleInfo(Creature);
    void setName(string);
    void setPotions(int);
    void setLevel(int);
    void pickItem(string, string, int);
    string getName();
    int getPotions();
    int getLvl();
    string getWeapon();
    string getArmor();
    string getShoe();
    int getWeaponValue();
    int getArmorValue();
    int getShoeValue();
    void levelup();
    bool alive();
    int getMaxHealth();
    void initialiseInventory();
    void showInventory();
    void clearOutput();
    int getGold();
    void setGold(int);
    void showStats();
    void buffWeapon(string, int);
    void buffArmor(string, int);
    void buffShoe(string, int);
    void nerfEquipment(string);
    void setMaxHP(int);
    int getMaxHP();
};

#endif