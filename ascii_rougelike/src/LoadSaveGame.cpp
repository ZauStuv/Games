#include "LoadSaveGame.h"

LoadSaveGame::LoadSaveGame()
{
    setSaveMenuArrow(0);
    setLoadMenuArrow(0);

    int rowNum = 0;
    string input;

    //create 3 save files, and load them with the contence of "savefile1", "savefile2" and "savefile3":
    _loadSaveFile.open("savefile1.txt");
    if(_loadSaveFile.fail())
        _saveStates[0].setStateName("Empty");
    else
    {
        //if(sscanf(str.c_str(), "%d", &i) != 1)

        //the first row should be the file name, the next ones are the parameters
        while(getline(_loadSaveFile, input))
        {
            switch(rowNum)
            {
                case 0:
                    //get the savestate name from the save file, and write it to the local SaveState object:
                    _saveStates[0].setStateName(input);
                    break;
                case 1:
                    _saveStates[0].setLevelNumber(atoi(input.c_str()));
                    break;
                case 2:
                    _saveStates[0].setMaxLife(atoi(input.c_str()));
                    break;
                case 3:
                    _saveStates[0].setCurrLife(atoi(input.c_str()));
                    break;
                case 4:
                    _saveStates[0].setExp(atoi(input.c_str()));
                    break;
                case 5:
                    _saveStates[0].setStat(atoi(input.c_str()));
                    break;
                case 6:
                    _saveStates[0].setNumOfEnemies(atoi(input.c_str()));
                    break;
                case 7:
                    _saveStates[0].setSaveDuringGame(atoi(input.c_str()));
                    break;
                case 8:
                    _saveStates[0].setShopAvailable(atoi(input.c_str()));
                    break;
                case 9:
                    _saveStates[0].setMoney(atoi(input.c_str()));
                    break;
                case 10:
                    _saveStates[0].setShopCoordinate1(atoi(input.c_str()));
                    break;
                case 11:
                    _saveStates[0].setShopCoordinate2(atoi(input.c_str()));
                    break;
                case 12:
                    _saveStates[0].setSavePointCoordinate1(atoi(input.c_str()));
                    break;
                case 13:
                    _saveStates[0].setSavePointCoordinate2(atoi(input.c_str()));
                    break;
                case 14:
                    _saveStates[0].setPlayerCoordinate1(atoi(input.c_str()));
                    break;
                case 15:
                    _saveStates[0].setPlayerCoordinate2(atoi(input.c_str()));
                    break;
                case 16:
                    _saveStates[0].setLadderCoordinate1(atoi(input.c_str()));
                    break;
                case 17:
                    _saveStates[0].setLadderCoordinate2(atoi(input.c_str()));
                    break;
                //everything above 17 is player item. Player items have a finite number, with the same attributes, only their name and number should be saves/loaded:
                default:
                    if((rowNum % 3))
                    {
                        //there should be an empty row between each item+itemnumber
                        if(!((rowNum-1) % 3))
                            _saveStates[0].setItemName(input);
                        else if(!((rowNum+1) % 3))
                            _saveStates[0].setItemCount(atoi(input.c_str()));
                    }
                    else
                        _saveStates[0].updateItem();
                    break;
            }
            rowNum++;
        }
    }
    _loadSaveFile.close();
    rowNum = 0;


    _loadSaveFile.open("savefile2.txt");
    if(_loadSaveFile.fail())
        _saveStates[1].setStateName("Empty");
    else
    {
        //if(sscanf(str.c_str(), "%d", &i) != 1)

        //the first row should be the file name, the next ones are the parameters
        while(getline(_loadSaveFile, input))
        {
            switch(rowNum)
            {
                case 0:
                    //get the savestate name from the save file, and write it to the local SaveState object:
                    _saveStates[1].setStateName(input);
                    break;
                case 1:
                    _saveStates[1].setLevelNumber(atoi(input.c_str()));
                    break;
                case 2:
                    _saveStates[1].setMaxLife(atoi(input.c_str()));
                    break;
                case 3:
                    _saveStates[1].setCurrLife(atoi(input.c_str()));
                    break;
                case 4:
                    _saveStates[1].setExp(atoi(input.c_str()));
                    break;
                case 5:
                    _saveStates[1].setStat(atoi(input.c_str()));
                    break;
                case 6:
                    _saveStates[1].setNumOfEnemies(atoi(input.c_str()));
                    break;
                case 7:
                    _saveStates[1].setSaveDuringGame(atoi(input.c_str()));
                    break;
                case 8:
                    _saveStates[1].setShopAvailable(atoi(input.c_str()));
                    break;
                case 9:
                    _saveStates[1].setMoney(atoi(input.c_str()));
                    break;
                case 10:
                    _saveStates[1].setShopCoordinate1(atoi(input.c_str()));
                    break;
                case 11:
                    _saveStates[1].setShopCoordinate2(atoi(input.c_str()));
                    break;
                case 12:
                    _saveStates[1].setSavePointCoordinate1(atoi(input.c_str()));
                    break;
                case 13:
                    _saveStates[1].setSavePointCoordinate2(atoi(input.c_str()));
                    break;
                case 14:
                    _saveStates[1].setPlayerCoordinate1(atoi(input.c_str()));
                    break;
                case 15:
                    _saveStates[1].setPlayerCoordinate2(atoi(input.c_str()));
                    break;
                case 16:
                    _saveStates[1].setLadderCoordinate1(atoi(input.c_str()));
                    break;
                case 17:
                    _saveStates[1].setLadderCoordinate2(atoi(input.c_str()));
                    break;
                //everything above 17 is player item. Player items have a finite number, with the same attributes, only their name and number should be saves/loaded:
                default:
                    if((rowNum % 3))
                    {
                        //there should be an empty row between each item+itemnumber
                        if(!((rowNum-1) % 3))
                            _saveStates[1].setItemName(input);
                        else if(!((rowNum+1) % 3))
                            _saveStates[1].setItemCount(atoi(input.c_str()));
                    }
                    else
                        _saveStates[1].updateItem();
                    break;
            }
            rowNum++;
        }
    }
    _loadSaveFile.close();
    rowNum = 0;

    _loadSaveFile.open("savefile3.txt");
    if(_loadSaveFile.fail())
        _saveStates[2].setStateName("Empty");
    else
    {
        //if(sscanf(str.c_str(), "%d", &i) != 1)

        //the first row should be the file name, the next ones are the parameters
        while(getline(_loadSaveFile, input))
        {
            switch(rowNum)
            {
                case 0:
                    //get the savestate name from the save file, and write it to the local SaveState object:
                    _saveStates[2].setStateName(input);
                    break;
                case 1:
                    _saveStates[2].setLevelNumber(atoi(input.c_str()));
                    break;
                case 2:
                    _saveStates[2].setMaxLife(atoi(input.c_str()));
                    break;
                case 3:
                    _saveStates[2].setCurrLife(atoi(input.c_str()));
                    break;
                case 4:
                    _saveStates[2].setExp(atoi(input.c_str()));
                    break;
                case 5:
                    _saveStates[2].setStat(atoi(input.c_str()));
                    break;
                case 6:
                    _saveStates[2].setNumOfEnemies(atoi(input.c_str()));
                    break;
                case 7:
                    _saveStates[2].setSaveDuringGame(atoi(input.c_str()));
                    break;
                case 8:
                    _saveStates[2].setShopAvailable(atoi(input.c_str()));
                    break;
                case 9:
                    _saveStates[2].setMoney(atoi(input.c_str()));
                    break;
                case 10:
                    _saveStates[2].setShopCoordinate1(atoi(input.c_str()));
                    break;
                case 11:
                    _saveStates[2].setShopCoordinate2(atoi(input.c_str()));
                    break;
                case 12:
                    _saveStates[2].setSavePointCoordinate1(atoi(input.c_str()));
                    break;
                case 13:
                    _saveStates[2].setSavePointCoordinate2(atoi(input.c_str()));
                    break;
                case 14:
                    _saveStates[2].setPlayerCoordinate1(atoi(input.c_str()));
                    break;
                case 15:
                    _saveStates[2].setPlayerCoordinate2(atoi(input.c_str()));
                    break;
                case 16:
                    _saveStates[2].setLadderCoordinate1(atoi(input.c_str()));
                    break;
                case 17:
                    _saveStates[2].setLadderCoordinate2(atoi(input.c_str()));
                    break;
                //everything above 17 is player item. Player items have a finite number, with the same attributes, only their name and number should be saves/loaded:
                default:
                    if((rowNum % 3))
                    {
                        //there should be an empty row between each item+itemnumber
                        if(!((rowNum-1) % 3))
                            _saveStates[0].setItemName(input);
                        else if(!((rowNum+1) % 3))
                            _saveStates[2].setItemCount(atoi(input.c_str()));
                    }
                    else
                        _saveStates[2].updateItem();
                    break;
            }
            rowNum++;
        }
    }
    _loadSaveFile.close();
}

