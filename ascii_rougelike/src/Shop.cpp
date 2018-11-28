#include "Shop.h"

Shop::Shop()
{
    setItem(Item("Wooden sword", "A toy sword for kids or training, to avoid serious injuries", 1, 1, 0, 0, 10, 2));
    setItem(Item("Wooden shield", "A lightweigt shied that slightly defends you", 1, 0, 1, 0, 10, 2));
    setItem(Item("Bronze sword", "A more durable sword, made by the best craftsmen in the country", 1, 2, 0, 0, 50, 10));
    setItem(Item("Bronze shield", "A decent shield, which will outlast your grandchildren, a great value for price!", 1, 0, 2, 0, 50, 10));
    setItem(Item("Iron sword", "The strongest and prettiest sword available. No more attacking troubles!", 1, 3, 0, 0, 150, 30));
    setItem(Item("Iron shield", "This shield would eat Fort Knox for breakfast with its stats. Also, pretty decoration if no more needed", 1, 0, 3, 0, 150, 30));
    setItem(Item("Apple", "Restores HP slightly, also keeps doctor away!", 3, 0, 0, 1, 15, 1));
    setItem(Item("Lemon", "If life gives you lemons, make yourself a lemonade!", 3, 0, 0, 1, 15, 1));
    setItem(Item("Antidote", "Heals poisoned status", 3, 0, 0, 0, 20, 10));
    setItem(Item("Paralz heal", "Heals paralyzed status", 3, 0, 0, 0, 30, 15));
    setItem(Item("Big mushroom", "Yummy, and restores a plenty of HP", 2, 0, 0, 2, 30, 10));
    setItem(Item("Mamoothburger", "You don't want to eat for days after this. Also, refills a plenty of your HP", 2, 0, 0, 5, 50, 15));

}

void Shop::addItem(Item itemName)
{
    list<Item>::iterator lit;

    for(lit = _shopItems.begin(); lit != _shopItems.end(); lit++)
    {
        if( (*lit).getName() == itemName.getName())
        {
            (*lit).setPieceOf((*lit).getPieceOf()+1);
            return;
        }
    }
    _shopItems.push_back(itemName);
    //if there were more of the item available, buy only one:
    _shopItems.back().setPieceOf(1);
}

void Shop::enterShop(Character &cPlayer, PaintScreen &cPaint)
{
    list<Item>::iterator lit;
    int itemArrowCompare = 0;

    while(true)
    {
        //Clear screen, and display the shop menu with the available Items:
        cPaint.clearScreen();
        cPaint.paintWelcomeAtShop();

        for(lit = _shopItems.begin(); lit != _shopItems.end(); lit++)
        {
            cPaint.paintItems((*lit).getName(), getItemArrow(), itemArrowCompare);
            itemArrowCompare++;
        }
        cPaint.paintMenuSell(getItemArrow(), itemArrowCompare);

        cPaint.paintPlayerStats(cPlayer);

        setOptionsKey(getch());

        if(getOptionsKey() == 'w' || getOptionsKey() == 'W')
        {
            if(getItemArrow() > 0)
                setItemArrow(getItemArrow()-1);
        }
        else if(getOptionsKey() == 's' || getOptionsKey() == 'S')
        {
            if(getItemArrow() <= itemArrowCompare)
                setItemArrow(getItemArrow()+1);
        }
        else if(getOptionsKey() == '\r')
        {
            //open "selltoshop" menu:
            if(getItemArrow() == itemArrowCompare)
            {
                //returns true if player has bought something:
                if(sellToShop(cPlayer, cPaint))
                {
                    return;
                }
            }
            //return with "back"
            else if(getItemArrow() == itemArrowCompare+1)
                return;
            //write out the number in pocket, the description and the ablilities of the item:
            else
                watchItemDetails(cPaint, getItemArrow(), _shopItems, cPlayer);
        }


        itemArrowCompare = 0;
    }
}

void Shop::removeItem(Item itemName, int &itemArrow)
{
    list<Item>::iterator lit;

    for(lit = _shopItems.begin(); lit != _shopItems.end(); lit++)
    {
        if( (*lit).getName() == itemName.getName())
        {
            (*lit).setPieceOf((*lit).getPieceOf()-1);
            break;
        }
    }
    if((*lit).getPieceOf() == 0)
    {
        if(lit != _shopItems.begin())
            itemArrow--;
        _shopItems.erase(lit);

        return;
    }
    return;
}


