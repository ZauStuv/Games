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
        bool openMenu(Character &cPlayer, PaintScreen &cPaint);
        void collectData(Character &cPlayer);
        //return true if player has used an item, false if he went "back"
        bool openItems(PaintScreen &cPaint, Character &cPlayer);

        //getters:
        int getArrow();
        int getItemArrow();
        int getOptionsKey();
        int getHealth();
        int getMaxHealth();
        char getStat();
        int getExp();
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
        int _money;
        list<Item> _items;
        Item _equippedWearpon;
        Item _equippedShield;

        //The menu point the arrow is pointing to:
        int _arrow;
        int _itemArrow;

        //return true if player has used an item, false if he went "back"
        bool watchItemDetails(PaintScreen &cPaint, int itemArrow, list<Item> &myItems, Character &cPlayer);

};

#endif // MENU_H
