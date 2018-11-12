#ifndef LOADSAVEGAME_H
#define LOADSAVEGAME_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>
#include <conio.h>
#include <list>
#include "Item.h"
#include "PaintScreen.h"
#include "SaveState.h"

using namespace std;


class LoadSaveGame
{
    public:
        LoadSaveGame();
        void saveGame();
        void openLoadMenu(PaintScreen &cPaint, SaveState &state);
        void openSaveMenu(PaintScreen &cPaint, int levelNum, int numOfEnemies, bool saveDuringGame, bool shopAvailable, int currHealth, int maxHealth, int exp, int money, char stat, int shopXcoordinate, int shopYcoordinate, int saveXcoordinate, int saveYcoordinate, int playerXcoordinate, int playerYcoordinate, int ladderCoordinates[2], list<Item> &playerItems);


        //getters:
        int* getCoordinates();
        SaveState getSaveState(int ssNumber);
        int getSaveMenuKey();
        int getSaveMenuArrow();
        int getLoadMenuKey();
        int getLoadMenuArrow();

        //setters:
        void setCoordinates(int x, int y);
        void setSaveMenuKey(int saveMenuKey);
        void setSaveMenuArrow(int saveMenuArrow);
        void setLoadMenuKey(int loadMenuKey);
        void setLoadMenuArrow(int loadMenuArrow);



    private:

        //input file:
        ifstream _loadGame;
        ifstream _loadSaveFile;
        ofstream _saveGame;

        //savestate settings:
        int _coordinates[2];

        //savestate objects [3]:
        SaveState _saveStates[3];


        //Save menu settings:
        char _saveMenuKey;
        int _saveMenuArrow;

        //Load menu settings:
        char _loadMenuKey;
        int _loadMenuArrow;

        //save the game to a file:
        void saveGameState(int stateNum, PaintScreen &cPaint, int levelNum, int numOfEnemies, bool saveDuringGame, bool shopAvailable, int currHealth, int maxHealth, int exp, int money, char stat, int shopXcoordinate, int shopYcoordinate, int saveXcoordinate, int saveYcoordinate, int playerXcoordinate, int playerYcoordinate, int ladderCoordinates[2], list<Item> &playerItems);

        //Player settings:

        //<list of items>
        //<experience points>
        //<money>
};

#endif // LOADSAVEGAME_H
