# CPC113 Hackathon 2
> **MEMBERS**

**1.** `ANG DE JIE`

**No. Matric -** `164049`

**2.** `ANSON KIU YI KAI`

**No. Matric -** `164554`

**3.** `AXLER CHIN SHUN YUAN`

**No. Matric -** `162331`

> GROUP NUMBER

`Group 40`

> INTRODUCTION

We are from `Group 40`. This is our first game we ever made by using  `C++` programming language. The game is called **Spire of Sin**.

**Spire of Sin** is an immersive and captivating role-playing game (RPG) that delves into a dark and morally world.

> HOW TO RUN THE GAME

Here are the `.cpp` files that are necessary to run as a command:
```txt
Creature.cpp Menu.cpp Player.cpp main.cpp Stage0.cpp Stage1.cpp Stage2.cpp Stage3.cpp Stage4.cpp Stage5.cpp Stage6.cpp Inventory.cpp SaveLoad.cpp Shop.cpp
```

Installed any IDE which support `c++`, copy and paste this `command` into the `command prompt`. We take `Visual Studio Code` + `MSYS2` as example:
```txt
// Copy this comamand and paste it into the command prompt.
g++ Creature.cpp Menu.cpp Player.cpp main.cpp Stage0.cpp Stage1.cpp Stage2.cpp Stage3.cpp Stage4.cpp Stage5.cpp Stage6.cpp Inventory.cpp SaveLoad.cpp Shop.cpp -o main.exe
```

> GAME DESCRIPTION

You are an `exile` and wake up in a mysterious room with no memory, you don't know how you get here. Suddenly, you heard voices surroud you but you don't where are they from.
You awaken to a voice beckoning you to wake up, and you tell yourself you have to **ESCAPE** from this haunted area. Discover the mysterious area, `battle` fearsome `monsters`, 
and unlock the `chests` in **Spire of Sins**, a captivating RPG that challenges your morality and tests the limits of your resolve.

> GAMEPLAY

- Choose your `path`

While playing the game, the players are able to make their own decision in some scenarios. The choice they made will affect their future.

Here is an example of the scenarios:
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

- Deal with `actions`
  
The players are able to deal with `actions` while exploring the mysterious area in the game. 

This is the `action` menu:
```c++
Type 'walk' to move forward ...
Type 'wait' to rest ...
Type 'view' to view inventory ...
Type 'stats' to view current stats...
Type 'exit' to exit the game...
> _
```

- Fight with the `monsters`

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

- Unlock the `chests`

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

- Stay your determination to continue moving forwards

We know that it is **not really easy** for the players (YOU) to beat the game. So, please stay your **determination** :)

`Congrats !`:
```c++
                                                                    ###
     ####    ####   #    #   ####   #####     ##   #####   ####     ###
    #    #  #    #  ##   #  #    #  #    #   #  #    #    #         ###
    #       #    #  # #  #  #       #    #  #    #   #     ####      # 
    #       #    #  #  # #  #  ###  #####   ######   #         #       
    #    #  #    #  #   ##  #    #  #   #   #    #   #    #    #    ###
     ####    ####   #    #   ####   #    #  #    #   #     ####     ###
```
