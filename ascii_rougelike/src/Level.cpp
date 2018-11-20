#include "Level.h"

Level::Level()
{

}
void Level::getRandomCoordinateForMap(int &myY, int &myX, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION])
{
    while(1)
    {
        //set the shop and other objects so that they can be reached from any direction:
        myX = rand() % MAX_LEVEL_DIMENSION;
        myY = rand() % MAX_LEVEL_DIMENSION;
        if(levelMap[myY][myX] == '.' && levelMap[myY+1][myX] == '.' && levelMap[myY-1][myX] == '.' && levelMap[myY][myX+1] == '.' && levelMap[myY][myX-1] == '.')
        {
            levelMap[myY][myX] = '_';
            break;
        }
    }
}
void Level::getRandomCoordinateForMapEnemiesAndPlayer(int &myY, int &myX, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION])
{
    while(1)
    {
        //set the shop and other objects so that they can be reached from any direction:
        myX = rand() % MAX_LEVEL_DIMENSION;
        myY = rand() % MAX_LEVEL_DIMENSION;
        if(levelMap[myY][myX] == '.')
        {
            levelMap[myY][myX] = '_';
            break;
        }
    }
}


void Level::newGame(LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions)
{
    int levelNum = 1;

    //create the player:
    Character cPlayer;
    cPlayer.setMaxhealth(cOptions.getLife());
    cPlayer.setDefaults(cOptions.getStartingBudget());

    //load level, and continue until you play the last level, or quit the game, or die -> return loadLevel false:
    while(true)
    {
        if(loadLevel(levelNum, cGameLoaderSaver, cOptions, cPlayer) == false)
            break;

        levelNum++;

        //after finishing level9, congrats to the player, then return:
        if(levelNum > 9)
        {
            _cPaint.clearScreen();
            _cPaint.messageCongrats();
            system("pause");
            return;
        }

    }


}
void Level::loadGame(LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions)
{
    SaveState cState;

    if(cGameLoaderSaver.openLoadMenu(_cPaint, cState) == false)
        return;

    //before loading the settings, check if the save is valid. If not, return:
    if(cState.getStateName() == "Empty")
        return;

    //bacause in load mode, overwrite the global options:
    cOptions.setLife(cState.getMaxLife());
    cOptions.setNumOfEnemies(cState.getMaxNumOfEnemies());
    cOptions.setSaveDuringGame(cState.getSaveDuringGame());
    cOptions.setShopAvailable(cState.getSaveDuringGame());
    cOptions.setStartingBudget(cState.getMoney());


    int levelNum = cState.getLevelNumber();

    Character cPlayer;
    cPlayer.setMaxhealth(cOptions.getLife());
    cPlayer.setDefaults(cState.getMoney());
    cPlayer.setCurrHealth(cState.getCurrLife());
    cPlayer.setStat(cState.getStat());
    cPlayer.setAllPlayerItems(cState.getItems());
    cPlayer.initExp(cState.getExp());

    cPlayer.setEquippedWearpon(cState.getAttackItem());
    cPlayer.setEquippedShield(cState.getDefenceItem());

    //load level, and continue until you play the last level, or quit the game, or die -> return loadLevel false:
    while(true)
    {
        if(loadLevel(levelNum, cGameLoaderSaver, cOptions, cPlayer, cState) == false)
            break;

        levelNum++;

        //after finishing level9, congrats to the player, then return:
        if(levelNum > 9)
        {
            _cPaint.clearScreen();
            _cPaint.messageCongrats();
            system("pause");
            return;
        }
    }

}


