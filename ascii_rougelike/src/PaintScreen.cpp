#include "PaintScreen.h"



PaintScreen::PaintScreen()
{
    //ctor
}


bool PaintScreen::hasListCoordinates(list<Enemy> &cEnemies, int y, int x)
{
    list<Enemy>::iterator lit;

    for(lit = cEnemies.begin(); lit != cEnemies.end(); lit++)
    {
        if(*(*lit).getCoordinates() == y && *((*lit).getCoordinates()+1) == x)
            return true;
    }
    return false;
}


void PaintScreen::clearScreen()
{
    string clearScreenString(50, '\n');
    cout << clearScreenString;
}
void PaintScreen::messageCannotAfford()
{
    cout << "You cannot afford to buy it!" << endl;
}
void PaintScreen::messageCannotSellEquippedItem()
{
    cout << "You cannot sell equipped item!" << endl;
}
void PaintScreen::messageCannotTossEquippedWearpon()
{
    cout << "Cannot toss equipped wearpon!" << endl;
}
void PaintScreen::messageCannotTossEquippedShield()
{
    cout << "Cannot toss equipped shield!" << endl;
}
void PaintScreen::messageCongrats()
{
    cout << "Congratulations! You have completed the game!\n";
    cout << "Feel free to adjust the settings if you feel like you need more challenge!\n";
}
void PaintScreen::messageEnemyAttackMissed()
{
    cout << "Enemy attack missed!" << endl;
}
void PaintScreen::messageEnterSavestateName()
{
    cout << "Please enter savestate name: " << endl;
}
void PaintScreen::messageGameOver()
{
    cout << "Game Over" << endl << endl;
}
void PaintScreen::messageItemBought()
{
    cout << "You bought the item!" << endl;
}
void PaintScreen::messageItemSold()
{
    cout << "Item sold!" << endl;
}
void PaintScreen::messageItemTossed()
{
    cout << "Item disposed!" << endl;
}
void PaintScreen::messageHealthHealed()
{
    cout << "Health restored!" << endl;
}
void PaintScreen::messageNoEffect()
{
    cout << "It wouldn't have any effect!" << endl;
}
void PaintScreen::messageParlzHealed()
{
    cout << "Paralizis healed!" << endl;
}
void PaintScreen::messagePoisonHealed()
{
    cout << "Poisoning healed!" << endl;
}
void PaintScreen::messageShieldEquipped()
{
    cout << "Shield equipped!" << endl;
}
void PaintScreen::messageShieldAlreadyEquipped()
{
    cout << "Shield already equipped!" << endl;
}
void PaintScreen::messageWearponEquipped()
{
    cout << "Wearpon equipped!" << endl;
}
void PaintScreen::messageWearponAlreadyEquipped()
{
    cout << "Wearpon already equipped!" << endl;
}
void PaintScreen::messageYouBecameParalized()
{
    cout << "You became paralized!" << endl;
}
void PaintScreen::messageYouBecamePoisoned()
{
    cout << "You became poisoned!" << endl;
}
void PaintScreen::paintItems(string item, int itemArrow, int itemArrowCompare)
{
    if(itemArrow == itemArrowCompare)
    {
        cout << "> ";
        cout << item << endl;
    }
    else
        cout << "  " << item << endl;
}

void PaintScreen::paintMenuBack(int itemArrow, int itemArrowCompare)
{
    if(itemArrow == itemArrowCompare)
    {
        cout << "> ";
        cout << "Back" << endl << endl;
    }
    else
        cout << "  " << "Back" << endl << endl;
}

void PaintScreen::paintMenuSell(int itemArrow, int itemArrowCompare)
{
    if(itemArrow == itemArrowCompare)
    {
        cout << "> Sell" << endl;
        cout << "  Back" << endl << endl;
    }
    else if(itemArrow == itemArrowCompare+1)
    {
        cout << "  Sell" << endl;
        cout << "> Back" << endl << endl;
    }
    else
    {
        cout << "  Sell" << endl;
        cout << "  Back" << endl  << endl;
    }
}

void PaintScreen::paintItemDetails(string name, string desc, int pieceOf, int attack, int defence, int heal, int buyPrice, int sellPrince, int selectArrow)
{
    cout << name << endl;
    cout << desc << endl;
    cout << pieceOf << " Piece(s)" << endl;
    cout << "attack: " << attack << endl;
    cout << "defence: " << defence << endl;
    cout << "heal: " << heal << endl;
    cout << "buy price: " << buyPrice << endl;
    cout << "sell price: " << sellPrince << endl;

    switch(selectArrow)
    {
        case 0:
        printf("> Use\n");
        printf("  Throw away\n");
        printf("  Back\n");
        break;

        case 1:
        printf("  Use\n");
        printf("> Throw away\n");
        printf("  Back\n");
        break;

        case 2:
        printf("  Use\n");
        printf("  Throw away\n");
        printf("> Back\n");
        break;
    }

}

