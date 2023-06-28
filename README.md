# CPT113 Hackathon 2
> **MEMBERS**

**1.** `ANG DE JIE`

**No. Matric -** `164049`

**2.** `ANSON KIU YI KAI`

**No. Matric -** `164554`

**3.** `AXLER CHIN SHUN YUAN`

**No. Matric -** `162331`

> GROUP NUMBER

**Group 40**

> INTRODUCTION

We are from **Group 40**. This is our first game we ever made by using  `C++` programming language. The game is called **Spire of Sin**. It is an immersive and captivating **text-based** role-playing game (RPG) that delves into a dark and morally world.

> HOW TO RUN THE GAME

- Here are the `.cpp` files that are necessary to run as a command:
```txt
Creature.cpp Menu.cpp Player.cpp main.cpp Stage0.cpp Stage1.cpp Stage2.cpp Stage3.cpp Stage4.cpp Stage5.cpp Stage6.cpp Inventory.cpp SaveLoad.cpp Shop.cpp
```

- Installed any IDE which support `c++`, copy and paste this command into the command prompt. We take `Visual Studio Code` + `MSYS2` as example:
```txt
// Copy this comamand and paste it into the command prompt.
g++ Creature.cpp Menu.cpp Player.cpp main.cpp Stage0.cpp Stage1.cpp Stage2.cpp Stage3.cpp Stage4.cpp Stage5.cpp Stage6.cpp Inventory.cpp SaveLoad.cpp Shop.cpp -o main.exe
```

> GAME DESCRIPTION

You are an `exile` and wake up in a mysterious room with no memory, you don't know how you get here. Suddenly, you heard voices surroud you but you don't where are they from.
You awaken to a voice beckoning you to wake up, and you tell yourself you have to **ESCAPE** from this haunted area. Discover the mysterious area, `battle` fearsome `monsters`, 
and unlock the `chests` in **Spire of Sins**, a captivating text-based RPG that challenges your morality and tests the limits of your resolve.

> GAME FEATURES
1. Interactive Menu
   
2. Multiple Ending (Later you will know)
   
3. Multiple Events
  - Statue
  - Suddenly encounted with enemy
    
4. Battle System
  - Attack
  - Defend
  - Use potion
  - Dodge
  - Blocking Damage
    
5. Random Chest System

6. Shop System
  - Buy item
  - Sell item
    
7. Save & Load

8. Player Stats
  - HP
  - ATK
  - DEF
  - SPEED
    
9. Inventory System
  - Weapon
  - Armor
  - Shoe
  - Gold
  - Potion

> HOW WE IMPLEMENTED OOP

We implement OPP for each `Stage` class. In this case, we use `composition` that allows the objects to be composed of other objects or components in our program.

For example: 

`Stage0` -> `Stage1` -> `Stage2` -> `Stage3` -> `Stage4` -> `Stage5` -> `Stage6`

When the `Stage 0` is finished, it will go to the next stage, `Stage1` and start loading the game.

We also implement OOP for `Player` class and `Creature` class. Our derived class is `Player` class and our base class is `Creature` class. The reason why we want to do this because we want the `Player` class inherits from `Creature` class to get the all the stats of the specific creature. For example the `slime`, so we are able to get the `HP`, `ATK`, `DEF`, `SPEED` of the `slime` to be used in our battle system.

> HOW LINKED LIST PLAY A ROLE IN OUR GAME

1.	The feature to save and load the game is achieved by Linked List. For instance, after each stage, the game is automatically saved. Behind the UI, it is a Stack structure managing this saving feature where it pushes each stage’s data into the structure.

2.	The feature of the Shop. For instance, at stage 3 and stage 5, you will get the opportunity to buy items. Once we check whether the player can buy the desired item, we push the item data into the Linked List. This is to simplify the process of showing the purchased item, which is the ‘Show Purchased’ option when the player is in the store.  Besides, the player also can sell items. Behind the UI, this selling item feature is accomplished by deleting the node of the item purchased. This is vital so that the player can have options to buy other items that are more beneficial to the run. 

3.	The feature of Inventory. The player’s inventory is essentially a Linked List that contains 3 nodes, Weapon, Armor, and Shoes. When the player acquires a new item, the values of the node, like the name, and the value, is updated. Showing inventory is also achieved by traversing the Linked List. This is vital because this Linked List allows player to have a working inventory. 


> GAMEPLAY

1. Choose your own `path`.

- While playing the game, the players are able to make their own decision in some scenarios. The choice they made will affect their future.
- Here is an example of the scenarios:
```c++
You wakes up in a mysterious room with no memory of how you get here ...
"Damn ... Its cold in here" You said as you slowly close your eyes once again ...
You heard voices ...

"Wake up, son ... Wake up, Ubicana. You dont have much time left ..."
"Is that ... God ? I don't care ... let me be ..."

Choose:
1. Slowly gets up ...
2. Continue sleeping
> _
```

2. Deal with `actions`.
  
The players are able to deal with `actions` while exploring the mysterious area in the game. 

This is the `action` menu:
```c++
Type 'walk' to move forward ...
Type 'wait' to rest ...
Type 'view' to view inventory ...
Type 'stats' to view current stats ...
Type 'exit' to exit the game ...
> _
```

3. Fight with the `monsters`.

The players will encounter with `monsters` for each stage. Every time you get into a new stage, the monsters will become stronger than ever.

Here is the `battle` menu:
```python
                                                          Enemy's HP: 10
                                                      Enemy's Attack: 2 
                                                       Enemy's Speed: 0 
Ubicana  (Level: 0)
                                              _________________________ 
                                             |                         |
     HP:     30                              |Now, Choose your action: |
 Attack:      5                              |1. Attack                | 
Defense:      0                              |2. Defense               | 
  Speed:      0                              |3. Potion                | 
Potions Left: 0                              |_________________________| 

Enter your action:
> _
```

4. Unlock the `chests`.

After finishing the battle, the player will able to unlock the `chests`. There are total of 3 `chests` for each stage.

Here is the `chests` menu:

```c++
You beated the slime ! And you found 3 chests behind the slime.
But ... Which one would you like to open ?
1. Rusty Chest
2. Rusty Chest
3. Rusty Chest
> _
```

5. Stay your determination to continue moving forwards.

We know that it is **not really easy** for the players (you) to beat the game. So, please stay your **determination** :)

6. Escape the haunted area.

If you **manage to beat the game**, you will see this message:
```c++
                                                                    ###
     ####    ####   #    #   ####   #####     ##   #####   ####     ###
    #    #  #    #  ##   #  #    #  #    #   #  #    #    #         ###
    #       #    #  # #  #  #       #    #  #    #   #     ####      # 
    #       #    #  #  # #  #  ###  #####   ######   #         #       
    #    #  #    #  #   ##  #    #  #   #   #    #   #    #    #    ###
     ####    ####   #    #   ####   #    #  #    #   #     ####     ###
```
That's is, **good luck** my `exile` !
