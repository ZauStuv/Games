#include "Menu.h"

Menu::Menu()
{
    setArrow(0);
    setItemArrow(0);
}

void Menu::collectData(Character &cPlayer)
{
    //clear the list before updating it:
    _items.clear();
    _health = cPlayer.getCurrHealth();
    _maxHealth = cPlayer.getMaxhealth();
    _stat = cPlayer.getStat();
    _exp = cPlayer.getExp();
    _money = cPlayer.getMoney();
    _equippedWearpon = cPlayer.getEquippedWearpon();
    _equippedShield = cPlayer.getEquippedShield();
    cPlayer.getPlayerItems(_items);
}


//getters
int Menu::getArrow()
{
    return _arrow;
}
int Menu::getItemArrow()
{
    return _itemArrow;
}
int Menu::getOptionsKey()
{
    return _optionsKey;
}
int Menu::getHealth()
{
    return _health;
}
int Menu::getMaxHealth()
{
    return _maxHealth;
}
char Menu::getStat()
{
    return _stat;
}
int Menu::getExp()
{
    return _exp;
}
int Menu::getMoney()
{
    return _money;
}
void Menu::getItems(list<Item> &cItem)
{
    list<Item>::iterator lit;

    for(lit = _items.begin(); lit != _items.end(); lit++)
    {
        cItem.push_back(*lit);
    }
}

bool Menu::openItems(PaintScreen &cPaint, Character &cPlayer)
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
        getItems(myItems);
        for(lit = myItems.begin(); lit!= myItems.end(); lit++)
        {
            cPaint.paintItems((*lit).getName(), getItemArrow(), itemArrowCompare);
            itemArrowCompare++;
        }
        cPaint.paintMenuBack(getItemArrow(), itemArrowCompare);


        setOptionsKey(getch());

        if(getOptionsKey() == 'w' || getOptionsKey() == 'W')
        {
            if(getItemArrow() > 0)
            {
                setItemArrow(getItemArrow()-1);
            }
        }
        else if(getOptionsKey() == 's' || getOptionsKey() == 'S')
        {
            if(getItemArrow() < itemArrowCompare)
            {
                setItemArrow(getItemArrow()+1);
            }
        }
        else if(getOptionsKey() == '\r')
        {
            //return with "back"
            if(getItemArrow() == itemArrowCompare)
                return false;
            //write out the number in pocket, the description and the ablilities of the item:
            if(watchItemDetails(cPaint, getItemArrow(), myItems, cPlayer) == true)
                return true;

        }

        itemArrowCompare = 0;
        myItems.clear();
    }
}


bool Menu::openMenu(Character &cPlayer, PaintScreen &cPaint)
{


    //update the variables for the menu:
    collectData(cPlayer);

    while(1)
    {
        cPaint.paintPlayerMenu(getArrow(), getHealth(), getMaxHealth(), getStat(), getMoney(), getExp(), _equippedWearpon.getName(), _equippedShield.getName());

        //wait for the user input:
        setOptionsKey(getch());

        if(getOptionsKey() == 'w' || getOptionsKey() == 'W')
        {
            if(getArrow() > 0)
                setArrow(getArrow()-1);
        }
        if(getOptionsKey() == 's' || getOptionsKey() == 'S')
        {
            if(getArrow() < 2)
                setArrow(getArrow()+1);
        }

        //when enter is pressed:
        if(getOptionsKey() == '\r')
        {
            switch(getArrow())
            {
                case 0:
                    if(openItems(cPaint, cPlayer) == true)
                        return false;
                    break;
                case 1:
                    //back to game:
                    return false;
                case 2:
                    //quit game:
                    return true;

            }
        }

    }
}


void Menu::setArrow(int arrow)
{
    _arrow = arrow;
}

void Menu::setItemArrow(int itemArrow)
{
    _itemArrow = itemArrow;
}

void Menu::setOptionsKey(char key)
{
    _optionsKey = key;
}


