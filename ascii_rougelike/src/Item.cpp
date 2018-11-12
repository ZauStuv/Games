#include "Item.h"

Item::Item()
{}

Item::Item(string name, string desc, int pieceOf, int attack, int defence, int heal, int shopPrice, int sellPrice)
{
    _name = name;
    _description = desc;
    _pieceOf = pieceOf;
    _attack = attack;
    _defence = defence;
    _heal = heal;
    _shopPrice = shopPrice;
    _sellPrice = sellPrice;
}


//Getters:
string Item::getName()
{
    return _name;
}
string Item::getDescription()
{
    return _description;
}
int Item::getPieceOf()
{
    return _pieceOf;
}
int Item::getAttack()
{
    return _attack;
}
int Item::getDefence()
{
    return _defence;
}
int Item::getHeal()
{
    return _heal;
}
int Item::getShopPrice()
{
    return _shopPrice;
}
int Item::getSellPrice()
{
    return _sellPrice;
}

//Setters:
void Item::setName(string name)
{
    _name = name;
}
void Item::setDescription(string desc)
{
    _description = desc;
}
void Item::setPieceOf(int pieceOf)
{
    _pieceOf = pieceOf;
}
void Item::setAttack(int attack)
{
    _attack = attack;
}
void Item::setDefence(int defence)
{
    _defence = defence;
}
void Item::setHeal(int heal)
{
    _heal = heal;
}
void Item::setShopPrice(int shopPrice)
{
    _shopPrice = shopPrice;
}
void Item::setSellPrice(int sellPrice)
{
    _sellPrice = sellPrice;
}
//an unified function for initializing an item:
void Item::setEverything(string name, int attack, int defence, int heal, int shopPrice, int sellPrice)
{
    _name = name;
    _attack = attack;
    _defence = defence;
    _heal = heal;
    _shopPrice = shopPrice;
    _sellPrice = sellPrice;
}
