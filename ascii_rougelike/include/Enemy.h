#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy(int health, int attack, int defence);
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
        //enemy defence:
        int _defence;
        //coordinates on the map:
        int _coordinates[2];

};

#endif // ENEMY_H