void PaintScreen::paintShopItemDetails(string name, string desc, int pieceOf, int attack, int defence, int heal, int buyPrice, int sellPrince, int selectArrow)
{
    cout << name << endl;
    cout << desc << endl;
    cout << pieceOf << " Piece available for sale" << endl;
    cout << "attack: " << attack << endl;
    cout << "defence: " << defence << endl;
    cout << "heal: " << heal << endl;
    cout << "buy price: " << buyPrice << endl;
    cout << "sell price: " << sellPrince << endl;

    switch(selectArrow)
    {
        case 0:
        printf("> Buy\n");
        printf("  Back\n\n");
        break;

        case 1:
        printf("  Buy\n");
        printf("> Back\n\n");
        break;
    }

}


void PaintScreen::PaintLoadMenu(string name1, string name2, string name3, int arrow)
{
    cout << "Select the file to load your progress:\n\n";

    switch(arrow)
    {
        case 0:
            cout << "> " << name1 << endl;
            cout << "  " << name2 << endl;
            cout << "  " << name3 << endl << endl;
            cout << "  " << "Back\n";
            break;

        case 1:
            cout << "  " << name1 << endl;
            cout << "> " << name2 << endl;
            cout << "  " << name3 << endl << endl;
            cout << "  " << "Back\n";
            break;

        case 2:
            cout << "  " << name1 << endl;
            cout << "  " << name2 << endl;
            cout << "> " << name3 << endl << endl;
            cout << "  " << "Back\n";
            break;

        case 3:
            cout << "  " << name1 << endl;
            cout << "  " << name2 << endl;
            cout << "  " << name3 << endl << endl;
            cout << "> " << "Back\n";
            break;

    }
}

void PaintScreen::PaintSaveMenu(string name1, string name2, string name3, int arrow)
{
    cout << "Select the file to save your progress:\n\n";

    switch(arrow)
    {
        case 0:
            cout << "> " << name1 << endl;
            cout << "  " << name2 << endl;
            cout << "  " << name3 << endl << endl;
            cout << "  " << "Back\n";
            break;

        case 1:
            cout << "  " << name1 << endl;
            cout << "> " << name2 << endl;
            cout << "  " << name3 << endl << endl;
            cout << "  " << "Back\n";
            break;

        case 2:
            cout << "  " << name1 << endl;
            cout << "  " << name2 << endl;
            cout << "> " << name3 << endl << endl;
            cout << "  " << "Back\n";
            break;

        case 3:
            cout << "  " << name1 << endl;
            cout << "  " << name2 << endl;
            cout << "  " << name3 << endl << endl;
            cout << "> " << "Back\n";
            break;

    }
}

void PaintScreen::paintSellToShop(Character &cPlayer)
{

}

void PaintScreen::paintMainMenu(bool (*arrow)[2])
{
    //Wipe screen clear:
    clearScreen();

    //Paint title screen:
    printf("######################################################################\n");
    printf("#                                                                    #\n");
    printf("#    @@@@@@    @@@@     @@@@      @@     @@@@@    @@@@@@   @@@@@     #\n");
    printf("#    @        @    @   @    @    @  @    @    @   @        @    @    #\n");
    printf("#    @        @        @        @    @   @    @   @        @    @    #\n");
    printf("#    @@@@@@    @@@@    @        @@@@@@   @@@@@    @@@@@@   @@@@@     #\n");
    printf("#    @             @   @        @    @   @        @        @  @      #\n");
    printf("#    @        @    @   @    @   @    @   @        @        @   @     #\n");
    printf("#    @@@@@@    @@@@     @@@@    @    @   @        @@@@@@   @    @    #\n");
    printf("#                                                                    #\n");
    printf("######################################################################\n\n");

    printf("2018 by Niznize\n\n\n");


    if(arrow[0][0] == true)
        paintMainMenu_newGame();
    if(arrow[0][1] == true)
        paintMainMenu_loadGame();
    if(arrow[1][0] == true)
        paintMainMenu_options();
    if(arrow[1][1] == true)
        paintMainMenu_quit();

}
void PaintScreen::paintMainMenu_newGame()
{
    printf("   > New Game      Options\n");
    printf("     Load Game     Quit\n");

}
void PaintScreen::paintMainMenu_options()
{
    printf("     New Game    > Options\n");
    printf("     Load Game     Quit\n");
}
void PaintScreen::paintMainMenu_loadGame()
{
    printf("     New Game      Options\n");
    printf("   > Load Game     Quit\n");
}
void PaintScreen::paintMainMenu_quit()
{
    printf("     New Game      Options\n");
    printf("     Load Game   > Quit\n");
}

