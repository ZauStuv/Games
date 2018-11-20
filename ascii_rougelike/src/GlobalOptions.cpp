#include "GlobalOptions.h"

GlobalOptions::GlobalOptions()
{
    setOptionsArrow(0);
}
void GlobalOptions::optionsMenu(PaintScreen cPaint, GlobalOptions &cOptions)
{
    bool exitOptions = false;
    //Stay here, until the player presses "Enter" for menu point "Back":
    while(exitOptions == false)
    {
        cPaint.clearScreen();
        cPaint.paintOptionsMenu(cOptions.getLife(), cOptions.getNumOfEnemies(), cOptions.getStartingBudget(), cOptions.getSaveDuringGame(), cOptions.getShopAvailable(), cOptions.getOptionsArrow());
        //You can move the cursor here:
        exitOptions = selectOption(cOptions);

    }

}

bool GlobalOptions::selectOption(GlobalOptions &cOptions)
{
    cOptions.setOptionsKey(getch());

    if(cOptions.getOptionsKey() == 'w' || cOptions.getOptionsKey() == 'W')
    {
        if(cOptions.getOptionsArrow() > 0)
            cOptions.setOptionsArrow(cOptions.getOptionsArrow()-1);
    }
    if(cOptions.getOptionsKey() == 's' || cOptions.getOptionsKey() == 'S')
    {
        if(cOptions.getOptionsArrow() < 5)
            cOptions.setOptionsArrow(cOptions.getOptionsArrow()+1);
    }

    if(cOptions.getOptionsKey() == 'a' || cOptions.getOptionsKey() == 'A')
    {
        switch(cOptions.getOptionsArrow())
        {
            case 0:
            if(cOptions.getLife() > 1)
                cOptions.setLife(cOptions.getLife()-1);
            break;

            case 1:
            if(cOptions.getNumOfEnemies() > 1)
                cOptions.setNumOfEnemies(cOptions.getNumOfEnemies()-1);
            break;

            case 2:
            if(cOptions.getStartingBudget() > 5)
                cOptions.setStartingBudget(cOptions.getStartingBudget()-1);
            break;

            case 3:
            cOptions.setSaveDuringGame(!cOptions.getSaveDuringGame());
            break;

            case 4:
            cOptions.setShopAvailable(!cOptions.getShopAvailable());
            break;
        }
    }
    if(cOptions.getOptionsKey() == 'd' || cOptions.getOptionsKey() == 'D')
    {
        switch(cOptions.getOptionsArrow())
        {
            case 0:
            if(cOptions.getLife() < 9)
                cOptions.setLife(cOptions.getLife()+1);
            break;

            case 1:
            if(cOptions.getNumOfEnemies() < 9)
                cOptions.setNumOfEnemies(cOptions.getNumOfEnemies()+1);
            break;

            case 2:
            if(cOptions.getStartingBudget() < 1000)
            cOptions.setStartingBudget(cOptions.getStartingBudget()+1);
            break;

            case 3:
            cOptions.setSaveDuringGame(!cOptions.getSaveDuringGame());
            break;

            case 4:
            cOptions.setShopAvailable(!cOptions.getShopAvailable());
            break;
        }
    }

    //exit the options menu:
    if(cOptions.getOptionsArrow() == 5 && cOptions.getOptionsKey() == '\r')
        return true;

    return false;
}

//setters:
void GlobalOptions::setLife(int life)
{
    _life = life;
}
void GlobalOptions::setNumOfEnemies(int num_of_enemies)
{
    _num_of_enemies = num_of_enemies;
}
void GlobalOptions::setSaveDuringGame(bool save_during_game)
{
    _save_during_game = save_during_game;
}
void GlobalOptions::setShopAvailable(bool shop_available)
{
    _shop_available = shop_available;
}
void GlobalOptions::setStartingBudget(int starting_budget)
{
    _starting_budget = starting_budget;
}

//getters
int GlobalOptions::getLife()
{
    return _life;
}
int GlobalOptions::getNumOfEnemies()
{
    return _num_of_enemies;
}
bool GlobalOptions::getSaveDuringGame()
{
    return _save_during_game;
}
bool GlobalOptions::getShopAvailable()
{
    return _shop_available;
}
int GlobalOptions::getStartingBudget()
{
    return _starting_budget;
}



//private getters and setters:
void GlobalOptions::setOptionsArrow(int optionsArrow)
{
    _optionsArrow = optionsArrow;
}
void GlobalOptions::setOptionsKey(char optionsKey)
{
    _optionsKey = optionsKey;
}
int GlobalOptions::getOptionsArrow()
{
    return _optionsArrow;
}
char GlobalOptions::getOptionsKey()
{
    return _optionsKey;
}
