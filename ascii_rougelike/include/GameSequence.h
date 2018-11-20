#ifndef GAMESEQUENCE_H
#define GAMESEQUENCE_H

#include <fstream>
#include <cstdlib>
#include <conio.h>
#include "Level.h"
#include "GlobalOptions.h"
#include "LoadSaveGame.h"
#include "PaintScreen.h"



class GameSequence
{
    public:

        /** @brief: Initializes the start of the game
        *
        *   Sets up the default options of the game.
        *
        *   @param: none
        *   @return: void
        */
        GameSequence();


        /** @brief: Loads the main menu of the game.
        *
        *   Prints out the title and the first visible menu points called "Options",
        *   "Load Game", "New Game" and "Quit".
        *   @param: none
        *   @return: void
        */
        void loadMainMenu();

        //getters:

        //setters:

    private:

        //Holds the level and player settings:
        Level _cLoadLevel;

        //Holds the initial settings for the game, which can be changed in the options menu:
        GlobalOptions _cOptions;

        //Holds the PaintScreen object, which will be used through the game:
        PaintScreen _cPaint;

        //Holds the intformation about the selected menu point of the main menu.
        char _mainMenuKey;

        //Holds the current position of the main menu selector arrow
        bool _mainMenuArrow[2][2];


        /** @brief: Executes the currently selected menu point.
        *
        *   Checks the value of all <_mainMenuArrow[][]> array elements one after another,
        *   and executes the one which has "true" value stored in itself.
        *
        *   @param: none
        *   @return: void
        */
        bool enterPressed();

        /** @brief: Updates the menu point selector arrow.
        *
        *   Checks the previously pressed key information in
        *   <_mainMenuKey>, and updates the position of the selector
        *   arrow accordingly.
        *
        *   @param: none
        *   @return: void
        */
        void updateArrow();
};

#endif // GAMESEQUENCE_H