void PaintScreen::paintLevelMap(char levelMap[MAX_LEVEL_DIMENSION][MAX_LEVEL_DIMENSION], int *pPlayer, int *pShop, int *pSaveState, list<Enemy> &cEnemies, int ladderCoordinates[2])
{


    int x, y;

    for(y = 0; y <  MAX_LEVEL_DIMENSION; y++)
    {
        for(x = 0; x < MAX_LEVEL_DIMENSION; x++)
        {
            //The [0][0] coordinate is for dispose. it will always be a wall:
            if(x == 0 && y == 0)
                cout << '#';
            //check for randomly placed objects:
            else if(*pShop == y && *(pShop+1) == x)
                cout << 'M';
            else if(*pSaveState == y && *(pSaveState+1) == x)
                cout << 'Q';
            else if(hasListCoordinates(cEnemies, y, x) == true)
                cout << 'S';
            else if(ladderCoordinates[0] == y && ladderCoordinates[1] == x)
                cout << 'H';
            else if(*pPlayer == y && *(pPlayer+1) == x)
                cout << '@';
            else
            {
                cout << levelMap[y][x];
                if(levelMap[y][x] == '\n' || levelMap[y][x] == '\000')
                    break;
            }
        }
        if(levelMap[y][x] == '\000')
            break;

    }
    cout << endl;
}


void PaintScreen::paintOptionsMenu(int life, int enemies, int money, bool saveOk, bool shopOk, int arrow)
{
    switch(arrow)
    {
        case 0:
        printf("> Life: %d\n", life);
        printf("  Enemies: %d\n", enemies);
        printf("  Starting money: %d\n", money);
        printf("  Save during the game: %d\n", saveOk);
        printf("  Shop available: %d\n", shopOk);
        printf("  Back\n");
        break;

        case 1:
        printf("  Life: %d\n", life);
        printf("> Enemies: %d\n", enemies);
        printf("  Starting money: %d\n", money);
        printf("  Save during the game: %d\n", saveOk);
        printf("  Shop available: %d\n", shopOk);
        printf("  Back\n");
        break;

        case 2:
        printf("  Life: %d\n", life);
        printf("  Enemies: %d\n", enemies);
        printf("> Starting money: %d\n", money);
        printf("  Save during the game: %d\n", saveOk);
        printf("  Shop available: %d\n", shopOk);
        printf("  Back\n");
        break;

        case 3:
        printf("  Life: %d\n", life);
        printf("  Enemies: %d\n", enemies);
        printf("  Starting money: %d\n", money);
        printf("> Save during the game: %d\n", saveOk);
        printf("  Shop available: %d\n", shopOk);
        printf("  Back\n");
        break;

        case 4:
        printf("  Life: %d\n", life);
        printf("  Enemies: %d\n", enemies);
        printf("  Starting money: %d\n", money);
        printf("  Save during the game: %d\n", saveOk);
        printf("> Shop available: %d\n", shopOk);
        printf("  Back\n");
        break;

        case 5:
        printf("  Life: %d\n", life);
        printf("  Enemies: %d\n", enemies);
        printf("  Starting money: %d\n", money);
        printf("  Save during the game: %d\n", saveOk);
        printf("  Shop available: %d\n", shopOk);
        printf("> Back\n");
        break;

        default:
        printf("At \"PaintScreen::paintOptionsMenu\" wrong number for the arrow selection variable");

    }

}

void PaintScreen::paintPlayerMenu(int arrow, int health, int maxHealth, char stat, int money, int exp, string attackItem, string defenceItem)
{

    //clear screen:
    clearScreen();

    printf("Health: %d/%d\n", health, maxHealth);
    printf("Status: %c\n", stat);
    printf("Money: %d\n", money);
    printf("Exp. points: %d\n", exp);
    cout << "Equipped wearpon: " << attackItem << endl;
    cout <<"Equipped shield: " << defenceItem << endl;

    cout << endl;

    switch(arrow)
    {
        case 0:
        cout << "> Items" << endl;
        cout << "  Back" << endl;
        cout << "  Quit game" << endl << endl;
        break;

        case 1:
        cout << "  Items" << endl;
        cout << "> Back" << endl;
        cout << "  Quit game" << endl << endl;
        break;

        case 2:
        cout << "  Items" << endl;
        cout << "  Back" << endl;
        cout << "> Quit game" << endl << endl;
        break;

        default:
        //not used atm
        break;
    }


/*
    playerMenu.getItems(cItems);

    for(lit = cItems.begin(); lit != cItems.end(); lit++)
    {
        cout << (*lit).getName() << endl;
    }
*/
    cout << endl;

}


void PaintScreen::paintPlayerStats(Character &cPlayer)
{
    //Paint out the lives:
    for(int h = 0; h < cPlayer.getCurrHealth(); h++)
    {
        printf("<3 ");
    }
    printf("\t Money: %d\n", cPlayer.getMoney());

}

void PaintScreen::paintWelcomeAtShop()
{
    cout << "**** Welcome to the local grocery store! ****\n\n";
    cout << "Please look around: \n\n\n";

}
