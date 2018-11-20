#include "Enemy.h"

//define an enemy:
Enemy::Enemy(int health, int attack)
{
    _health = health;
    _attack = attack;
}

bool Enemy::dealDamage(int damage)
{
    setHealth(getHealth()-damage);
    if(getHealth() <= 0)
        //enemy died
        return true;
    else
        return false;
}
//getters:
int* Enemy::getCoordinates()
{
    return _coordinates;
}
int Enemy::getHealth()
{
    return _health;
}
int Enemy::getAttack()
{
    return _attack;
}

//setters:
void Enemy::setCoordinates(int x, int y)
{
    _coordinates[0] = x;
    _coordinates[1] = y;
}

void Enemy::setHealth(int health)
{
    _health = health;
}