void LoadSaveGame::openLoadMenu(PaintScreen &cPaint, SaveState &state)
{
    while(true)
    {
        cPaint.clearScreen();
        //
        cPaint.PaintLoadMenu(getSaveState(0).getStateName(), getSaveState(1).getStateName(), getSaveState(2).getStateName(), getLoadMenuArrow());

        setLoadMenuKey(getch());

        if(getLoadMenuKey() == 'w' || getLoadMenuKey() == 'W')
        {
            if(getLoadMenuArrow() > 0)
            {
                setLoadMenuArrow(getLoadMenuArrow()-1);
            }
        }
        else if(getLoadMenuKey() == 's' || getLoadMenuKey() == 'S')
        {
            if(getLoadMenuArrow() < 3)
            {
                setLoadMenuArrow(getLoadMenuArrow()+1);
            }
        }
        else if(getLoadMenuKey() == '\r')
        {
            if(getLoadMenuArrow() == 3)
                return;
            else
            {
                if(getLoadMenuArrow() == 0)
                {
                    //retrieve the saved game datas from the 1st savefile:
                    state = _saveStates[0];
                }
                else if(getLoadMenuArrow() == 1)
                {
                    //retrieve the saved game datas from the 2nd savefile:
                    state = _saveStates[1];

                }
                else if(getLoadMenuArrow() == 2)
                {
                    //retrieve the saved game datas from the 2nd savefile:
                    state = _saveStates[2];
                }
                return;
            }
        }
    }
}



