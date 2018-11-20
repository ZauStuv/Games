#ifndef PAINTSCREEN_H
#define PAINTSCREEN_H

#define MAX_LEVEL_DIMENSION 200

#include <iostream>
#include <string>
#include <cstdio>
#include <list>


#include "Enemy.h"
#include "Character.h"



using namespace std;


class PaintScreen
{
    public:
        PaintScreen();

        /** @brief: Vipes the screen clear.
        *
        *   @param: none
        *   @return: void
        */
        void clearScreen();

        /** @brief: 21 1 row long notification messages inside the game for the user.
        *
        *   @param: none
        *   @return: void
        */
        void messageCannotAfford();
        void messageCannotSellEquippedItem();
        void messageCannotTossEquippedShield();
        void messageCannotTossEquippedWearpon();
        void messageCongrats();
        void messageEnemyAttackMissed();
        void messageEnterSavestateName();
        void messageGameOver();
        void messageHealthHealed();
        void messageItemBought();
        void messageItemSold();
        void messageLevelUp();
        void messageNoEffect();
        void messageParlzHealed();
        void messagePoisonHealed();
        void messageShieldAlreadyEquipped();
        void messageShieldEquipped();
        void messageWearponAlreadyEquipped();
        void messageWearponEquipped();
        void messageYouBecameParalized();
        void messageYouBecamePoisoned();
        void messageItemTossed();

        /** @brief: Displays the details of an item in the user menu.
        *
        *   Displays the item name, its description, the number available where it was currently observed, its attack,
        *   defence and heal properties, the price which the shop sells the player for, and the price payed by the shop
        *   to the player in exchange for the item.
        *   The <selectArrow> defines if the arrow will point at "Use", "Throw away" or "Back".
        *
        *   @param: name: name of the item, desc: description, pieceOf: how many are available, attack: item attack value, defence: item defence value,
        *           heal: item heal value, buyPrice: how many gold the player has to give for 1 piece of the item,
        *           sellPrice: how many gold the player gets from the shop for 1 piece of the item, selectArrow: defines which option the arrow should point at.
        *
        *   @return: void
        */
        void paintItemDetails(string name, string desc, int pieceOf, int attack, int defence, int heal, int buyPrice, int sellPrince, int selectArrow);

        /** @brief: Displays player or shop items.
        *
        *   Displays the list of items and the arrow on
        *   which it is currently pointing at, with the help of <itemArrow> and <itemArrowCompare>
        *
        *   @param: item: the name of the item, itemArrow: gives the current position of the arrow,
        *           itemArrowCompare: gives the number of items at the player pocket or in the shop.
        *   @return: void
        */
        void paintItems(string item, int itemArrow, int itemArrowCompare);

        /** @brief: Displays the level map with all the objects.
        *
        *   Allows to paint out the character-based game map and the pre-defined (number of) objects.
        *   It allows a square-based map size defined by the macro constant MAX_LEVEL_DIMENSION. At this area, the characters held by <levelMap[][]>
        *   will be put out onto the screen, one after another. If the character is an '\n', the fist parameter of the array will be incremented.
        *   In case the coordinates of a map object is the same as the coordinates of an empty space ('.'), stored in <levelMap[][]>, it will overwrite the space.
        *
        *   @param:levelMap[][]: This array stores the wall and empty space characters for the whole map, *pPlayer: has the player coordinates, *pShop: has the shop coordinates,
        *          *pSaveState: has the savestate coordinates, cEnemies: a list of (varying number of) enemies and their coordinates, ladderCoordinates: the x and y coordinates of the ladder.
        *   @return: void
        */
        void paintLevelMap(char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int *pPlayer, int *pShop, int *pSaveState, list<Enemy> &cEnemies, int ladderCoordinates[2]);

        /** @brief: Displays the savefile loader menu
        *
        *   Displays the names of the 3 savestates, along with the position of the arrow, which is determined by the value of <arrow>.
        *
        *   @param: name1: the name of the first savestate (not the file name), name2: name of 2nd savestate, name3: name of 3rd savestate, arrow: holds the value to position the selector arrow.
        *
        *   @return: void
        */
        void PaintLoadMenu(string name1, string name2, string name3, int arrow);

        /** @brief: Paints the title screen logo and the main menu to the screen
        *
        *   @param: arrow[2]: Determines which menu point the arrow should point at.
        *   @return: void
        */
        void paintMainMenu(bool (*arrow)[2]);

