#include "Player.h"
#include "Inventory.h"
#include <iostream>
using namespace std;

Player ::Player()
{
    level = 1;
    name = "";
    potions = 0;
}

Player ::~Player()
{
}

Player ::Player(string n, int lvl, int hp, int atk, int df, int spd, int pt) : Creature(hp, atk, df, spd)
{
    name = n;
    level = lvl;
    potions = pt;
}

// Player ::Player(int hp, int atk, int df, int spd, int lvl) : Creature(hp, atk, df, spd)
// {
//     level = lvl;
// }

bool Player ::alive()
{
    if (getHP() > 0)
        return true;
    else
        return false;
}

void Player ::battle(Creature Enemy) // fighting with what enemy
{

    string action;
    int hp;

    setAtk(inventory->getWeaponValue());
    setDefense(inventory->getArmorValue());
    setSpeed(inventory->getShoeValue());

    while (Enemy.StageEnemyAlive() && alive()) // while Enemy and player is not die
    {
        // static int round = 1;
        // countround(round);
        srand(time(0));
        unsigned int randNumDodgePlayer = rand() % 30 + 1;           // for dodge (player)
        unsigned int randNumDodgeEnemy = rand() % 20 + 1;            // for dodge (enemy)
        unsigned int randNumBlockDamage = rand() % getDefense() + 1; // for blocking damage
        unsigned int randNumCounterAtk = rand() % getAtk() + 1;      // for counter attack
        showBattleInfo(Enemy);                                       // print player's status and enemy's status
        cin >> action;

        if (action == "attack" || action == "Attack" || action == "ATTACK" || action == "1")
        {
            hp = Enemy.getHP() - getAtk();
            Enemy.setHP(hp); // set enemy's HP attack player attack

            if (Enemy.StageEnemyAlive()) // if enemy still alive
            {
                // cout << "LuckNumber " << randomNum << endl; //this code is just used to detect any error in dodging
                if (randNumDodgePlayer <= getSpeed()) // attack + dodge (player)
                {
                    cout << "You successfully hit the enemy ! " << endl;
                    cout << "The enemy lost " << getWeaponValue() << " HP." << endl;
                    cout << "Oh no ! The enemy counter attacked you !" << endl;
                    cout << "Well done ! You dodged the attack !" << endl;
                    clearOutput();
                    continue;
                }
                else // attack only (player)
                {
                    if (randNumDodge)
                        cout << "You successfully hit the enemy ! " << endl;
                    cout << "The enemy lost " << getWeaponValue() << " HP." << endl;
                    cout << "Oh no ! The enemy counter attacked you !" << endl;
                    cout << "You lost " << Enemy.getAtk() << " HP." << endl;
                    clearOutput();
                    setHP(getHP() - Enemy.getAtk());
                }
            }
        }
        else if (action == "defense" || action == "Defense" || action == "DEFENSE" || action == "2")
        {
            // cout << "LuckNumber " << randomNum << endl; //this code is just used to detect any error in dodging
            if (Enemy.getAtk() > getDefense())
            {
                if (randomNum <= getSpeed()) // dodge
                {
                    cout << "Nice ! Successfully dodged the enemy's attack !" << endl;
                    clearOutput();
                    continue;
                }
                else // fail to dodge and get hurt
                {
                    cout << "You lost " << (Enemy.getAtk() - getDefense()) << " HP ";
                    cout << "because you have " << getDefense() << " points of armor ! " << endl;
                    clearOutput();
                    hp = getHP() - (Enemy.getAtk() - getDefense());
                    setHP(hp);
                }
            }
            else
            {
                cout << "Enemy's attack blocked !" << endl;
                clearOutput();
            }
        }
        else if (action == "potion" || action == "Potion" || action == "POTION" || action == "3")
        {
            if (potions > 0)
            {
                if (getHP() <= getMaxHealth())
                {
                    cout << "Potion is used successfully. 5 HP recovered." << endl;
                    clearOutput();
                    setHP(getHP() + 5);
                    setPotions(getPotions() - 1);
                }
                else if ((getMaxHealth() - getHP()) < 5)
                {
                    clearOutput();
                    setHP(getMaxHealth());
                }
                else
                {
                    cout << "HP is full ! No potions used." << endl;
                    clearOutput();
                }
            }
            else
            {
                cout << "Oh boy, there is no potion left in your inventory." << endl;
                clearOutput();
                continue;
            }
        }
        else
        {
            cout << "You can only attack, defense or use potions in this round." << endl;
            clearOutput();
        }
    }
}

