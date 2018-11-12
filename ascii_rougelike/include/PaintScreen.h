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

        /** @brief: Paints the title screen logo and the main menu to the screen
        *
        *   @param: chooser; The character which decides which menu point will be selected
        *   @return: void
        */
        void paintMainMenu(bool (*arrow)[2]);

        /** @brief: Vipes the screen clear.
        *
        *   @param: none
        *   @return: void
        */
        void clearScreen();
        void messageCannotAfford();
        void messageCannotSellEquippedItem();
        void messageCannotTossEquippedWearpon();
        void messageCannotTossEquippedShield();
        void messageCongrats();
        void messageEnemyAttackMissed();
        void messageEnterSavestateName();
        void messageGameOver();
        void messageHealthHealed();
        void messageItemBought();
        void messageItemSold();
        void messageNoEffect();
        void messageParlzHealed();
        void messagePoisonHealed();
        void messageShieldEquipped();
        void messageShieldAlreadyEquipped();
        void messageWearponEquipped();
        void messageWearponAlreadyEquipped();
        void messageYouBecameParalized();
        void messageYouBecamePoisoned();
        void messageItemTossed();
        void paintItems(string item, int itemArrow, int itemArrowCompare);
        void paintMenuBack(int itemArrow, int itemArrowCompare);
        void paintMenuSell(int itemArrow, int itemArrowCompare);
        void paintItemDetails(string name, string desc, int pieceOf, int attack, int defence, int heal, int buyPrice, int sellPrince, int selectArrow);
        void paintShopItemDetails(string name, string desc, int pieceOf, int attack, int defence, int heal, int buyPrice, int sellPrince, int selectArrow);
        void paintLevelMap(char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int *pPlayer, int *pShop, int *pSaveState, list<Enemy> &cEnemies, int ladderCoordinates[2]);
        void paintOptionsMenu(int life, int enemies, int money, bool saveOk, bool shopOk, int arrow);
        void paintPlayerMenu(int arrow, int health, int maxHealth, char stat, int money, int exp, string attackItem, string defenceItem);
        void paintPlayerStats(Character &cPlayer);
        void PaintLoadMenu(string name1, string name2, string name3, int arrow);
        void PaintSaveMenu(string name1, string name2, string name3, int arrow);
        void paintSellToShop(Character &cPlayer);
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