bool Level::loadLevel(int level, LoadSaveGame &cGameLoaderSaver, GlobalOptions &cOptions, Character &cPlayer)
{
    //game quit variable:
    char gameQuit = '\0';
    string levelName = "level" + to_string(level) + ".txt";
    ifstream _levelLoader;
    int ladderCoordinates[2];
    int poisonCounter = 0;

    //strores the map for the level in a 2d array:
    char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION] = {EOF};
    //load the level file from the working directory:
    _levelLoader.open(levelName);
    //stores 1 character from the level file:
    char c;
    //Loop variables:
    int x = 0, y = 0;


    if(_levelLoader.fail())
    {
        //cout << "Level file does not exist\n";
        return false;
    }

    //read in the level characters:
    while( _levelLoader.get(c))
    {
        levelMap[y][x] = c;
        x++;
        if(c == '\n')
        {
            x = 0;
            y++;
        }
    }



    //ceate player menu:
    Menu playerMenu;

    //create the enemies:
    list<Enemy> cEnemies;
    int numOfEnemies = 0;
    while(cOptions.getNumOfEnemies() > numOfEnemies)
    {
        cEnemies.push_back(Enemy((rand() % 9)+1, (rand() % 5)+1));
        numOfEnemies++;
    }

    //create the shop, if available:
    Shop cShop;


    //Randomize the location of items:
    randomizer(cOptions, cShop, cGameLoaderSaver, cPlayer, cEnemies, levelMap, ladderCoordinates);

    //This is where the actual running game will take place:
    while(1)
    {
        //wipe the page clean:
        _cPaint.clearScreen();

        //Paint out the map:
        _cPaint.paintLevelMap(levelMap, cPlayer.getCoordinates(), cShop.getCoordinates(), cGameLoaderSaver.getCoordinates(), cEnemies, ladderCoordinates);

        //Paint out the player health and money:
        _cPaint.paintPlayerStats(cPlayer);


        //wait for the user to give an input, then evaluate it:
        gameQuit = playerMove(cPlayer, playerMenu, cShop, cEnemies, cGameLoaderSaver, levelMap, level, cOptions, ladderCoordinates);

        if(gameQuit == 'q')
        {
            _levelLoader.close();
            return false;
        }
        else if(gameQuit == 'h')
        {
            _levelLoader.close();
            return true;
        }

        //move enemies: if enemy has killed the player(function returns true), return false and quit the game:
        if(enemyMove(cEnemies, cPlayer, levelMap))
            return false;


        if(cPlayer.getStat() == 'p')
        {
            if(!((poisonCounter++) % 5) && poisonCounter)
            {
                cPlayer.setCurrHealth(cPlayer.getCurrHealth()-1);
                if(!cPlayer.getCurrHealth())
                {
                    _cPaint.clearScreen();
                    _cPaint.messageGameOver();
                    system("pause");
                    return false;
                }
            }
        }
        else
            poisonCounter = 0;
    }




    //after finishing, close the level file:
    _levelLoader.close();

    return true;
    //
}

