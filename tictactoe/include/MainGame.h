#ifndef MAINGAME_H
#define MAINGAME_H

#include <string>
#include "Table.h"

using namespace std;

void checkSymbolMatch(char *pSymbol, int place);

class MainGame
{
    public:

        MainGame();
        void setupTable();
        void startGame();




    private:

        Table table1;


        char _morePlayers;
        int _playerCount;

        string _player[4];
        char _symbol[4];
};

#endif // MAINGAME_H
