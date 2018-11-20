#ifndef MENU_H
#define MENU_H

#include "Character.h"
#include "Item.h"
#include "PaintScreen.h"
#include <conio.h>

class Menu
{
    public:
        Menu();

        /** @brief: opens the player menu.
        *
        *   First, the function collects all the current player stats and items to the local private variables via
        *   <collectData()>, then in an endless loop, it displays all the player parameters and the current position
        *   of the arrow, and polls for a keystroke constantly to evaluate what to do.
        *
        *   @param: cPlayer: the player object, cPaint: necessary to display the menu to the screen.
        *   @return: true if player wants to quit the game, false if not.
        */
        bool openMenu(Character &cPlayer, PaintScreen &cPaint);



        //getters:
        int getArrow();
        int getItemArrow();
        int getOptionsKey();
        int getHealth();
        int getMaxHealth();
        char getStat();
        int getExp();
        int getLevel();
        int getMoney();
        void getItems(list<Item> &cItem);

        //setters:
        void setArrow(int arrow);
        void setItemArrow(int itemArrow);
        void setOptionsKey(char key);

    private:

        int _health;
        int _maxHealth;
        char _stat;
        int _optionsKey;
        int _exp;
        int _level;
        int _money;
        list<Item> _items;
        Item _equippedWearpon;
        Item _equippedShield;

        //The menu point the arrow is pointing to:
        int _arrow;
        int _itemArrow;

        /** @brief: collect all the current player parameters.
        *
        *   collect all the current parameters from the player, necessary for the player menu,
        *   stores them in local variables.
        *
        *   @param: cPlayer: the player object.
        *   @return: void
        */
        void collectData(Character &cPlayer);

        /** @brief: Lists out the player items
        *
        *   Collects all the player items from the local private item list <_items>,
        *   then it writes them out to the screen, one after another + the "back" option,
        *   and the current arrow position. after pressing enter, the current position of
        *   the arrow, stored in <_itemArrow> determines which item the player shall observe.
        *
        *   @param: cPaint: helps to paint out the submenu, cPlayer: the player object.
        *   @return: true if the selected item has been used, false if the player goes back via the "back" option.
        */
        bool openItems(PaintScreen &cPaint, Character &cPlayer);

        //return true if player has used an item, false if he went "back"
        /** @brief: Opens the details of an item.
        *
        *   This submenu displays all the details of a selected item, as well as the options to use it
        *   or dispose it, or to go back to the <openItems()> submenu.
        *   With the help of the variable <itemArrow>, the function can decide from the available item list, which one
        *   has been selected previously in the caller function, and displays the details of that item thereafter.
        *
        *   @param: cPaint: helps to paint out the submenu, itemArrow: the sequence number of the item from the item
        *   list to be displayed. myItems: the item list of the player, cPlayer: the player object.
        *   @return: true if the player object is successfully user or equipped, false if the player chose to go back.
        */
        bool watchItemDetails(PaintScreen &cPaint, int itemArrow, list<Item> &myItems, Character &cPlayer);

};

#endif // MENU_H
