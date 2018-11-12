#include "SaveState.h"

SaveState::SaveState()
{
    //list all possible items, and add them to "allItems" variable:
    _allItems.push_back(Item("Hammer", "Just an ordinary Rusty hammer from the backshelf",1,1,0,0,20,5));
    _allItems.push_back(Item("Wooden sword", "A toy sword for kids or training, to avoid serious injuries", 1, 1, 0, 0, 10, 2));
    _allItems.push_back(Item("Wooden shield", "A lightweigt shied that slightly defends you", 1, 0, 1, 0, 10, 2));
    _allItems.push_back(Item("Bronze sword", "A more durable sword, made by the best craftsmen in the country", 1, 2, 0, 0, 50, 10));
    _allItems.push_back(Item("Bronze shield", "A decent shield, which will outlast your grandchildren, a great value for price!", 1, 0, 2, 0, 50, 10));
    _allItems.push_back(Item("Iron sword", "The strongest and prettiest sword available. No more attacking troubles!", 1, 3, 0, 0, 150, 30));
    _allItems.push_back(Item("Iron shield", "This shield would eat Fort Knox for breakfast with its stats. Also, pretty decoration if no more needed", 1, 0, 3, 0, 150, 30));
    _allItems.push_back(Item("Apple", "Restores HP slightly", 3, 0, 0, 1, 15, 1));
    _allItems.push_back(Item("Lemon", "If life gives you lemons, make yourself a lemonade!", 3, 0, 0, 1, 15, 1));
    _allItems.push_back(Item("Antidote", "Heals poisoned status", 3, 0, 0, 0, 20, 10));
    _allItems.push_back(Item("Paralz heal", "Heals paralyzed status", 3, 0, 0, 0, 30, 15));
    _allItems.push_back(Item("Big mushroom", "Yummy, and restores a plenty of HP", 2, 0, 0, 2, 30, 10));
    _allItems.push_back(Item("Mamoothburger", "You don't want to eat for days after this. Also, refills a plenty of your HP", 2, 0, 0, 5, 50, 15));
}

void SaveState::updateItem()
{
    list<Item>::iterator lit;

    for(lit = _allItems.begin(); lit != _allItems.end(); lit++)
    {
        if((*lit).getName() == getItemName())
        {
            _items.push_back(*lit);
            _items.back().setPieceOf(getItemCount());
            break;
        }
    }

}


//getters
string SaveState::getStateName()
{
    return _stateName;
}
string SaveState::getItemName()
{
    return _itemName;
}
int SaveState::getItemCount()
{
    return _itemCount;
}
list<Item> SaveState::getItems()
{
    return _items;
}

int SaveState::getLevelNumber()
{
    return _levelNumber;
}
int SaveState::getMaxLife()
{
    return _maxLife;
}
int SaveState::getCurrLife()
{
    return _currLife;
}
int SaveState::getExp()
{
    return _exp;
}
int SaveState::getLadderCoordinate(int coordinate)
{
    return _ladderCoordinates[coordinate];
}
int SaveState::getMoney()
{
    return _money;
}
char SaveState::getStat()
{
    return _stat;
}
int SaveState::getNumOfEnemies()
{
    return _num_of_enemies;
}
bool SaveState::getShopAvailable()
{
    return _shop_available;
}
bool SaveState::getSaveDuringGame()
{
    return _save_during_game;
}
int SaveState::getShopCoordinate1()
{
    return _shopCoordinates[0];
}
int SaveState::getShopCoordinate2()
{
    return _shopCoordinates[1];
}
int SaveState::getSavePointCoordinate1()
{
    return _savePointCoordinates[0];
}
int SaveState::getSavePointCoordinate2()
{
    return _savePointCoordinates[1];
}
int SaveState::getPlayerCoordinate1()
{
    return _playerCoordinates[0];
}
int SaveState::getPlayerCoordinate2()
{
    return _playerCoordinates[1];
}


//setters:

void SaveState::setStateName(string stateName)
{
    _stateName = stateName;
}
void SaveState::setItemName(string itemName)
{
    _itemName = itemName;
}
void SaveState::setItemCount(int itemCount)
{
    _itemCount = itemCount;
}
void SaveState::setLevelNumber(int levelNumber)
{
    _levelNumber = levelNumber;
}
void SaveState::setMaxLife(int maxLife)
{
    _maxLife = maxLife;
}
void SaveState::setCurrLife(int currLife)
{
    _currLife = currLife;
}
void SaveState::setExp(int exp)
{
    _exp = exp;
}
void SaveState::setLadderCoordinate1(int coordinate)
{
    _ladderCoordinates[0] = coordinate;
}
void SaveState::setLadderCoordinate2(int coordinate)
{
    _ladderCoordinates[1] = coordinate;
}
void SaveState::setMoney(int money)
{
    _money = money;
}
void SaveState::setStat(char stat)
{
    _stat = stat;
}
void SaveState::setNumOfEnemies(int num_of_enemies)
{
    _num_of_enemies = num_of_enemies;
}
void SaveState::setShopAvailable(bool shop_available)
{
    _shop_available = shop_available;
}
void SaveState::setSaveDuringGame(bool save_during_game)
{
    _save_during_game = save_during_game;
}
void SaveState::setShopCoordinate1(int shopCoordinate)
{
    _shopCoordinates[0] = shopCoordinate;
}
void SaveState::setShopCoordinate2(int shopCoordinate)
{
    _shopCoordinates[1] = shopCoordinate;
}
void SaveState::setSavePointCoordinate1(int savePointCoordiante)
{
    _savePointCoordinates[0] = savePointCoordiante;
}
void SaveState::setSavePointCoordinate2(int savePointCoordiante)
{
    _savePointCoordinates[1] = savePointCoordiante;
}
void SaveState::setPlayerCoordinate1(int playerCoordinate)
{
    _playerCoordinates[0] = playerCoordinate;
}
void SaveState::setPlayerCoordinate2(int playerCoordinate)
{
    _playerCoordinates[1] = playerCoordinate;
}