bool Level::loadLevel(int level, LoadSaveGame &cGameLoaderSaver, GlobalOptions cOptions, Character &cPlayer, SaveState cState)
{
    //game quit variable:
    char gameQuit = '\0';
    string levelName = "level" + to_string(level) + ".txt";
    ifstream _levelLoader;
    int ladderCoordinates[2];
    int poisonCounter = 0;

    //strores the map for the level in a 2d array:
    char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION] = {EOF};
    //load the level file from the working directory:
    _levelLoader.open(levelName);
    //stores 1 character from the level file:
    char c;
    //Loop variables:
    int x = 0, y = 0;


    if(_levelLoader.fail())
    {
        //cout << "Level file does not exist\n";
        return false;
    }

    //read in the level characters:
    while( _levelLoader.get(c))
    {
        levelMap[y][x] = c;
        x++;
        if(c == '\n')
        {
            x = 0;
            y++;
        }
    }



    //ceate player menu:
    Menu playerMenu;

    //create the enemies:
    list<Enemy> cEnemies;
    int numOfEnemies = 0;

    //load back on the currently saved level only as many enemies as many have remained before saving:
    if(cState.getLevelNumber() == level)
    {
        while(cState.getCurrNumOfEnemies() > numOfEnemies)
        {
            cEnemies.push_back(Enemy((rand() % 9)+1, (rand() % 5)+1));
            numOfEnemies++;
        }
    }
    else
    {
        while(cOptions.getNumOfEnemies() > numOfEnemies)
        {
            cEnemies.push_back(Enemy((rand() % 9)+1, (rand() % 5)+1));
            numOfEnemies++;
        }
    }

    //create the shop, if available:
    Shop cShop;


    //Randomize the location of items:
    randomizer(cOptions, cShop, cGameLoaderSaver, cPlayer, cEnemies, levelMap, ladderCoordinates);


    //overwrite the shop and savestate coordinates for the first loaded level:
    if(cState.getLevelNumber() == level)
    {
        levelMap[*(cShop.getCoordinates())][*(cShop.getCoordinates()+1)] = '.';
        cShop.setCoordinates(cState.getShopCoordinate1(), cState.getShopCoordinate2());
        levelMap[*(cShop.getCoordinates())][*(cShop.getCoordinates()+1)] = '_';
        levelMap[*(cGameLoaderSaver.getCoordinates())][*(cGameLoaderSaver.getCoordinates()+1)] = '.';
        cGameLoaderSaver.setCoordinates(cState.getSavePointCoordinate1(), cState.getSavePointCoordinate2());
        levelMap[*(cGameLoaderSaver.getCoordinates())][*(cGameLoaderSaver.getCoordinates()+1)] = '_';
        levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)] = '.';
        cPlayer.setCoordinates(cState.getPlayerCoordinate1(), cState.getPlayerCoordinate2());
        levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)] = '_';

        levelMap[ladderCoordinates[0]][ladderCoordinates[1]] = '.';
        ladderCoordinates[0] = cState.getLadderCoordinate(0);
        ladderCoordinates[1] = cState.getLadderCoordinate(1);
        levelMap[ladderCoordinates[0]][ladderCoordinates[1]] = '_';
    }

    //This is where the actual running game will take place:
    while(gameQuit != 'q')
    {
        //wipe the page clean:
        _cPaint.clearScreen();

        //Paint out the map:
        _cPaint.paintLevelMap(levelMap, cPlayer.getCoordinates(), cShop.getCoordinates(), cGameLoaderSaver.getCoordinates(), cEnemies, ladderCoordinates);

        //Paint out the player health and money:
        _cPaint.paintPlayerStats(cPlayer);


        //wait for the user to give an input, then evaluate it:
        gameQuit = playerMove(cPlayer, playerMenu, cShop, cEnemies, cGameLoaderSaver, levelMap, level, cOptions, ladderCoordinates);

        if(gameQuit == 'q')
        {
            _levelLoader.close();
            return false;
        }

        else if(gameQuit == 'h')
        {
            _levelLoader.close();
            return true;
        }


        //move enemies: if enemy has killed the player(function returns true), return false and quit the game:
        if(enemyMove(cEnemies, cPlayer, levelMap))
            return false;

        if(cPlayer.getStat() == 'p')
        {
            if(!((poisonCounter++) % 5 && poisonCounter))
            {
                cPlayer.setCurrHealth(cPlayer.getCurrHealth()-1);
                if(!cPlayer.getCurrHealth())
                {
                    _cPaint.clearScreen();
                    _cPaint.messageGameOver();
                    system("pause");
                    return false;
                }
            }
        }
        else
            poisonCounter = 0;
    }





    //after finishing, close the level file:
    _levelLoader.close();

    return true;
    //

}