        /** @brief: Paints the last row of the item selector menu
        *
        *   because of the program structure, this function displays the last row of the item selector menu separately.
        *   it only prints out "Back", and optionally the selector arrow.
        *
        *   @param: itemArrow: gives the current position of the arrow, itemArrowCompare: stores the number of different items in the item menu.
        *
        *   @return: void
        */
        void paintMenuBack(int itemArrow, int itemArrowCompare);

        /** @brief:Displays the "Sell" and "Back" options
        *
        *   Compares <itemArrow> with <itemArrowCompare>, and displays the menu points with the position the arrow accordingly.
        *
        *   @param:itemArrow: gives the current position of the arrow, itemArrowCompare: stores the number of different items in the item menu.
        *
        *   @return: void
        */
        void paintMenuSell(int itemArrow, int itemArrowCompare);

        /** @brief:Displays the options menu in the main menu.
        *
        *   Displays all 5 options, and the values corresponding to them in the same row,
        *   each parameter in a new row, one after another, as well as the current position of the selector arrow.
        *
        *   @param:life: gives the maximum health set for the player, enemies: the starting number of enemies on each level, saveOk: stores wheter there will be a safehouse on the levels,
        *          shopOk: stores wheter there will be a safehouse on the levels, arrow: stores the position of the selector arrow.
        *
        *   @return: void
        */
        void paintOptionsMenu(int life, int enemies, int money, bool saveOk, bool shopOk, int arrow);

        /** @brief:Displays the player options menu during the game.
        *
        *   Displays all the parameters, one after another, each one in a different row, and prints out 3 choices at the bottom of the screen:
        *   "Items", "Back" and "Quit game".
        *
        *   @param:arrow: determines wheter the arrow character will point at "Items", "Back", or at "Quit game", health: stores the value for current health,
        *          maxHealth: stores the maximum health, determined by the main options, stat: stores the player status, exp: contains all the exp points the player
        *          has gained, level: the level of the player, attackItem: the set attack item, defenceItem: the set defence item.
        *
        *   @return: void
        */
        void paintPlayerMenu(int arrow, int health, int maxHealth, char stat, int money, int exp, int level, string attackItem, string defenceItem);

        /** @brief:Displays the player stats.
        *
        *   Displays first the health with "<3" characters, then the money the player currently has, in the same row.
        *
        *   @param: cPlayer: Contains the player object, with all its settings.
        *   @return: void
        */
        void paintPlayerStats(Character &cPlayer);

        /** @brief:Displays the save menu.
        *
        *   Displays the three savestates, each one in a new row + the option to go back in the bottom row.
        *
        *   @param: name1: the name of the 1st savestate, name2: the name of the 2nd savestate, name3: the name of the 3rd savestate,
        *           arrow: stores the current position of the savefile selector arrow.
        *   @return: void
        */
        void PaintSaveMenu(string name1, string name2, string name3, int arrow);

        /** @brief:Displays the details of shop items.
        *
        *   Displays the name, the description, the number of pieces available, the attack, the defence, the heal stats,
        *   the price the player can buy 1 piece for, the price the player can get by selling 1 piece, and the options
        *   to buy or to return to the item selector menu at the bottom.
        *
        *   @param: name: name of the item, desc: the long description of the item, pieceOf: the available number to be bought,
        *           attack: the attack value of the item, attack: the defence value of the item, heal: the healing value of the item,
        *           buyPrice: the price the player has to pay for 1 piece of the item, sellPrice: the selling price of 1 item.
        *           arrow: stores the position of the item selector arrow.
        *   @return: void
        */
        void paintShopItemDetails(string name, string desc, int pieceOf, int attack, int defence, int heal, int buyPrice, int sellPrince, int selectArrow);

        /** @brief:Displays a short welcome message when entering the shop.
        *
        *   @param: void
        *   @return: void
        */
        void paintWelcomeAtShop();

        //paint levels:

    private:

        //paint the actually marked menu point in the main menu:
        void paintMainMenu_newGame();
        void paintMainMenu_options();
        void paintMainMenu_loadGame();
        void paintMainMenu_quit();

        bool hasListCoordinates(list<Enemy> &cEnemies, int x, int y);
};

#endif // PAINTSCREEN_H