void LoadSaveGame::openSaveMenu(PaintScreen &cPaint, int levelNum, int numOfEnemies, bool saveDuringGame, bool shopAvailable, int currHealth, int maxHealth, int exp, int money, char stat, int shopXcoordinate, int shopYcoordinate, int saveXcoordinate, int saveYcoordinate, int playerXcoordinate, int playerYcoordinate, int ladderCoordinates[2], list<Item> &playerItems)
{
    while(true)
    {


        cPaint.clearScreen();
        //read the 3 save files:
        cPaint.PaintSaveMenu(getSaveState(0).getStateName(), getSaveState(1).getStateName(), getSaveState(2).getStateName(), getSaveMenuArrow());

        setSaveMenuKey(getch());

        if(getSaveMenuKey() == 'w' || getSaveMenuKey() == 'W')
        {
            if(getSaveMenuArrow() > 0)
            {
                setSaveMenuArrow(getSaveMenuArrow()-1);
            }
        }
        else if(getSaveMenuKey() == 's' || getSaveMenuKey() == 'S')
        {
            if(getSaveMenuArrow() < 3)
            {
                setSaveMenuArrow(getSaveMenuArrow()+1);
            }
        }
        else if(getSaveMenuKey() == '\r')
        {
            if(getSaveMenuArrow() == 3)
                return;
            else
            {
                if(getSaveMenuArrow() == 0)
                {
                    //save the game datas:
                    saveGameState(getSaveMenuArrow(), cPaint, levelNum, numOfEnemies, saveDuringGame, shopAvailable, currHealth, maxHealth, exp, money, stat, shopXcoordinate, shopYcoordinate, saveXcoordinate, saveYcoordinate, playerXcoordinate, playerYcoordinate, ladderCoordinates, playerItems);
                }
                else if(getSaveMenuArrow() == 1)
                {
                    //save the game datas:
                    saveGameState(getSaveMenuArrow(), cPaint, levelNum, numOfEnemies, saveDuringGame, shopAvailable, currHealth, maxHealth, exp, money, stat, shopXcoordinate, shopYcoordinate, saveXcoordinate, saveYcoordinate, playerXcoordinate, playerYcoordinate, ladderCoordinates, playerItems);
                }
                else if(getSaveMenuArrow() == 2)
                {
                    //save the game datas:
                    saveGameState(getSaveMenuArrow(), cPaint, levelNum, numOfEnemies, saveDuringGame, shopAvailable, currHealth, maxHealth, exp, money, stat, shopXcoordinate, shopYcoordinate, saveXcoordinate, saveYcoordinate, playerXcoordinate, playerYcoordinate, ladderCoordinates, playerItems);
                }
                return;
            }
        }


    }


}


