#include "Character.h"

Character::Character()
{
    //ctor
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

bool Character::gainExp(int exp)
{
    int lastLevel = getLevel();
    setExp(getExp()+exp);

    if(getExp() >= 100 && getExp() < 200 && (getExp() - exp) < 100)
    {
        setLevel(2);
        //if level up has happened:
        lastLevel = getLevel();
        return true;
    }
    else if(getExp() >= 200 && getExp() < 300 && (getExp() - exp) < 200)
    {
        //if multiple level-up happens:
        while(3 - (lastLevel+1))
        {
            setLevel(++lastLevel);
        }
        setLevel(3);
        lastLevel = getLevel();
        return true;
    }
    else if(getExp() >= 300 && getExp() < 400 && (getExp() - exp) < 300)
    {
        while(4 - (lastLevel+1))
        {
            setLevel(++lastLevel);
        }
        setLevel(4);
        lastLevel = getLevel();
        return true;
    }
    else if(getExp() >= 400 && getExp() < 500 && (getExp() - exp) < 400)
    {
        while(5 - (lastLevel+1))
        {
            setLevel(++lastLevel);
        }
        setLevel(5);
        lastLevel = getLevel();
        return true;
    }
    else if(getExp() >= 500 && getExp() < 600 && (getExp() - exp) < 500)
    {
        while(6 - (lastLevel+1))
        {
            setLevel(++lastLevel);
        }
        setLevel(6);
        lastLevel = getLevel();
        return true;
    }
    else if(getExp() >= 600 && getExp() < 700 && (getExp() - exp) < 600)
    {
        while(7 - (lastLevel+1))
        {
            setLevel(++lastLevel);
        }
        setLevel(7);
        lastLevel = getLevel();
        return true;
    }
    else if(getExp() >= 700 && getExp() < 800 && (getExp() - exp) < 700)
    {
        while(8 - (lastLevel+1))
        {
            setLevel(++lastLevel);
        }
        setLevel(8);
        lastLevel = getLevel();
        return true;
    }
    else if(getExp() >= 800 && getExp() < 900 && (getExp() - exp) < 800)
    {
        while(9 - (lastLevel+1))
        {
            setLevel(++lastLevel);
        }
        setLevel(9);
        lastLevel = getLevel();
        return true;
    }
    else if(getExp() >= 900 && (getExp() - exp) < 900)
    {
        while(10 - (lastLevel+1))
        {
            setLevel(++lastLevel);
        }
        setLevel(10);
        lastLevel = getLevel();
        return true;
    }
    else
        return false;
}

void Character::initExp(int exp)
{
    setExp(exp);

    if(exp >= 100 && exp < 200)
    {
        _level = 2;
    }
    else if(exp >= 200 && exp < 300)
    {
        _level = 3;
    }
    else if(exp >= 300 && exp < 400)
    {
        _level = 4;
    }

    else if(exp >= 400 && exp < 500)
    {
        _level = 5;
    }
    else if(exp >= 500 && exp < 600)
    {
        _level = 6;
    }
    else if(exp >= 600 && exp < 700)
    {
        _level = 7;
    }
    else if(exp >= 700 && exp < 800)
    {
        _level = 8;
    }
    else if(exp >= 800 && exp < 900)
    {
        _level = 9;
    }
    else if(exp >= 900)
    {
        _level = 10;
    }
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

//Set values in case of a new game:
void Character::setDefaults(int startMoney)
{
    setCurrHealth(getMaxhealth());
    setStat('n');
    setAttack(1);
    setDefence(1);
    setExp(0);
    setLevel(1);
    setMoney(startMoney);
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
int Character::getLevel()
{
    return _level;
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
void Character::setLevel(int level)
{
    _level = level;
    list<Item>::iterator lit;

    if(_level == 2)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedWearpon.getName())
                  (*lit).setAttack((*lit).getAttack()+1);
        }
        getEquippedWearpon().setAttack(getEquippedWearpon().getAttack()+1);
    }
    else if(_level == 3)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedShield.getName())
                  (*lit).setDefence((*lit).getDefence()+1);
        }
        getEquippedShield().setDefence(getEquippedShield().getDefence()+1);
    }
    else if(_level == 4)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedWearpon.getName())
                  (*lit).setAttack((*lit).getAttack()+1);
        }
        getEquippedWearpon().setAttack(getEquippedWearpon().getAttack()+1);
    }
    else if(_level == 5)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedShield.getName())
                  (*lit).setDefence((*lit).getDefence()+1);
        }
        getEquippedShield().setDefence(getEquippedShield().getDefence()+1);
    }
    else if(_level == 6)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedWearpon.getName())
                  (*lit).setAttack((*lit).getAttack()+1);
        }
        getEquippedWearpon().setAttack(getEquippedWearpon().getAttack()+1);
    }
    else if(_level == 7)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedShield.getName())
                  (*lit).setDefence((*lit).getDefence()+1);
        }
        getEquippedShield().setDefence(getEquippedShield().getDefence()+1);
    }
    else if(_level == 8)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedWearpon.getName())
                  (*lit).setAttack((*lit).getAttack()+1);
        }
        getEquippedWearpon().setAttack(getEquippedWearpon().getAttack()+1);
    }
    else if(_level == 9)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedShield.getName())
                  (*lit).setDefence((*lit).getDefence()+1);
        }
        getEquippedShield().setDefence(getEquippedShield().getDefence()+1);
    }
    else if(_level == 10)
    {
        for(lit = _playerItems.begin(); lit != _playerItems.end(); lit++)
        {
              if((*lit).getName() == _equippedWearpon.getName())
                  (*lit).setAttack((*lit).getAttack()+1);
        }
        getEquippedWearpon().setAttack(getEquippedWearpon().getAttack()+1);
    }
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
