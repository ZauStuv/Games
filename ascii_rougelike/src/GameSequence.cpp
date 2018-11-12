#include "GameSequence.h"

GameSequence::GameSequence()
{
    //key set for "New Game" as default.
    _mainMenuKey = 'n';
    _mainMenuArrow[0][0] = true;
    _mainMenuArrow[0][1] = false;
    _mainMenuArrow[1][0] = false;
    _mainMenuArrow[1][1] = false;

    _cOptions.setLife(3);
    _cOptions.setNumOfEnemies(5);
    _cOptions.setStartingBudget(25);
    _cOptions.setSaveDuringGame(true);
    _cOptions.setShopAvailable(true);


}


bool GameSequence::enterPressed()
{
    LoadSaveGame cGameLoaderSaver;


     if(_mainMenuArrow[0][0] == true)
    {
        //Open new game:
        _cLoadLevel.newGame(cGameLoaderSaver, _cOptions);
    }

    if(_mainMenuArrow[0][1] == true)
    {
        //load saved game:
        _cLoadLevel.loadGame(cGameLoaderSaver, _cOptions);
    }
    if(_mainMenuArrow[1][0] == true)
    {
        //load the options menu:
        _cOptions.optionsMenu(_cPaint, _cOptions);
    }
    if(_mainMenuArrow[1][1] == true)
    {
        return true;
    }
    return false;
}



void GameSequence::loadMainMenu()
{
    bool exitGame = false;

    while(exitGame == false)
    {
        while(true)
        {
            //loads the title screen and the menu points:
            _cPaint.paintMainMenu(_mainMenuArrow);
            _mainMenuKey = getch();

            if(_mainMenuKey == '\r')
                break;

            updateArrow();

        }

        //check which menu point was selected when "Enter" was pressed:
        exitGame = enterPressed();
    }
}



void GameSequence::updateArrow()
{
    if(_mainMenuArrow[0][0] == true)
    {
        if(_mainMenuKey == 's' || _mainMenuKey == 'S')
        {
            _mainMenuArrow[0][0] = false;
            _mainMenuArrow[0][1] = true;
        }
        if(_mainMenuKey == 'd' || _mainMenuKey == 'D')
        {
            _mainMenuArrow[0][0] = false;
            _mainMenuArrow[1][0] = true;
        }
    }

    if(_mainMenuArrow[0][1] == true)
    {
        if(_mainMenuKey == 'w' || _mainMenuKey == 'W')
        {
            _mainMenuArrow[0][1] = false;
            _mainMenuArrow[0][0] = true;
        }
        if(_mainMenuKey == 'd' || _mainMenuKey == 'D')
        {
            _mainMenuArrow[0][1] = false;
            _mainMenuArrow[1][1] = true;
        }
    }
    if(_mainMenuArrow[1][0] == true)
    {
        if(_mainMenuKey == 'a' || _mainMenuKey == 'A')
        {
            _mainMenuArrow[1][0] = false;
            _mainMenuArrow[0][0] = true;
        }
        if(_mainMenuKey == 's' || _mainMenuKey == 'S')
        {
            _mainMenuArrow[1][0] = false;
            _mainMenuArrow[1][1] = true;
        }
    }
    if(_mainMenuArrow[1][1] == true)
    {
        if(_mainMenuKey == 'a' || _mainMenuKey == 'A')
        {
            _mainMenuArrow[1][1] = false;
            _mainMenuArrow[0][1] = true;
        }
        if(_mainMenuKey == 'w' || _mainMenuKey == 'W')
        {
            _mainMenuArrow[1][1] = false;
            _mainMenuArrow[1][0] = true;
        }
    }
}
