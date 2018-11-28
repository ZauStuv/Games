#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>
#define MAX_LEVEL_DIMENSION 200

class Enemy
{
    public:

        Enemy(int health, int attack);

        /** @brief: chases player after dealing some damage.
        *
        *   After the player has attacked an enemy, that enemy will always follow the player until it dies,
        *   or the enemy has been defeated.
        *
        *   @param: playerYCoordinate: the Y coordinate of the player, playerXCoordinate: the X coordinate of the player,
        *           levelMap[][]: the array of the level map, with all the stored fields within it.
        *   @return: void
        */
        void chasePlayer(int playerYCoordinate, int playerXCoordinate, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION]);

        /** @brief: does the given damage to an enemy.
        *
        *   Enemy will deal a damage set by <damage>, then it gets subtracted from the current health and
        *   evaluated if the enemy survived the attack.
        *
        *   @param: damage: the amount of damage the enemy shall deal.
        *   @return: true if enemy died by the attack, false if it didn't.
        */
        bool dealDamage(int damage);


        //getters:
        int* getCoordinates();
        int getHealth();
        int getMaxHealth();
        int getAttack();

        //setters:
        void setCoordinates(int x, int y);
        void setHealth(int health);


    private:

        //Enemy health:
        int _health;
        //Enemy starting health:
        int _maxHealth;
        //enemy attack:
        int _attack;
        //coordinates on the map:
        int _coordinates[2];

};

#endif // ENEMY_H
