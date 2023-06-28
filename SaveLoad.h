#ifndef SAVELOAD_H
#define SAVELOAD_H
#include "Player.h"
// #include "Stage0.h"
// #include "Stage1.h"
// #include "Stage2.h"
// #include "Stage3.h"
// #include "Stage4.h"
// #include "Stage5.h"
// #include "Stage6.h"
#include <fstream>

class SaveLoad
{
private:
    struct Node
    {
        int stage;
        Player player;

        Node *next;
    };
    Node *stackTop;

public:
    SaveLoad();
    ~SaveLoad();
    void savefile();
    int loadfile(Player *);
    void push(int, Player *);
    void pop();
    void show();
};

#endif