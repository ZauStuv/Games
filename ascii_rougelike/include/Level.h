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

        /** @brief: initializes the start of a new game.
        *
        *   The function sets the level number to 1, initializes the player settings (so that it will
        *   not be reinitialized after player has completed the level), then enters into an endless loop
        *   which can be broken only if the <loadLevel()> returns false, or levelNum would be larger than
        *   9 (player has completed the final level).
        *
        *   @param: cGameLoaderSaver: there will be a singe loader-saver object during the whole game to handle
        *           the save requests, cOptions: contains all the global game settings which will be applied for
        *           each level, or the initial settings for the player to pass once before the game starts.
        *   @return: void
        */
        void newGame(LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions);

        /** @brief: loads an existing game state.
        *
        *   It loads first the gamestate loader menu, where you can choose which state out of 3 you would like
        *   to continue. All the options of the previous state will be loaded into the cState class. Then, this
        *   class will overwrite all the global and player settings. After that, a similar <loadLevel> function
        *   will be called as for a new game, only with the cState setting passed to it as an addition, to set
        *   the number of enemies and the coordinates of the map objects as they were at the moment of the save.
        *
        *   @param:CGameLoaderSaver: has all the necessary datas stored to restore the parameters of the last save,
        *          cOptions: the global options for the game. These will be used the same way as in a new game.
        *   @return: void
        */
        void loadGame(LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions);
        //Getters:


        //Setters:

    private:


        /** @brief: gives the chance to each enemy to make a move
        *
        *   This function scrolls through all enemies currently available in the map, and gives them by random chance
        *   the opportunity to move in 1 of the four directions, if the neighbouring field is empty (a '.') character.
        *   If the player gets next to the enemy, the enemy will always attack the player, instead of moving.
        *
        *   @param: cEnemy: the list of enemies, which will make a random move, one after another, cPlayer: the player
        *           which the enemies might cause damage to, levelMap[][]: the size of the map where the enemies can
        *           move around.
        *
        *   @return: true if the player has been killed by an enemy, false if not.
        */
        bool enemyMove(list<Enemy> &cEnemy, Character &cPlayer, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION]);

        /** @brief: initializes the level and every object inside it.
        *
        *   This version of this function will be called in case of a new game.
        *   After opening the actual level file, the coordinate of each field will be stored in a 2d array in <levelMap[][]>,
        *   then it goes on with the initialization of the player menu, the number of enemies, and giving random coordinates
        *   to each object on the map on the empty fields.
        *   Then, in an endless loop, the displaying of the map will happen, and then in each round, the player and the enemies
        *   will get the chance to make a move, until the player quits, finishes the level, or is killed by an enemy or poisoning.
        *
        *   @param: level: the actual number of the level, cGameLoaderSaver: the object which stores the coordinates of the safe house
        *           (among others), cOptions: the global options of the game, cPlayer: the player object, with all its parameters.
        *
        *   @return: true if the player has completed the level and escaped through the ladder, false if the player was killed
        *            by an enemy, died of poisoning, or quitted the game in the player menu.
        */
        bool loadLevel(int level, LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions, Character &cPlayer);

        /** @brief: initializes the level and every object inside it.
        *
        *   This version of this function will be called in case of a loaded game.
        *   After opening the actual level file, the coordinate of each field will be stored in a 2d array in <levelMap[][]>,
        *   then it goes on with the initialization of the player menu, the number of remaining enemies if the player has just loaded
        *   the savestate, and after giving random coordinates to each object, the shop, safe house, player and ladder coordinates
        *   will be loaded from the <cState> object to recreate the last save state.
        *   Then, in an endless loop, the displaying of the map will happen, and then in each round, the player and the enemies
        *   will get the chance to make a move, until the player quits, finishes the level, or is killed by an enemy or poisoning.
        *
        *   @param: level: the actual number of the level, cGameLoaderSaver: the object which stores the coordinates of the safe house
        *           (among others), cOptions: the global options of the game, cPlayer: the player object, with all its parameters.
        *           cState: the savestate object, which holds all the informations from the chosen save state.
        *
        *   @return: true if the player has completed the level and escaped through the ladder, false if the player was killed
        *            by an enemy, died of poisoning, or quitted the game in the player menu.
        */
        bool loadLevel(int level, LoadSaveGame &cGameLoaderSaver, GlobalOptions cOptions, Character &cPlayer, SaveState cState);

        /** @brief: gives a random coordinate to every object on the map.
        *
        *   The funcion goes through each object which has been created before, and loads their x and y coordinates
        *   with a value inside the maximum map dimensions.
        *
        *   @param: cOptions: the global game options. It's for deciding if the shop or safe house were enabled, and should also get a random
        *           coordinate, cRandShop: the shop object, cRandPlayer: the player object, randEnemies: the list of enemy objects, levelMap[][]:
        *           the 2d array filled up with the characters from the map file, ladderCoordinates[]: stores the x and y coordinates for the ladder.
        *   @return: void
        */
        void randomizer(GlobalOptions &cOptions, Shop &cRandShop, LoadSaveGame &cRandSaveState, Character &cRandPlayer, list<Enemy> &randEnemies, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int ladderCoordinates[2]);

        /** @brief: sets a random number for coordinate X and Y
        *
        *   sets a random number for coordinate X and Y inside the range of the map. the value will only be valid if the
        *   coordinate is an empty field '.' on the <levelMap[][]> array. The funtion loops until it randomly finds
        *   such an empty field, then it gives the random coordinates to <myX> and <myY> respectively.
        *   This funcion fill be used by shops, safe houses and ladders so that there will be no object or wall above,
        *   below and next to these objects.
        *
        *   @param: myX: the X coordinate for an object, myY: the Y coordinate for an object, levelMap[][]: the 2d array which
        *           stores the level map characters.
        *   @return: void
        */
        void getRandomCoordinateForMap(int &myX, int &myY, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION]);

        /** @brief: sets a random number for coordinate X and Y
        *
        *   sets a random number for coordinate X and Y inside the range of the map. the value will only be valid if the
        *   coordinate is an empty field '.' on the <levelMap[][]> array. The funtion loops until it randomly finds
        *   such an empty field, then it gives the random coordinates to <myX> and <myY> respectively.
        *   This funcion fill be used by enemies or characters, which can spawn on any empty space on the level,
        *   possibly even next to each other.
        *
        *   @param: myX: the X coordinate for an object, myY: the Y coordinate for an object, levelMap[][]: the 2d array which
        *           stores the level map characters.
        *   @return: void
        */
        void getRandomCoordinateForMapEnemiesAndPlayer(int &myX, int &myY, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION]);

        /** @brief: waits for the player to input a character, then evaluates it.
        *
        *   The function first waits until it gets a letter from the user input, then if it's either of wsad, it moves to up/down/left/right
        *   if there is an open space next to the player, or interacts with the object if the object coordinates are the same where the
        *   player would move. If player presses enter, the player menu opens up.
        *
        *   @param: cPlayer: the player object. Its coordinates will change when moving, or health or exp can change if it attacks an enemy.
        *           playerMenu: the menu for the player. It can be opened by pressing enter during the main game (when map is visible).
        *           cShop: the shop objects, whose menu opens when the player wants to walk to the field where the shop character 'M' resides.
        *           cEnemies: the list of enemies the player can interact. They are represented with an 'S' character in the map.
        *           The interaction will occur if the player is next to an enemy
        *           (diagonal proximity does not count). If the enemy is defeated, the player gains some experience points and money.
        *           cSaveState: the savestate object, which is represented with a 'Q' character. If player would like to step onto it,
        *           the save menu would be opened.
        *   @return: 'h', if the player steps onto the ladder. This means, the player has completed the level.
        *            'q', if the player wants to quit the game via the player menu.
        *            'c', if neither of above has happened, the player has completed his turn, and the game can continue.
        */
        char playerMove(Character &cPlayer, Menu &playerMenu, Shop &cShop, list<Enemy> &cEnemies, LoadSaveGame &cSaveState, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int levelNum, GlobalOptions &cOptions, int ladderCoordinates[2]);
        //painter variable:
        PaintScreen _cPaint;
};

#endif // LEVEL_H
