#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:

        Enemy(int health, int attack);

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
        int getAttack();

        //setters:
        void setCoordinates(int x, int y);
        void setHealth(int health);


    private:

        //Enemy health:
        int _health;
        //enemy attack:
        int _attack;
        //coordinates on the map:
        int _coordinates[2];

};

#endif // ENEMY_H
