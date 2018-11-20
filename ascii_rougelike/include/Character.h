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

        /** @brief: Adds a new item to the player.
        *
        *   Adds an item to the end of the player's existing item list <_playerItems>, or if the item already exist,
        *   increments the amount of that item by 1.
        *
        *   @param: itemName: the name of the item to be added to the player.
        *   @return: void
        */
        void addItem(Item itemName);

        /** @brief: Attacks an enemy.
        *
        *   Attacks an enemy with the power of the equipped wearpon
        *
        *   @param: void
        *   @return: the value of the equipped wearpon's attack.
        */
        int attackEnemy();

        /** @brief: Calculates the consequences of a successful enemy attack.
        *
        *   When the player gets hit by an enemy, based on the player's shield, some of its
        *   health will be lost by the attack. This damage will be subtracted from the player's
        *   current health value <_currHealth>.
        *
        *   @param: damage: the amount of the injury the player will take after an enemy attack.
        *   @return: true if player dies from the attack, false if not.
        */
        bool dealDamage(int damage);

        /** @brief: Adds experience points to the player.
        *
        *   After defeating an enemy, the player gains some experience point, depending on the attack value
        *   of the enemy. This will be added to the player's total experience points <_exp>. If this value surpasses
        *   a certain number, the player will level up.
        *
        *   @param: exp: the experience point the player gains after defeating an enemy.
        *   @return: true if level up happens, false if not.
        */
        bool gainExp(int exp);

        /** @brief: Sets the starting experience of the player.
        *
        *   Is only used when player loads a game. According to the saved experience points,
        *   the funcion sets the level of the player as well.
        *
        *   @param: exp: the experience point the player had when the previus game was saved.
        *   @return: void
        */
        void initExp(int exp);

        /** @brief: Removes 1 piece of an item from the inventory
        *
        *   Works basically the same as the <addItem()> function. If the player has more instances of
        *   that item, the funcion removes only one of it. If the item was the last one of the inventory,
        *   the item itself will be removed completely from the player's item list <_playerItems>.
        *
        *   @param: itemName: the name of the item to be removed from the player items.
        *   @return: void
        */
        void removeItem(Item itemName);

        /** @brief: sets the default values for a character.
        *
        *   Sets the all the starting paramters for the player in the beginning of the game (when starting a new game).
        *   This funcion will only called once at the beginning of the game, when the player will be created, or when
        *   a saved game will be loaded, but then the necessary values will be overridden.
        *
        *   @param: startMoney: the amount of money that the player will get at the beginning of the game. Value set in
        *           the Options class.
        *   @return: void
        */
        void setDefaults(int startMoney);


        //Getters:
        int getMaxhealth();
        int getCurrHealth();
        int getAttack();
        int getDefence();
        int getExp();
        int getLevel();
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
        void setLevel(int level);
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
        //Player level:
        int _level;
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