bool Level::enemyMove(list<Enemy> &cEnemy, Character &cPlayer, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION])
{
    list<Enemy>::iterator lit;

    for(lit = cEnemy.begin(); lit != cEnemy.end(); lit++)
    {
        //inspect if the player is next to the enemy (up, down, left, right):
        if( (*((*lit).getCoordinates()) == *(cPlayer.getCoordinates())+1 && *((*lit).getCoordinates()+1) == *(cPlayer.getCoordinates()+1))  ||   (*((*lit).getCoordinates()) == *(cPlayer.getCoordinates())-1 && *((*lit).getCoordinates()+1) == *(cPlayer.getCoordinates()+1))  ||  (*((*lit).getCoordinates()) == *(cPlayer.getCoordinates()) && *((*lit).getCoordinates()+1) == *(cPlayer.getCoordinates()+1)+1)  ||  (*((*lit).getCoordinates()) == *(cPlayer.getCoordinates()) && *((*lit).getCoordinates()+1) == *(cPlayer.getCoordinates()+1)-1))
        {
            //set a 90% chance of hitting the player:
            if((rand() % 10) != 0)
            {
                //by a 20% chance, let the player get poisoned or paralized. you cannot get both at once:
                if(rand() % 8 == 0 && cPlayer.getStat() == 'n')
                {
                    _cPaint.messageYouBecamePoisoned();
                    system("pause");
                    cPlayer.setStat('p');
                }
                if(rand() % 9 == 0 && cPlayer.getStat() == 'n')
                {
                    _cPaint.messageYouBecameParalized();
                    system("pause");
                    cPlayer.setStat('z');
                }

                if(cPlayer.dealDamage((*lit).getAttack()) == true)
                {
                    _cPaint.clearScreen();
                    _cPaint.messageGameOver();
                    system("pause");
                    return true;
                }
            }
        }
        else
        {
            switch(rand() % 5)
            {
                //move up:
                case 0:
                    if(*((*lit).getCoordinates()) > 0 && levelMap[*((*lit).getCoordinates())-1][*((*lit).getCoordinates()+1)] == '.')
                    {
                        (*lit).setCoordinates(*((*lit).getCoordinates())-1, *((*lit).getCoordinates()+1));
                        //turn the last tile back to '.', and turn the new one to '_':
                        levelMap[*((*lit).getCoordinates())+1][*((*lit).getCoordinates()+1)] = '.';
                        levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)] = '_';
                        break;
                    }
                //move down:
                case 1:
                    if(*((*lit).getCoordinates()) < MAX_LEVEL_DIMENSION && levelMap[*((*lit).getCoordinates())+1][*((*lit).getCoordinates()+1)] == '.')
                    {
                        (*lit).setCoordinates(*((*lit).getCoordinates())+1, *((*lit).getCoordinates()+1));
                        levelMap[*((*lit).getCoordinates())-1][*((*lit).getCoordinates()+1)] = '.';
                        levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)] = '_';
                        break;
                    }
                //move left:
                case 2:
                    if(*((*lit).getCoordinates()+1) > 0 && levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)-1] == '.')
                    {
                        (*lit).setCoordinates(*((*lit).getCoordinates()), *((*lit).getCoordinates()+1)-1);
                        //turn the last tile back to '.', and turn the new one to '_':
                        levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)+1] = '.';
                        levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)] = '_';
                        break;
                    }
                //move right:
                case 3:
                    if(*((*lit).getCoordinates()+1) < MAX_LEVEL_DIMENSION && levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)+1] == '.')
                    {
                        (*lit).setCoordinates(*((*lit).getCoordinates()), *((*lit).getCoordinates()+1)+1);
                        //turn the last tile back to '.', and turn the new one to '_':
                        levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)-1] = '.';
                        levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)] = '_';
                        break;
                    }
                //don't move anywhere:
                default:
                    break;
            }
        }
    }
    return false;

}