bool Menu::watchItemDetails(PaintScreen &cPaint, int itemArrow, list<Item> &myItems, Character &cPlayer)
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
        cPaint.paintItemDetails((*lit).getName(), (*lit).getDescription(), (*lit).getPieceOf(), (*lit).getAttack(), (*lit).getDefence(), (*lit).getHeal(), (*lit).getShopPrice(), (*lit).getSellPrice(), selectArrow);

        setOptionsKey(getch());

        if(getOptionsKey() == 'w' || getOptionsKey() == 'W')
        {
            if(selectArrow > 0)
                selectArrow--;
        }
        else if(getOptionsKey() == 's' || getOptionsKey() == 'S')
        {
            if(selectArrow < 2)
                selectArrow++;
        }
        else if(getOptionsKey() == '\r')
        {
            switch(selectArrow)
            {
                case 0:
                //Check what status the item can add to your character:
                //a): check if the item is an attack or defence item, and if it's not equipped yet:
                if(cPlayer.getEquippedShield().getName() != (*lit).getName())
                {
                    //if it's not equipped, check if it's a defence item:
                    if((*lit).getDefence() > 0)
                    {
                        cPlayer.setEquippedShield(*lit);
                        cPaint.messageShieldEquipped();
                        system("pause");
                        return true;
                    }
                }
                else if((*lit).getDefence() > 0)
                {
                    cPaint.messageShieldAlreadyEquipped();
                    system("pause");
                    break;
                }
                if(cPlayer.getEquippedWearpon().getName() != (*lit).getName())
                {
                    //if it's not equipped, check if it's a defence item:
                    if((*lit).getAttack() > 0)
                    {
                        cPlayer.setEquippedWearpon(*lit);
                        cPaint.messageWearponEquipped();
                        system("pause");
                        return true;
                    }
                }
                else if((*lit).getAttack() > 0)
                {
                    cPaint.messageWearponAlreadyEquipped();
                    system("pause");
                    break;
                }
                //b): If the item can heal any status condition:
                if((*lit).getName() == "Paralz heal")
                {
                    if(cPlayer.getStat() == 'z')
                    {
                        cPlayer.setStat('n');
                        cPlayer.removeItem(*lit);
                        cPaint.messageParlzHealed();
                        system("pause");
                        return true;

                    }
                    else
                    {
                        cPaint.messageNoEffect();
                        system("pause");
                        break;
                    }

                }
                if((*lit).getName() == "Antidote")
                {
                    if(cPlayer.getStat() == 'p')
                    {
                        cPlayer.setStat('n');
                        cPlayer.removeItem(*lit);
                        cPaint.messagePoisonHealed();
                        system("pause");
                        return true;

                    }
                    else
                    {
                        cPaint.messageNoEffect();
                        system("pause");
                        break;
                    }
                }
                //if the item is a heal item:
                if((*lit).getHeal() > 0)
                {
                    //don't eat the food if it cannot restore any HP:
                    if(cPlayer.getCurrHealth() >= cPlayer.getMaxhealth())
                    {
                        cPaint.messageNoEffect();
                        system("pause");
                        break;
                    }
                    cPlayer.setCurrHealth(cPlayer.getCurrHealth()+(*lit).getHeal());
                    //healing should not restore more than the max health:
                    if(cPlayer.getCurrHealth() > cPlayer.getMaxhealth())
                        cPlayer.setCurrHealth(cPlayer.getMaxhealth());
                    cPlayer.removeItem(*lit);
                    cPaint.messageHealthHealed();
                    system("pause");
                    return true;
                }
                break;

                case 1:
                //you cannot throw away your only wearpon:
                if(cPlayer.getEquippedWearpon().getName() == (*lit).getName())
                {
                    cPaint.messageCannotTossEquippedWearpon();
                    system("pause");
                    break;
                }
                if(cPlayer.getEquippedShield().getName() == (*lit).getName())
                {
                    cPaint.messageCannotTossEquippedShield();
                    system("pause");
                    break;
                }
                cPlayer.removeItem(*lit);
                cPaint.messageItemTossed();
                system("pause");
                return true;

                case 2:
                return false;
            }
        }

    }
}
