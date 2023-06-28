#include <iostream>
#include <string>
#include <Windows.h>
#include "Menu.h"
#include "Stage0.h"
#include "Stage1.h"
#include <stdlib.h>
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"
using namespace std;

Menu::Menu() {}

Menu::~Menu() {}

void Menu::ShowMenu()
{
    system("cls");
    cout << " #####  ######  ### ######  #######    ####### #######     #####  ### #     # " << endl;
    cout << "#     # #     #  #  #     # #          #     # #          #     #  #  ##    # " << endl;
    cout << "#       #     #  #  #     # #          #     # #          #        #  # #   # " << endl;
    cout << " #####  ######   #  ######  #####      #     # #####       #####   #  #  #  # " << endl;
    cout << "      # #        #  #   #   #          #     # #                #  #  #   # # " << endl;
    cout << "#     # #        #  #    #  #          #     # #          #     #  #  #    ## " << endl;
    cout << " #####  #       ### #     # #######    ####### #           #####  ### #     # " << endl;
    cout << endl;
    cout << "Choose: " << endl;
    cout << "1. Start the game. " << endl;
    cout << "2. Load Game. " << endl;
    cout << "3. Exit. " << endl;
    cout << "> ";
    cin >> MenuControl;

    while (MenuControl != "1" && MenuControl != "2" && MenuControl != "3")
    {
        cout << "Invalid command. Please try again.\n";
        cout << "> ";
        cin >> MenuControl;
    }

    if (MenuControl == "1")
    {
        // Start the story + level1
        stage0->loadLevel();
    }
    if (MenuControl == "2")
    {
        string choose;
        // Load the game
        SavePtr->show();
        cout << "> ";
        cin >> choose;

        while (choose != "y" && choose != "yes" && choose != "n" && choose != "no" && choose != "No" && choose != "NO")
        {
            cout << "Sorry, I dont recognize " << choose << endl;
            cout << "\n> ";
            cin >> choose;
        }

        if (choose == "y" || choose == "yes")
        {
            int stage = SavePtr->loadfile(plyPtr);
            if (stage == 1)
            {
                Stage1 stage1(plyPtr, SavePtr);
                stage1.loadLevel();
            }
            else if (stage == 2)
            {
                Stage2 stage2(plyPtr, SavePtr);
                stage2.loadLevel();
            }
            else if (stage == 3)
            {
                Stage3 stage3(plyPtr, SavePtr);
                stage3.loadLevel();
            }
            else if (stage == 4)
            {
                Stage4 stage4(plyPtr, SavePtr);
                stage4.loadLevel();
            }
            else if (stage == 5)
            {
                Stage5 stage5(plyPtr, SavePtr);
                stage5.loadLevel();
            }
            else if (stage == 0)
            {
                cout << "There is no game saved in file." << endl;
            }
            else if (stage == 6)
            {
                Stage6 stage6(plyPtr, SavePtr);
                stage6.loadLevel();
            }
        }
        else if (choose == "n" || choose == "no" || choose == "No" || choose == "NO")
        {
            ShowMenu();
        }
    }
    if (MenuControl == "3")
    {
        exit(3);
    }
}

void Menu::gameOver()
{
    cout << "#   #  ####### #     #    ######  ### ####### ######  " << endl;
    cout << " # #   #     # #     #    #     #  #  #       #     # " << endl;
    cout << "  #    #     # #     #    #     #  #  #####   #     # " << endl;
    cout << "  #    #     # #     #    #     #  #  #       #     # " << endl;
    cout << "  #    #     # #     #    #     #  #  #       #     # " << endl;
    cout << "  #    #######  #####     ######  ### ####### ######  " << endl;
}

void Menu::congratMessage()
{
    cout << "                                                                 ###" << endl;
    cout << "  ####    ####   #    #   ####   #####     ##   #####   ####     ### " << endl;
    cout << " #    #  #    #  ##   #  #    #  #    #   #  #    #    #         ### " << endl;
    cout << " #       #    #  # #  #  #       #    #  #    #   #     ####      #  " << endl;
    cout << " #       #    #  #  # #  #  ###  #####   ######   #         #        " << endl;
    cout << " #    #  #    #  #   ##  #    #  #   #   #    #   #    #    #    ### " << endl;
    cout << "  ####    ####   #    #   ####   #    #  #    #   #     ####     ###  " << endl;
}