char Level::playerMove(Character &cPlayer, Menu &playerMenu, Shop &cShop, list<Enemy> &cEnemies, LoadSaveGame &cSaveState, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int levelNum, GlobalOptions &cOptions, int ladderCoordinates[2])
{
    //character input:
    int c;

    //endless loop, until the player moves("enter does not count")
    while(true)
    {
        //wait for user input w,s,a,d, or enter to enter menu:
        c = getch();
        list<Item> playerItems;
        list<Enemy>::iterator lit;
        int enemyNum = 0;

        switch(c)
        {
            case 'w':
                //check fist if player is not paralized:
                if(cPlayer.getStat() == 'z')
                {
                    break;
                }
                else if(*(cPlayer.getCoordinates()) > 0 && levelMap[*(cPlayer.getCoordinates())-1][*(cPlayer.getCoordinates()+1)] == '.')
                {
                    cPlayer.setCoordinates(*(cPlayer.getCoordinates())-1, *(cPlayer.getCoordinates()+1));
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(cPlayer.getCoordinates())+1][*(cPlayer.getCoordinates()+1)] = '.';
                    levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)] = '_';
                }
                //in case there is an object, which is not a wall:
                else
                {
                    //a): there is a shop:
                    if(*(cPlayer.getCoordinates()) > 0 && *(cShop.getCoordinates()) == *(cPlayer.getCoordinates())-1 && *(cShop.getCoordinates()+1) == *(cPlayer.getCoordinates()+1))
                    {
                        cShop.enterShop(cPlayer, _cPaint);
                    }
                    //b): there is an enemy:
                    for(lit = cEnemies.begin(); lit != cEnemies.end(); lit++)
                    {
                        if(*(cPlayer.getCoordinates()) > 0 && *((*lit).getCoordinates()) == *(cPlayer.getCoordinates())-1 && *((*lit).getCoordinates()+1) == *(cPlayer.getCoordinates()+1))
                        if((*lit).dealDamage(cPlayer.attackEnemy()) == true)
                        {
                            //get some money and xp from the enemy:
                            cPlayer.setMoney(cPlayer.getMoney()+(*lit).getAttack()*5);
                            if(cPlayer.gainExp((*lit).getAttack()*20))
                                _cPaint.messageLevelUp();
                            //turn the enemy tile from '_', to an empty '_':
                            levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)] = '.';
                            cEnemies.erase(lit);
                            break;
                        }
                        enemyNum++;
                    }
                    //c) there is a savestate:
                    if(*(cPlayer.getCoordinates()) > 0 && *(cSaveState.getCoordinates()) == *(cPlayer.getCoordinates())-1 && *(cSaveState.getCoordinates()+1) == *(cPlayer.getCoordinates()+1))
                    {
                        cPlayer.getPlayerItems(playerItems);
                        cSaveState.openSaveMenu(_cPaint, levelNum, cOptions.getNumOfEnemies(), enemyNum, cOptions.getSaveDuringGame(), cOptions.getShopAvailable(), cPlayer.getCurrHealth(), cPlayer.getMaxhealth(), cPlayer.getExp(), cPlayer.getMoney(), cPlayer.getStat(), *(cShop.getCoordinates()), *(cShop.getCoordinates()+1), *(cSaveState.getCoordinates()), *(cSaveState.getCoordinates()+1), *(cPlayer.getCoordinates()), *(cPlayer.getCoordinates()+1), ladderCoordinates, cPlayer.getEquippedShield().getName(), cPlayer.getEquippedWearpon().getName(), playerItems);
                    }
                    //d) there is an exit:
                    if(*(cPlayer.getCoordinates()) > 0 && ladderCoordinates[0] == *(cPlayer.getCoordinates())-1 && ladderCoordinates[1] == *(cPlayer.getCoordinates()+1))
                    {
                        return 'h';
                    }

                }
                break;

            case 's':
                //check fist if player is not paralized:
                if(cPlayer.getStat() == 'z')
                {
                    break;
                }
                else if(*(cPlayer.getCoordinates()) < MAX_LEVEL_DIMENSION && levelMap[*(cPlayer.getCoordinates())+1][*(cPlayer.getCoordinates()+1)] == '.')
                {
                    cPlayer.setCoordinates(*(cPlayer.getCoordinates())+1, *(cPlayer.getCoordinates()+1));
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(cPlayer.getCoordinates())-1][*(cPlayer.getCoordinates()+1)] = '.';
                    levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)] = '_';
                }
                //in case there is an object, which is not a wall:
                else
                {
                    //a): there is a shop:
                    if(*(cPlayer.getCoordinates()) < MAX_LEVEL_DIMENSION && *(cShop.getCoordinates()) == *(cPlayer.getCoordinates())+1 && *(cShop.getCoordinates()+1) == *(cPlayer.getCoordinates()+1))
                    {
                        cShop.enterShop(cPlayer, _cPaint);
                    }

                    //b): there is an enemy:
                    for(lit = cEnemies.begin(); lit != cEnemies.end(); lit++)
                    {
                        if(*(cPlayer.getCoordinates()) < MAX_LEVEL_DIMENSION && *((*lit).getCoordinates()) == *(cPlayer.getCoordinates())+1 && *((*lit).getCoordinates()+1) == *(cPlayer.getCoordinates()+1))
                        if((*lit).dealDamage(cPlayer.attackEnemy()) == true)
                        {
                            //get some money and xp from the enemy:
                            cPlayer.setMoney(cPlayer.getMoney()+(*lit).getAttack()*5);
                            if(cPlayer.gainExp((*lit).getAttack()*20))
                                _cPaint.messageLevelUp();
                            //turn the enemy tile from '_', to an empty '_':
                            levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)] = '.';
                            cEnemies.erase(lit);
                            break;
                        }
                        enemyNum++;
                    }
                     //c) there is a savestate:
                    if(*(cPlayer.getCoordinates()) < MAX_LEVEL_DIMENSION && *(cSaveState.getCoordinates()) == *(cPlayer.getCoordinates())+1 && *(cSaveState.getCoordinates()+1) == *(cPlayer.getCoordinates()+1))
                    {
                        cPlayer.getPlayerItems(playerItems);
                        cSaveState.openSaveMenu(_cPaint, levelNum, cOptions.getNumOfEnemies(), enemyNum, cOptions.getSaveDuringGame(), cOptions.getShopAvailable(), cPlayer.getCurrHealth(), cPlayer.getMaxhealth(), cPlayer.getExp(), cPlayer.getMoney(), cPlayer.getStat(), *(cShop.getCoordinates()), *(cShop.getCoordinates()+1), *(cSaveState.getCoordinates()), *(cSaveState.getCoordinates()+1), *(cPlayer.getCoordinates()), *(cPlayer.getCoordinates()+1), ladderCoordinates, cPlayer.getEquippedShield().getName(), cPlayer.getEquippedWearpon().getName(), playerItems);
                    }
                    //d) there is an exit:
                    if(*(cPlayer.getCoordinates()) < MAX_LEVEL_DIMENSION && ladderCoordinates[0] == *(cPlayer.getCoordinates())+1 && ladderCoordinates[1] == *(cPlayer.getCoordinates()+1))
                    {
                        return 'h';
                    }

                }
                break;

            case 'a':
                //check fist if player is not paralized:
                if(cPlayer.getStat() == 'z')
                {
                    break;
                }
                else if(*(cPlayer.getCoordinates()+1) > 0 && levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)-1] == '.')
                {
                    cPlayer.setCoordinates(*(cPlayer.getCoordinates()), *(cPlayer.getCoordinates()+1)-1);
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)+1] = '.';
                    levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)] = '_';
                }
                //in case there is an object, which is not a wall:
                else
                {
                    //a): there is a shop:
                    if(*(cPlayer.getCoordinates()+1) > 0 && *(cShop.getCoordinates()) == *(cPlayer.getCoordinates()) && *(cShop.getCoordinates()+1) == *(cPlayer.getCoordinates()+1)-1)
                        cShop.enterShop(cPlayer, _cPaint);
                    //b): there is an enemy:
                    for(lit = cEnemies.begin(); lit != cEnemies.end(); lit++)
                    {
                        if(*(cPlayer.getCoordinates()+1) > 0 && *((*lit).getCoordinates()) == *(cPlayer.getCoordinates()) && *((*lit).getCoordinates()+1) == *(cPlayer.getCoordinates()+1)-1)
                        if((*lit).dealDamage(cPlayer.attackEnemy()) == true)
                        {
                            //get some money and xp from the enemy:
                            cPlayer.setMoney(cPlayer.getMoney()+(*lit).getAttack()*5);
                            if(cPlayer.gainExp((*lit).getAttack()*20))
                                _cPaint.messageLevelUp();
                            //turn the enemy tile from '_', to an empty '_':
                            levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)] = '.';
                            cEnemies.erase(lit);
                            break;
                        }
                        enemyNum++;
                    }
                     //c) there is a savestate:
                    if(*(cPlayer.getCoordinates()+1) > 0 && *(cSaveState.getCoordinates()) == *(cPlayer.getCoordinates()) && *(cSaveState.getCoordinates()+1) == *(cPlayer.getCoordinates()+1)-1)
                    {
                        cPlayer.getPlayerItems(playerItems);
                        cSaveState.openSaveMenu(_cPaint, levelNum, cOptions.getNumOfEnemies(), enemyNum, cOptions.getSaveDuringGame(), cOptions.getShopAvailable(), cPlayer.getCurrHealth(), cPlayer.getMaxhealth(), cPlayer.getExp(), cPlayer.getMoney(), cPlayer.getStat(), *(cShop.getCoordinates()), *(cShop.getCoordinates()+1), *(cSaveState.getCoordinates()), *(cSaveState.getCoordinates()+1), *(cPlayer.getCoordinates()), *(cPlayer.getCoordinates()+1), ladderCoordinates,  cPlayer.getEquippedShield().getName(), cPlayer.getEquippedWearpon().getName(), playerItems);
                    }
                    //d) there is an exit:
                    if(*(cPlayer.getCoordinates()) > 0 && ladderCoordinates[0] == *(cPlayer.getCoordinates()) && ladderCoordinates[1] == *(cPlayer.getCoordinates()+1)-1)
                    {
                        return 'h';
                    }

                }
                break;

            case 'd':
                //check fist if player is not paralized:
                if(cPlayer.getStat() == 'z')
                {
                    break;
                }
                else if(*(cPlayer.getCoordinates()+1) < MAX_LEVEL_DIMENSION && levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)+1] == '.')
                {
                    cPlayer.setCoordinates(*(cPlayer.getCoordinates()), *(cPlayer.getCoordinates()+1)+1);
                    //turn the last tile back to '.', and turn the new one to '_':
                    levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)-1] = '.';
                    levelMap[*(cPlayer.getCoordinates())][*(cPlayer.getCoordinates()+1)] = '_';
                }
                //in case there is an object, which is not a wall:
                else
                {
                    //a): there is a shop:
                    if(*(cPlayer.getCoordinates()+1) < MAX_LEVEL_DIMENSION && *(cShop.getCoordinates()) == *(cPlayer.getCoordinates()) && *(cShop.getCoordinates()+1) == *(cPlayer.getCoordinates()+1)+1)
                        cShop.enterShop(cPlayer, _cPaint);
                    //b): there is an enemy:
                    for(lit = cEnemies.begin(); lit != cEnemies.end(); lit++)
                    {
                        if(*(cPlayer.getCoordinates()+1) < MAX_LEVEL_DIMENSION && *((*lit).getCoordinates()) == *(cPlayer.getCoordinates()) && *((*lit).getCoordinates()+1) == *(cPlayer.getCoordinates()+1)+1)
                        if((*lit).dealDamage(cPlayer.attackEnemy()) == true)
                        {
                            //get some money and xp from the enemy:
                            cPlayer.setMoney(cPlayer.getMoney()+(*lit).getAttack()*5);
                            if(cPlayer.gainExp((*lit).getAttack()*20))
                                _cPaint.messageLevelUp();
                            //turn the enemy tile from '_', to an empty '_':
                            levelMap[*((*lit).getCoordinates())][*((*lit).getCoordinates()+1)] = '.';
                            cEnemies.erase(lit);
                            break;
                        }
                        enemyNum++;
                    }
                     //c) there is a savestate:
                    if(*(cPlayer.getCoordinates()+1) < MAX_LEVEL_DIMENSION  && *(cSaveState.getCoordinates()) == *(cPlayer.getCoordinates()) && *(cSaveState.getCoordinates()+1) == *(cPlayer.getCoordinates()+1)+1)
                    {
                        cPlayer.getPlayerItems(playerItems);
                        cSaveState.openSaveMenu(_cPaint, levelNum, cOptions.getNumOfEnemies(), enemyNum, cOptions.getSaveDuringGame(), cOptions.getShopAvailable(), cPlayer.getCurrHealth(), cPlayer.getMaxhealth(), cPlayer.getExp(), cPlayer.getMoney(), cPlayer.getStat(), *(cShop.getCoordinates()), *(cShop.getCoordinates()+1), *(cSaveState.getCoordinates()), *(cSaveState.getCoordinates()+1), *(cPlayer.getCoordinates()), *(cPlayer.getCoordinates()+1), ladderCoordinates, cPlayer.getEquippedShield().getName(), cPlayer.getEquippedWearpon().getName(), playerItems);
                    }
                    //d) there is an exit:
                    if(*(cPlayer.getCoordinates()) < MAX_LEVEL_DIMENSION && ladderCoordinates[0] == *(cPlayer.getCoordinates()) && ladderCoordinates[1] == *(cPlayer.getCoordinates()+1)+1)
                    {
                        return 'h';
                    }

                }
                break;

            case '\r':
                if(playerMenu.openMenu(cPlayer, _cPaint) == true)
                    return 'q';
                else
                    return 'c';

        }
        if(c == 'w' || c == 's' || c == 'a' || c == 'd')
            break;

    }
    //return false if the player has not quitted:
    return 'c';

}


