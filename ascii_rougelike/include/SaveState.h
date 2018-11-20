#ifndef SAVESTATE_H
#define SAVESTATE_H
#include <string>
#include <list>
#include "Item.h"

using namespace std;


class SaveState
{
    public:
        SaveState();

        /** @brief: stores every saved item in the local Item list <_items>.
        *
        *   Function checks if the name of the saved item matches to one of those in the pre-defined list, then it
        *   sets its quantitiy, its attack and its defence with the saved values (because these parameters can vary).
        *
        *   @param:
        *   @return: void
        */
        void updateItem();

        //getters:
        string getStateName();
        string getItemName();
        list<Item> getItems();
        Item getAttackItem();
        Item getDefenceItem();
        int getItemCount();
        int getItemAttack();
        int getItemDefence();
        int getMaxLife();
        int getCurrLife();
        int getExp();
        char getStat();
        int getLevelNumber();
        int getMoney();
        int getCurrNumOfEnemies();
        int getMaxNumOfEnemies();
        bool getShopAvailable();
        bool getSaveDuringGame();
        int getShopCoordinate1();
        int getShopCoordinate2();
        int getSavePointCoordinate1();
        int getSavePointCoordinate2();
        int getPlayerCoordinate1();
        int getPlayerCoordinate2();
        int getLadderCoordinate(int coordinate);

        //setters:
        void setStateName(string stateName);
        void setItemName(string itemName);
        void setAttackItem(string itemName);
        void setDefenceItem(string itemName);
        void setItemCount(int itemCount);
        void setItemAttack(int itemAttack);
        void setItemDefence(int itemDefence);
        void setMaxLife(int maxLife);
        void setCurrLife(int currLife);
        void setExp(int exp);
        void setStat(char stat);
        void setLevelNumber(int levelNumber);
        void setMoney(int money);
        void setCurrNumOfEnemies(int num_of_enemies);
        void setMaxNumOfEnemies(int num_of_enemies);
        void setShopAvailable(bool shop_available);
        void setSaveDuringGame(bool save_during_game);
        void setShopCoordinate1(int shopCoordinate);
        void setShopCoordinate2(int shopCoordinate);
        void setSavePointCoordinate1(int savePointCoordinate);
        void setSavePointCoordinate2(int savePointCoordinate);
        void setPlayerCoordinate1(int playerCoordinate);
        void setPlayerCoordinate2(int playerCoordinate);
        void setLadderCoordinate1(int coordinate);
        void setLadderCoordinate2(int coordinate);

    private:

        string _stateName;
        //Global option settings:
        int _maxLife;
        int _currLife;
        int _exp;
        char _stat;
        int _currNumOfEnemies;
        int _maxNumOfEnemies;
        bool _shopAvailable;
        bool _saveDuringGame;
        int _money;
        int _ladderCoordinates[2];
        //shop coordinates:
        int _shopCoordinates[2];
        //savepoint coordinates:
        int _savePointCoordinates[2];
        //player coordinates:
        int _playerCoordinates[2];


        string _itemName;
        int _itemCount;
        int _itemAttack;
        int _itemDefence;
        list<Item> _items;

        //Level settings:
        int _levelNumber;

        Item _defenceItem;
        Item _attackItem;

        //list containing all possible items and their stats:
        list<Item> _allItems;
};

#endif // SAVESTATE_H
