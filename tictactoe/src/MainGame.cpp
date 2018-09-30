#include "MainGame.h"
#include <iostream>
#include <sstream>

void announceWinner(string winner)
{
    cout << "The winner is " << winner << endl;

}

void checkSymbolMatch(char *pSymbol, int place)
{
    while(true)
    {
        cGetCharB(&pSymbol[place]);

        for(int i = place; i > 0; i--)
        {
            if(pSymbol[place] == pSymbol[i-1])
            {
                cout << "Symbol already used. Please choose another symbol!\n";
                break;
            }
            else if(i == 1)
                return;
        }
    }
}



MainGame::MainGame()
{
    string input = "";
    int arb = 0;

    cout << "Welcome to the tictactoe lite!\n\n";
    cout << "First I would like to ask your name: ";

    cin >> _player[0];

    cout << "Hello " << _player[0] << ", what symbol would you like to use? ";
    cGetCharB(&_symbol[0]);

    cout << endl;

    cout << "The next player should now enter its name: ";
    cin >> _player[1];

    cout << "Hello " << _player[1] << ", what symbol would you like to use? ";

    //check if the player does not want to use the same symbol as the last players:
    checkSymbolMatch(_symbol,1);

    _playerCount = 2;

    cout << endl;
    cout << "are there more players?(y/n)\n";

    while(true)
    {
        cGetChar(&_morePlayers);

        if(_morePlayers != 'y' && _morePlayers != 'n')
            cout << "Please enter 'y' or 'n'!\n";
        else
            break;

    }

    while(_morePlayers == 'y' && _playerCount < 4)
    {
        cout << "The next player should now enter its name: ";

        cin >> _player[_playerCount];
        cout << "Hello " << _player[_playerCount] << ", what symbol would you like to use? ";
        //check if the player does not want to use the same symbol as the last players:
        checkSymbolMatch(_symbol, _playerCount);

        //cin >> _symbol[_playerCount];
        cout << endl;
        _playerCount++;

        if(_playerCount < 4)
        {
            cout << "are there more players?(y/n)\n";
            cGetChar(&_morePlayers);

            while(_morePlayers != 'y' && _morePlayers != 'n')
            {
                cout << "Please enter 'y' or 'n'!\n";
                //cin >> _morePlayers;
                cGetChar(&_morePlayers);

            }
        }
    }
}

void MainGame::setupTable()
{
    table1.initTable();
    table1.createTable();
}


void MainGame::startGame()
{
    bool win = false;
    char replay = 'y';
    bool fieldOccupied = false;
    bool fieldInvalid = false;
    int x,y;

    while(replay == 'y')
    {
        while(win == false)
        {
            for(int i = 0; i < _playerCount; i++)
            {
                cout << _player[i] << " 's turn!\n";

                //Loop until player enters valid coordinates:
                do
                {
                cout << "Enter the X coordinate where you wish to place the marker: ";
                //cin >> x;
                cGetInt(&x);

                cout << "Enter the Y coordinate where you wish to place the marker: ";
                //cin >> y;
                cGetInt(&y);

                //see if symbol is inside the field:
                fieldInvalid = table1.checkRange(x, y);

                //see if someone has placed its symbol on the field already:
                fieldOccupied = table1.checkHit(i, x, y);

                }while(fieldOccupied == true || fieldInvalid == true);

                //if not, place it:
                table1.addHit(i, x, y);

                //draw table with hits
                table1.redrawTable(_symbol);

                //evaluate if the hits have won the game for someone:
                win = table1.evaluateHit(i);
                if(win == true)
                {
                    announceWinner(_player[i]);
                    break;
                }

            }

        }
        cout << "Do you want to play again?(y/n) ";
        cGetChar(&replay);
        while(replay != 'y' && replay != 'n')
        {
            cout << "Please enter 'y' or 'n'!\n";
            cin >> replay;
        }
        table1.clearValues();
        win = false;
    }
}