void Level::randomizer(GlobalOptions &cOptions, Shop &cRandShop, LoadSaveGame &cRandSaveState, Character &cRandPlayer, list<Enemy> &randEnemies, char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int ladderCoordinates[2])
{
    //set the randomness of everything:
    srand(time(NULL));

    int myX = 0, myY = 0;
    //list iterator:
    list<Enemy>::iterator lit;

    //check if shops or savepoints are allowed in the game. If no, set their coordinates to [0:0]:
    if(cOptions.getShopAvailable() == false)
        cRandShop.setCoordinates(0,0);
    else
    {
        getRandomCoordinateForMap(myY, myX, levelMap);
        cRandShop.setCoordinates(myY, myX);
    }
    if(cOptions.getSaveDuringGame() == false)
        cRandSaveState.setCoordinates(0,0);
    else
    {
        getRandomCoordinateForMap(myY, myX, levelMap);
        cRandSaveState.setCoordinates(myY, myX);
    }

    //set a random exit to the next level:
    getRandomCoordinateForMap(myY, myX, levelMap);
    ladderCoordinates[0] = myY;
    ladderCoordinates[1] = myX;

    for(lit = randEnemies.begin(); lit != randEnemies.end(); lit++)
    {
        getRandomCoordinateForMapEnemiesAndPlayer(myY, myX, levelMap);
        (*lit).setCoordinates(myY, myX);
    }

    //get a random number in the size of the map, and do this until it will be an empty space '.':
    getRandomCoordinateForMapEnemiesAndPlayer(myY, myX, levelMap);
    cRandPlayer.setCoordinates(myY, myX);

}