bool Shop::sellToShop(Character &cPlayer, PaintScreen &cPaint)
{
    int itemArrowCompare = 0;
    list<Item> myItems;
    list<Item>::iterator lit;

    //list out all the player items, +back at the bottom, and a cursor to choose one:
    while(true)
    {
        //clear screen:
        cPaint.clearScreen();

        //Display the item list:
        cPlayer.getPlayerItems(myItems);
        for(lit = myItems.begin(); lit!= myItems.end(); lit++)
        {
            cPaint.paintItems((*lit).getName(), getSellItemArrow(), itemArrowCompare);
            itemArrowCompare++;
        }
        cPaint.paintMenuBack(getSellItemArrow(), itemArrowCompare);


        setOptionsKey(getch());

        if(getOptionsKey() == 'w' || getOptionsKey() == 'W')
        {
            if(getSellItemArrow() > 0)
            {
                setSellItemArrow(getSellItemArrow()-1);
            }
        }
        else if(getOptionsKey() == 's' || getOptionsKey() == 'S')
        {
            if(getSellItemArrow() < itemArrowCompare)
            {
                setSellItemArrow(getSellItemArrow()+1);
            }
        }
        else if(getOptionsKey() == '\r')
        {
            //return with "back"
            if(getSellItemArrow() == itemArrowCompare)
                return false;
            //sell item to shop:
            else
            {
                itemArrowCompare = 0;
                for(lit = myItems.begin(); lit!= myItems.end(); lit++)
                {
                    if(itemArrowCompare == getSellItemArrow())
                        break;
                    itemArrowCompare++;
                }
                //cannot sell equpped item:
                if(cPlayer.getEquippedShield().getName() == (*lit).getName() || cPlayer.getEquippedWearpon().getName() == (*lit).getName())
                {
                    cPaint.messageCannotSellEquippedItem();
                    system("pause");
                    return false;
                }
                //give the money to the player for the item:
                cPlayer.setMoney(cPlayer.getMoney() + (*lit).getSellPrice());
                addItem(*lit);
                cPlayer.removeItem(*lit);
                cPaint.messageItemSold();
                system("pause");
                return true;
            }


        }

        itemArrowCompare = 0;
        myItems.clear();
    }
}

void Shop::watchItemDetails(PaintScreen &cPaint, int itemArrow, list<Item> &myItems, Character &cPlayer)
{
    list<Item>::iterator lit;
    int selectArrow = 0;

    while(true)
    {
        int itemArrowCompare = 0;

        cPaint.clearScreen();

        for(lit = myItems.begin(); lit!= myItems.end(); lit++)
        {
            itemArrowCompare++;
            if(itemArrowCompare-1 == itemArrow)
                break;
        }
        cPaint.paintShopItemDetails((*lit).getName(), (*lit).getDescription(), (*lit).getPieceOf(), (*lit).getAttack(), (*lit).getDefence(), (*lit).getHeal(), (*lit).getShopPrice(), (*lit).getSellPrice(), selectArrow);
        cPaint.paintPlayerStats(cPlayer);

        setOptionsKey(getch());

        if(getOptionsKey() == 'w' || getOptionsKey() == 'W')
        {
            if(selectArrow > 0)
                selectArrow--;
        }
        else if(getOptionsKey() == 's' || getOptionsKey() == 'S')
        {
            if(selectArrow < 1)
                selectArrow++;
        }
        else if(getOptionsKey() == '\r')
        {
            switch(selectArrow)
            {
                case 0:
                //Buy Item from shop, if you have enough money:
                if(cPlayer.getMoney() >= (*lit).getShopPrice())
                {
                    cPlayer.setMoney(cPlayer.getMoney()-(*lit).getShopPrice());
                    cPlayer.addItem(*lit);
                    removeItem(*lit, itemArrow);
                    cPaint.messageItemBought();
                    system("pause");
                }
                else
                {
                    cPaint.messageCannotAfford();
                    system("pause");
                }
                break;

                case 1:
                //return
                return;
            }
        }

    }
}




//Getters:
Item Shop::getItem()
{
    return _shopItems.back();
}

int* Shop::getCoordinates()
{
    return _coordinates;
}
int Shop::getItemArrow()
{
    return _itemArrow;
}
int Shop::getSellItemArrow()
{
    return _sellItemArrow;
}
char Shop::getOptionsKey()
{
    return _optionsKey;
}

//Setters:
void Shop::setItem(Item shopItem)
{
    _shopItems.push_back(shopItem);
}

void Shop::setCoordinates(int y, int x)
{
    _coordinates[0] = y;
    _coordinates[1] = x;
}
void Shop::setItemArrow(int itemArrow)
{
    _itemArrow = itemArrow;
}
void Shop::setSellItemArrow(int sellItemArrow)
{
    _sellItemArrow = sellItemArrow;
}
void Shop::setOptionsKey(char key)
{
    _optionsKey = key;
}
