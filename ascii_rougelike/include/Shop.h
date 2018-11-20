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

        /** @brief: Initializes the shop with the available items.
        *
        *   @param: void
        *   @return: void
        */
        Shop();

        /** @brief: opens the Shop menu.
        *
        *   After pressing the button which moves the character to the field on the map where the Shop seides (marked with the character 'M')
        *   the shop menu appears, with all the available items inside it + the "sell" oportunity for the player to sell its items to the shop.
        *
        *   @param: cPlayer: the player object. Necessary to get or upload the player items in this menu.
        *           cPaint: Paint object, to display the menu.
        *   @return: void
        */
        void enterShop(Character &cPlayer, PaintScreen &cPaint);

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

        /** @brief: adds an item - sold by the player - to the shop items.
        *
        *   Adds an item to the end of the shop's existing item list <_shopItems>, or if the item already exist,
        *   increments the amount of that item by 1.
        *
        *   @param: itemName: the name of the item to be added to the shop.
        *   @return: void
        */
        void addItem(Item itemName);

        /** @brief: Removes 1 piece of an item from the shop inventory
        *
        *   Works basically the same as the <addItem()> function. If the shop has more instances of
        *   that item, the function removes only one of it. If the item was the last one of the inventory,
        *   the item itself will be removed completely from the shop's item list <_playerItems>.
        *
        *   @param: itemName: the name of the item to be removed from the shop items.
        *           itemArrow: the parameter to do the trick to display the previous item
        *           next, to not run out of the list if the last element would be sold.
        *   @return: void
        */
        void removeItem(Item itemName, int &itemArrow);

        /** @brief: menu to sell player items to the shop
        *
        *   This submenu gets all the available player items displayed to the screen,
        *   and allows to sell any of them to the shop (one piece every time) if they are
        *   currently not equipped by the player. This is done in an endless loop, to toogle
        *   the keyboard inputs and refresh the display accordingly.
        *
        *   @param: cPlayer: player object that contains all the necessary items,
        *           cPaint: painter object, to display this submenu.
        *
        *   @return: true if player has sold an item, false if not, or if player want to sell an equipped item.
        */
        bool sellToShop(Character &cPlayer, PaintScreen &cPaint);

        /** @brief: display the details of an item
        *
        *   This menu point is the logic behind finding the appropriate item from the item list of the shop.
        *   by comparing <itemArrowCompare> to <itemArrow>.
        *
        *
        *   @param: cPaint: Paint object, to display item details and the player stats.
        *           itemArrow: the variable from the caller function which contains the sequence number
        *           of the last item, myItems: the list to contain all the items of the shop, cPlayer:
        *           player object.
        *
        *   @return: void
        */
        void watchItemDetails(PaintScreen &cPaint, int itemArrow, list<Item> &myItems, Character &cPlayer);

};

#endif // SHOP_H
