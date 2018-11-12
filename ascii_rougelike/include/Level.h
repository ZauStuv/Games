#ifndef LEVEL_H
#define LEVEL_H

#define MAX_LEVEL_DIMENSION 200

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <list>
#include <random>
#include <time.h>

#include "LoadSaveGame.h"
#include "GlobalOptions.h"
#include "Character.h"
#include "Shop.h"
#include "Enemy.h"
#include "Menu.h"
#include "SaveState.h"

#include "PaintScreen.h"
//#include "Item.h"
using namespace std;

class Level
{
    public:
        Level();
        void newGame(LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions);
        void loadGame(LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions);
        //Getters:


        //Setters:

    private:



        bool enemyMove(list<Enemy> &cEnemy, Character &cPlayer, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION]);
        //load level:
        bool loadLevel(int level, LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions, Character &cPlayer);
        //load level from saved game:
        bool loadLevel(int level, LoadSaveGame &cGameLoaderSaver, GlobalOptions cOptions, Character &cPlayer, SaveState cState);
        //Make random coordinate for level objects:
        void randomizer(GlobalOptions &cOptions, Shop &cRandShop, LoadSaveGame &cRandSaveState, Character &cRandPlayer, list<Enemy> &randEnemies, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int ladderCoordinates[2]);
        //Gets a random empty field inside the walls:
        void getRandomCoordinateForMap(int &myX, int &myY, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION]);
        void getRandomCoordinateForMapEnemies(int &myX, int &myY, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION]);
        void resetRandomCoordinates(char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION]);
        //waits for the player to input a character, then evaluate it:
        char playerMove(Character &cPlayer, Menu &playerMenu, Shop &cShop, list<Enemy> &cEnemies, LoadSaveGame &cSaveState, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int levelNum, GlobalOptions &cOptions, int ladderCoordinates[2]);
        //painter variable:
        PaintScreen _cPaint;
};

#endif // LEVEL_H