void LoadSaveGame::saveGame()
{
    _saveGame.open("savegame.txt");
}

void LoadSaveGame::saveGameState(int stateNum, PaintScreen &cPaint, int levelNum, int numOfEnemies, bool saveDuringGame, bool shopAvailable, int currHealth, int maxHealth, int exp, int money, char stat, int shopXcoordinate, int shopYcoordinate, int saveXcoordinate, int saveYcoordinate, int playerXcoordinate, int playerYcoordinate, int ladderCoordinates[2], list<Item> &playerItems)
{
    list<Item>::iterator lit;
    //concatenate "stateNum" to string, to create the savefile name:
    string fileName = "savefile" + to_string(stateNum+1) + ".txt";
    string stateName;
    string intToStringHolder;

    _saveGame.open(fileName);

    //set the savestate name:
    cPaint.clearScreen();
    cPaint.messageEnterSavestateName();
    cin >> stateName;

    _saveStates[stateNum].setStateName(stateName);

    //append _saveGame with details to savefile:
    //+add newline between inoputs:
    _saveGame << stateName;
    _saveGame << endl;
    _saveGame << to_string(levelNum);
    _saveGame << endl;
    _saveGame << to_string(maxHealth);
    _saveGame << endl;
    _saveGame << to_string(currHealth);
    _saveGame << endl;
    _saveGame << to_string(exp);
    _saveGame << endl;
    _saveGame << to_string(stat);
    _saveGame << endl;
    _saveGame << to_string(numOfEnemies);
    _saveGame << endl;
    _saveGame << to_string(saveDuringGame);
    _saveGame << endl;
    _saveGame << to_string(shopAvailable);
    _saveGame << endl;
    _saveGame << to_string(money);
    _saveGame << endl;
    _saveGame << to_string(shopXcoordinate);
    _saveGame << endl;
    _saveGame << to_string(shopYcoordinate);
    _saveGame << endl;
    _saveGame << to_string(saveXcoordinate);
    _saveGame << endl;
    _saveGame << to_string(saveYcoordinate);
    _saveGame << endl;
    _saveGame << to_string(playerXcoordinate);
    _saveGame << endl;
    _saveGame << to_string(playerYcoordinate);
    _saveGame << endl;
    _saveGame << to_string(ladderCoordinates[0]);
    _saveGame << endl;
    _saveGame << to_string(ladderCoordinates[1]);
    _saveGame << endl;
    _saveGame << endl;


    //add the player items at the end:
    for(lit = playerItems.begin(); lit != playerItems.end(); lit++)
    {
        _saveGame << (*lit).getName();
        _saveGame << endl;
        _saveGame << (*lit).getPieceOf();
        _saveGame << endl;
        _saveGame << endl;
    }




    _saveGame.close();
}



//getters:

int* LoadSaveGame::getCoordinates()
{
    return _coordinates;
}
SaveState LoadSaveGame::getSaveState(int ssNumber)
{
    return _saveStates[ssNumber];
}


//menu getters:

int LoadSaveGame::getSaveMenuKey()
{
    return _saveMenuKey;
}

int LoadSaveGame::getSaveMenuArrow()
{
    return _saveMenuArrow;
}
int LoadSaveGame::getLoadMenuKey()
{
    return _loadMenuKey;
}
int LoadSaveGame::getLoadMenuArrow()
{
    return _loadMenuArrow;
}


//setters:
void LoadSaveGame::setCoordinates(int x, int y)
{
    _coordinates[0] = x;
    _coordinates[1] = y;
}

//menu setters:

void LoadSaveGame::setSaveMenuKey(int saveMenuKey)
{
    _saveMenuKey = saveMenuKey;
}
void LoadSaveGame::setSaveMenuArrow(int saveMenuArrow)
{
    _saveMenuArrow = saveMenuArrow;
}
void LoadSaveGame::setLoadMenuArrow(int loadMenuArrow)
{
    _loadMenuArrow = loadMenuArrow;
}
void LoadSaveGame::setLoadMenuKey(int loadMenuKey)
{
    _loadMenuKey = loadMenuKey;
}
