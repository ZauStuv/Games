#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <list>

#include "Item.h"

using namespace std;

class Character
{
    public:
        Character();

        void setDefaults(int start_money);
        void addItem(Item itemName);
        bool dealDamage(int damage);
        void removeItem(Item itemName);
        int attackEnemy();

        //Getters:
        int getMaxhealth();
        int getCurrHealth();
        int getAttack();
        int getDefence();
        int getExp();
        int getMoney();
        char getStat();
        int* getCoordinates();
        void getPlayerItems(list<Item> &playerItems);
        Item getEquippedWearpon();
        Item getEquippedShield();

        //Setters:
        void setMaxhealth(int maxHealth);
        void setCurrHealth(int currHealth);
        void setAttack(int attack);
        void setDefence(int defence);
        void setExp(int exp);
        void setMoney(int money);
        void setStat(char stat);
        void setCoordinates(int x, int y);
        void setPlayerItems(Item playerItems);
        void setAllPlayerItems(list<Item> items);
        void setEquippedWearpon(Item equippedWearpon);
        void setEquippedShield(Item equippedShield);


    private:

        //The maximum; and the current player health:
        int _maxHealth;
        int _currHealth;
        //Player attack:
        int _attack;
        //Player defence:
        int _defence;
        //Player XP:
        int _exp;
        //Player money:
        int _money;
        //character health status:
        char _stat;
        //coordinates on the map:
        int _coordinates[2];
        //Player items
        list<Item> _playerItems;
        list<Item>::iterator it;
        //equipped player items:
        Item _equippedWearpon;
        Item _equippedShield;

};

#endif // CHARACTER_H