// Pls modify this part code for better UI
void Player ::showBattleInfo(Creature Enemy)
{
    cout << setw(66) << "Enemy's HP: " << Enemy.getHP() << endl;
    cout << setw(70) << "Enemy's Attack: " << Enemy.getAtk() << endl;
    cout << "\n\n\n"
         << setw(72) << "__________________________" << endl;
    cout << setw(7) << right << getName() << "  (Level: " << getLvl() << ")" << setw(26) << right << "|" << setw(26) << right << "|" << endl;
    cout << setw(9) << right << "HP: " << setw(6) << right << getHP() << setw(57) << right << " |Now, Choose your action: |" << endl;
    cout << setw(9) << right << "Attack: " << setw(6) << right << getAtk() << setw(41) << right << " |1. Attack " << setw(16) << " |" << endl;
    cout << setw(9) << right << "Defense: " << setw(6) << right << getDefense() << setw(42) << right << "|2. Defense " << setw(16) << " | " << endl;
    cout << setw(9) << right << "Speed: " << setw(6) << right << getSpeed() << setw(41) << right << "|3. Potion " << setw(16) << " |" << endl;
    cout << "Potions Left: " << getPotions() << setw(57) << right << "|_________________________|" << endl;
    cout << "\nEnter your action:" << endl;
    cout << "> ";
}

string Player::getName()
{
    return name;
}

void Player::setName(string n)
{
    name = n;
}

int Player::getPotions()
{
    return potions;
}

void Player::setPotions(int value)
{
    potions = value;
}

int Player::getGold()
{
    return gold;
}

void Player::setGold(int g)
{
    gold = g;
}

int Player ::getLvl()
{
    return level;
}

void Player::initialiseInventory()
{
    inventory->appendNode("weapon", "None", 0);
    inventory->appendNode("armor", "None", 0);
    inventory->appendNode("shoe", "None", 0);
}

void Player::pickItem(string type, string name, int value)
{
    inventory->updateInventory(type, name, value);
}

void Player::levelup()
{
    level++;
    maxHP = maxHP + 5;
}
int Player ::getMaxHealth()
{
    return maxHP;
}

void Player ::setLevel(int l)
{
    level = l;
}

string Player ::getWeapon()
{
    return inventory->getWeapon();
}

string Player ::getArmor()
{
    return inventory->getArmor();
}

string Player ::getShoe()
{
    return inventory->getShoe();
}

int Player ::getWeaponValue()
{
    return inventory->getWeaponValue();
}

int Player ::getArmorValue()
{
    return inventory->getArmorValue();
}

int Player ::getShoeValue()
{
    return inventory->getShoeValue();
}

void Player::showInventory()
{
    inventory->showInventory();
    cout << "Potions: " << getPotions() << endl;
    cout << "Gold: " << getGold() << endl;
}

void Player::clearOutput()
{
    cout << "Press enter to continue . . .";
    cin.ignore();
    cin.get();
    cout << "\033[2J\033[1;1H";
}

void Player::showStats()
{
    setAtk(inventory->getWeaponValue());
    setDefense(inventory->getArmorValue());
    setSpeed(inventory->getShoeValue());
    cout << "Max HP: " << getMaxHealth() << endl;
    cout << "Current HP: " << getHP() << endl;
    cout << "Attack: " << getAtk() << endl;
    cout << "Defense: " << getDefense() << endl;
    cout << "Speed: " << getSpeed() << endl;
}
