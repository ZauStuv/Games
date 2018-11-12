#ifndef SHOP_H
#define SHOP_H

#include <list>
#include <conio.h>
#include "Item.h"
#include "Character.h"
#include "PaintScreen.h"
#include "Menu.h"


class Shop
{
    public:
        Shop();
        void enterShop(Character &cPlayer, PaintScreen &cPaint);
        void addItem(Item itemName);
        void removeItem(Item itemName, int &itemArrow);

        //Getters:
        Item getItem();
        int* getCoordinates();
        char getOptionsKey();
        int getItemArrow();
        int getSellItemArrow();
        void getItems(list<Item> &cItem);

        //Setters:
        void setItem(Item shopItem);
        void setCoordinates(int x, int y);
        void setOptionsKey(char key);
        void setItemArrow(int itemArrow);
        void setSellItemArrow(int itemArrow);

    private:
        list<Item> _shopItems;
        list<Item> _items;
        char _optionsKey;
        int _itemArrow;
        int _sellItemArrow;
        //coordinates on the map:
        int _coordinates[2];
        //see the item details:
        void watchItemDetails(PaintScreen &cPaint, int itemArrow, list<Item> &myItems, Character &cPlayer);
        bool sellToShop(Character &cPlayer, PaintScreen &cPaint);

};

#endif // SHOP_H
