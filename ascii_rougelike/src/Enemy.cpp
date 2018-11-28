#include "Enemy.h"

//define an enemy:
Enemy::Enemy(int health, int attack)
{
    _health = health;
    _maxHealth = _health;
    _attack = attack;

}

void Enemy::chasePlayer(int playerYCoordinate, int playerXCoordinate, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION])
{
    int dy = abs(playerYCoordinate - *(getCoordinates()));
    int dx = abs(playerXCoordinate - *(getCoordinates()+1));
    //try to approach the player in the coordinate which is farther from the enemy
    if( dy > dx)
    {
        if(playerYCoordinate > *(getCoordinates()))
        {
            if(levelMap[*(getCoordinates())+1][*(getCoordinates()+1)] == '.')
            {
                //turn the last tile back to '.', and turn the new one to '_':
                levelMap[*(getCoordinates())+1][*(getCoordinates()+1)] = '_';
                levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                setCoordinates(*(getCoordinates())+1, *(getCoordinates()+1));
            }
            //if there is a tile, try to go along the other axis towards the player:
            else
            {
                if(playerXCoordinate > *(getCoordinates()+1) && levelMap[*(getCoordinates())][*(getCoordinates()+1)+1] == '.')
                {
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)+1] = '_';
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                    setCoordinates(*(getCoordinates()), *(getCoordinates()+1)+1);
                }
                else if(levelMap[*(getCoordinates())][*(getCoordinates()+1)-1] == '.')
                {
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)-1] = '_';
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                    setCoordinates(*(getCoordinates()), *(getCoordinates()+1)-1);
                }
            }

        }
        else
        {
            if(levelMap[*(getCoordinates())-1][*(getCoordinates()+1)] == '.')
            {
                //turn the last tile back to '.', and turn the new one to '_':
                levelMap[*(getCoordinates())-1][*(getCoordinates()+1)] = '_';
                levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                setCoordinates(*(getCoordinates())-1, *(getCoordinates()+1));
            }
            else
            {
                if(playerXCoordinate > *(getCoordinates()+1) && levelMap[*(getCoordinates())][*(getCoordinates()+1)+1] == '.')
                {
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)+1] = '_';
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                    setCoordinates(*(getCoordinates()), *(getCoordinates()+1)+1);
                }
                else if(levelMap[*(getCoordinates())][*(getCoordinates()+1)-1] == '.')
                {
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)-1] = '_';
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                    setCoordinates(*(getCoordinates()), *(getCoordinates()+1)-1);
                }
            }
        }
    }
    else
    {
        if(playerXCoordinate > *(getCoordinates()+1))
        {
            if(levelMap[*(getCoordinates())][*(getCoordinates()+1)+1] == '.')
            {
                //turn the last tile back to '.', and turn the new one to '_':
                levelMap[*(getCoordinates())][*(getCoordinates()+1)+1] = '_';
                levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                setCoordinates(*(getCoordinates()), *(getCoordinates()+1)+1);
            }
            else
            {
                if(playerYCoordinate > *(getCoordinates()) && levelMap[*(getCoordinates())+1][*(getCoordinates()+1)] == '.')
                {
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(getCoordinates())+1][*(getCoordinates()+1)] = '_';
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                    setCoordinates(*(getCoordinates())+1, *(getCoordinates()+1));
                }
                else if(levelMap[*(getCoordinates())-1][*(getCoordinates()+1)] == '.')
                {
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(getCoordinates())-1][*(getCoordinates()+1)] = '_';
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                    setCoordinates(*(getCoordinates())-1, *(getCoordinates()+1));
                }
            }
        }
        else
        {
            if(levelMap[*(getCoordinates())][*(getCoordinates()+1)-1] == '.')
            {
                //turn the last tile back to '.', and turn the new one to '_':
                levelMap[*(getCoordinates())][*(getCoordinates()+1)-1] = '_';
                levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                setCoordinates(*(getCoordinates()), *(getCoordinates()+1)-1);
            }
            else
            {
                if(playerYCoordinate > *(getCoordinates()) && levelMap[*(getCoordinates())+1][*(getCoordinates()+1)] == '.')
                {
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(getCoordinates())+1][*(getCoordinates()+1)] = '_';
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                    setCoordinates(*(getCoordinates())+1, *(getCoordinates()+1));
                }
                else if(levelMap[*(getCoordinates())-1][*(getCoordinates()+1)] == '.')
                {
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(getCoordinates())-1][*(getCoordinates()+1)] = '_';
                    levelMap[*(getCoordinates())][*(getCoordinates()+1)] = '.';
                    setCoordinates(*(getCoordinates())-1, *(getCoordinates()+1));
                }
            }
        }
    }
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
int Enemy::getMaxHealth()
{
    return _maxHealth;
}
int Enemy::getAttack()
{
    return _attack;
}

//setters:
void Enemy::setCoordinates(int y, int x)
{
    _coordinates[0] = y;
    _coordinates[1] = x;
}

void Enemy::setHealth(int health)
{
    _health = health;
}
