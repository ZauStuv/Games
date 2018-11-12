#include "Character.h"

Character::Character()
{
    //ctor
}

//Set values in case of a new game:
void Character::setDefaults(int start_money)
{
    setCurrHealth(getMaxhealth());
    setStat('n');
    setAttack(1);
    setDefence(1);
    setExp(0);
    setMoney(start_money);
    _playerItems.push_back(Item("Hammer", "Just an ordinary Rusty hammer from the backshelf",1,1,0,0,20,5));
    _playerItems.push_back(Item("Wooden shield", "A lightweigt shied that slightly defends you", 1, 0, 1, 0, 10, 2));

    //set the equipped wearpons:
    list<Item>::iterator lit;

    for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
    {
        if( (*lit).getAttack() != 0)
            setEquippedWearpon(*lit);
        if( (*lit).getDefence() != 0)
            setEquippedShield(*lit);
    }
}


void Character::addItem(Item itemName)
{
    list<Item>::iterator lit;

    for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
    {
        if( (*lit).getName() == itemName.getName())
        {
            (*lit).setPieceOf((*lit).getPieceOf()+1);
            return;
        }
    }
    _playerItems.push_back(itemName);
    //if there were more of the item available, buy only one:
    _playerItems.back().setPieceOf(1);
}
int Character::attackEnemy()
{
    return getEquippedWearpon().getAttack();
}

bool Character::dealDamage(int damage)
{
    setCurrHealth(getCurrHealth() - damage/getEquippedShield().getDefence());
    if(getCurrHealth() <= 0)
        //player died
        return true;
    else
        return false;
}


void Character::removeItem(Item itemName)
{
    list<Item>::iterator lit;

    for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
    {
        if( (*lit).getName() == itemName.getName())
        {
            (*lit).setPieceOf((*lit).getPieceOf()-1);
            break;
        }
    }
    if((*lit).getPieceOf() == 0)
            _playerItems.erase(lit);
}

//Getters:

int Character::getMaxhealth()
{
    return _maxHealth;
}
int Character::getCurrHealth()
{
    return _currHealth;
}
int Character::getAttack()
{
    return _attack;
}
int Character::getDefence()
{
    return _defence;
}
int Character::getExp()
{
    return _exp;
}
int Character::getMoney()
{
    return _money;
}
char Character::getStat()
{
    return _stat;
}
int* Character::getCoordinates()
{
    return _coordinates;
}
void Character::getPlayerItems(list<Item> &playerItems)
{
    list<Item>::iterator lit;

    for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
    {
        playerItems.push_back(*lit);
    }
}
Item Character::getEquippedWearpon()
{
    return _equippedWearpon;
}
Item Character::getEquippedShield()
{
    return _equippedShield;
}


void Character::setMaxhealth(int maxHealth)
{
    _maxHealth = maxHealth;
}
void Character::setCurrHealth(int currHealth)
{
    _currHealth = currHealth;
}
void Character::setAttack(int attack)
{
    _attack = attack;
}
void Character::setDefence(int defence)
{
    _defence = defence;
}
void Character::setExp(int exp)
{
    _exp = exp;
}
void Character::setMoney(int money)
{
    _money = money;
}
void Character::setStat(char stat)
{
    _stat = stat;
}
void Character::setCoordinates(int y, int x)
{
    _coordinates[0] = y;
    _coordinates[1] = x;
}
void Character::setPlayerItems(Item playerItems)
{
    _playerItems.push_back(playerItems);
}
void Character::setAllPlayerItems(list<Item> items)
{
    list<Item>::iterator lit;
    _playerItems.clear();

    for(lit = items.begin(); lit != items.end(); lit++)
    {
        _playerItems.push_back(*lit);
    }

}
void Character::setEquippedWearpon(Item equippedWearpon)
{
    _equippedWearpon = equippedWearpon;
}
void Character::setEquippedShield(Item equippedShield)
{
    _equippedShield = equippedShield;
}
