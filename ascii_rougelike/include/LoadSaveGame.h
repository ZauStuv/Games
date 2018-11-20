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

        /** @brief:Loads the contence of the save files at the beginning of the game.
        *
        *   In the main menu, after enter has been pressed, all the contence of the existing save files is loaded
        *   into the <_saveStates[3]> objects, and can be used later to change the game parameters back to that of
        *   the last game save.
        *
        *   @param:
        *   @return: void
        */
        LoadSaveGame();

        /** @brief: Opens the menu to load one of the saved game states.
        *
        *   The function stays in an endless loop which polls the player to navigate with 'w' or 's' in
        *   the menu and choose the wished save state or return to the game by pressing "enter".
        *   Selects 1 of the 3 save states, and loads the content of it to the <state> variable,
        *   passed as a parameter of the function.
        *   @param:cPaint: needed object to display the menu for the player, state: this objects gets all the content
        *          of the selected save state.
        *   @return: return "true" if one of the save states will be loaded, "false" if the player choose to go back to the main menu.
        */
        bool openLoadMenu(PaintScreen &cPaint, SaveState &state);

        /** @brief: Opens the menu to save the current game states.
        *
        *   The function stays in an endless loop which polls the player to navigate with 'w' or 's' in
        *   the menu and choose the wished save state to overwrite or return to the game by pressing "enter".
        *   The number stored in the arrow (and changed by pressing 'w' or 's' buttons), determines how the
        *   <saveGameState()> will be called, and thus, which save file will be overwritten.
        *
        *   @param:cPaint: needed object to display the menu for the player, levelNum: the current level number in the game, maxNumOfEnemies: the initial number of enemies on each
        *          game level, set by the global options, currNumOfEnemies: the current number of enemies on the map, saveDuringGame: if there is a save house available on the map,
        *          shopAvailable: if there is shop enabled in the game, currHealth: the current health of the player, maxHealth: the maximum health of the player, determined by the
        *          game options, exp: the total experience points of the player, money: the money of the player, stat: the current status condition of the player,
        *          shopXcoordinate: the X coordinate of the shop, shopYcoordinate: the Y coordinate of the shop, saveXcoordinate: the X coordinate of the safe house, SaveYcoordinate:
        *          the Y coordinate of the safe house, PlayerXcoordinate: the X coordinate of the player, PlayerYcoordinate: the Y coordinate of the player, ladderCoordinates[2]:
        *          the X and Y coordinates of the ladder, equippedDefenceItem: the shield currently equipped at the player, equippedAttackItem: the wearpon currently equipped at the player,
        *          playerItems: the list of all the items the player currently has.
        *
        *   @return: void
        */
        void openSaveMenu(PaintScreen &cPaint, int levelNum, int maxNumOfEnemies, int currNumOfEnemies, bool saveDuringGame, bool shopAvailable, int currHealth, int maxHealth, int exp, int money, char stat, int shopXcoordinate, int shopYcoordinate, int saveXcoordinate, int saveYcoordinate, int playerXcoordinate, int playerYcoordinate, int ladderCoordinates[2], string equippedDefenceItem, string equippedAttackItem, list<Item> &playerItems);


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
        ifstream _loadSaveFile;
        //output file:
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
        /** @brief: Loads the current game details into a file.
        *
        *   This function does the details of writing each parameter which should be stored, into a text file, each parameter in a new
        *   row. The list ends with the player items (name, number of, attack and defence) and has an empty line between each item.
        *   Every parameter (even the integers) will be stored in the save file as a string.
        *   Before creating or overwriting the existing save file. the screen will be wiped clean, and the player will be promted to
        *   give a name to the previously chosen save state (out of the 3 possible ones).
        *
        *   @param: stateNum: the number of savestate. It can be 0 or 1 or 2,
        *   @return: void
        */
        void saveGameState(int stateNum, PaintScreen &cPaint, int levelNum, int maxNumOfEnemies, int currNumOfEnemies, bool saveDuringGame, bool shopAvailable, int currHealth, int maxHealth, int exp, int money, char stat, int shopXcoordinate, int shopYcoordinate, int saveXcoordinate, int saveYcoordinate, int playerXcoordinate, int playerYcoordinate, int ladderCoordinates[2], string equippedDefenceItem, string equippedAttackItem, list<Item> &playerItems);

};

#endif // LOADSAVEGAME_H
