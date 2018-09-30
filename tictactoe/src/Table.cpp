#include "Table.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


void cGetChar(char *singleChar)
{
    string input = "";

    while (true) {

        getline(cin, input);
        if (input.length() == 1) {
            *singleChar = input[0];
            break;
        }
        cout << "Invalid character, please try again" << endl;
    }
}

void cGetCharB(char *singleChar)
{
    string input = "";
    int arb = 0;

    while (true) {

        getline(cin, input);
        if (input.length() == 1) {
            *singleChar = input[0];
            break;
        }
        if(arb)
            cout << "Invalid character, please try again" << endl;
        arb++;
    }
}


void cGetInt(int *singleNum)
{
    string input = "";

    while (true)
    {
        getline(cin, input);

        // This code converts from string to number safely.
        stringstream myStream(input);
        if (myStream >> *singleNum)
            break;
        cout << "Invalid number, please try again" << endl;
    }
}

void checkWinMarker(int *winMarker, int width, int height)
{
    while(true)
    {
        cGetInt(winMarker);

        if(*winMarker > width || *winMarker > height)
            cout << "Please enter a lower value!\n";
        else
            return;
    }
}

bool sonar(int winNum, char p1Hit[17][17], int y, int x)
{
    int leftDown = 0, down = 0, rightDown = 0, right = 0;
    //look around, from left-down to right:
    if(p1Hit[y+1][x-1] == 'x')
    {
        leftDown++;
        for(int i = 2; i < winNum; i++)
        {
            if(p1Hit[y+i][x-i] != 'x')
            break;
            //else
            leftDown++;
        }
    }
    if(p1Hit[y+1][x] == 'x')
    {
        down++;
        for(int i = 2; i < winNum; i++)
        {
            if(p1Hit[y+i][x] != 'x')
            break;
            //else
            down++;
        }
    }
    if(p1Hit[y+1][x+1] == 'x')
    {
        rightDown++;
        for(int i = 2; i < winNum; i++)
        {
            if(p1Hit[y+i][x+i] != 'x')
            break;
            //else
            rightDown++;
        }
    }
        if(p1Hit[y][x+1] == 'x')
    {
        right++;
        for(int i = 2; i < winNum; i++)
        {
            if(p1Hit[y][x+i] != 'x')
            break;
            //else
            right++;
        }
    }
    //evaluate if any value has reached the winning number:
    if(leftDown == winNum-1 || down == winNum-1 || rightDown == winNum-1 || right == winNum-1)
        return true;
    return false;

}




Table::Table()
{
    for(int y = 0; y < 15; y++)
    {
        for(int x = 0; x < 15; x++)
        {
            _p1hit[y][x] = '\0';
            _p2hit[y][x] = '\0';
            _p3hit[y][x] = '\0';
            _p4hit[y][x] = '\0';
        }
    }
    _width = 0, _height = 0, _winMarkerNum = 0;
}

void Table::initTable()
{

    do
    {
        cout << "How wide would you like the board to be? (Enter a number between 3 and 15) ";
        cGetInt(&_width);



 //       cin >> _width;

        if(_width < 3 || _width > 15)
            cout << "Wrong value. Please enter a valid number!\n";
    }while(_width < 3 || _width > 15);

    do
    {
        cout << "How high would you like the board to be? (Enter a number between 3 and 15) ";
    //    cin >> _height;

        cGetInt(&_height);

        if(_height < 3 || _height > 15)
            cout << "Wrong value. Please enter a valid number!\n";
    }while(_height < 3 || _height > 15);


    do
    {
        cout << "How many markers, horizontal, vertical or diagonal would be needed for a win? (Enter a number between 3 and 15) ";
 //       cin >> _winMarkerNum;
        //check if the number of markers in more than the longest side:
        checkWinMarker(&_winMarkerNum, _width, _height);
        //cGetInt(&_winMarkerNum);

        if(_winMarkerNum < 3 || _winMarkerNum > 15)
            cout << "Wrong value. Please enter a valid number!\n";
    }while(_winMarkerNum < 3 || _winMarkerNum > 15);

}

void Table::createTable()
{
    cout << "Note that grid markers start from top left to bottom right (i.e. 1,1 is the furherest top left)\n\n";

    for(int y = 0; y < _height*2+2; y++)
    {
        for(int x = 0; x < _width*4+2; x++)
        {
            if(y % 2)
                cout << "-";
            else
            {
                if(!x)
                {
                    if(!y)
                        cout << "  ";
                    else
                        if(y < 20)
                        {
                            cout << y/2 << " ";
                        }

                        else
                            cout << y/2;
                }
                else
                {
                    if((!y && x < 40) || y)
                    {
                        if(!((x-1) % 4))
                        cout << "|";
                        else if(!(x % 2))
                            cout << " ";
                        else
                        {
                            if(!y)
                                cout << (x+1)/4;
                            else
                                cout << '.';
                        }
                    }
                    else
                    {
                        if(x > _width*4+1 - ((_width*4+1) / 41)*(_width-10))
                            cout << " ";
                        else if(!((x-1) % 3))
                            cout << "|";
                        else if(!((x+1) % 3))
                            cout << " ";
                        else
                            cout << (10+(x-39)/3);
                    }
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool Table::checkHit(int i, int x, int y)
{
    switch(i)
    {
        case 0:
        if(_p2hit[y][x] == 'x' || _p3hit[y][x] == 'x' || _p4hit[y][x] == 'x')
        {
            cout << "Please enter valid coordinates!\n";
            return true;
        }

        case 1:
        if(_p1hit[y][x] == 'x' || _p3hit[y][x] == 'x' || _p4hit[y][x] == 'x')
        {
            cout << "Please enter valid coordinates!\n";
            return true;
        }

        case 2:
        if(_p1hit[y][x] == 'x' || _p2hit[y][x] == 'x' || _p4hit[y][x] == 'x')
        {
            cout << "Please enter valid coordinates!\n";
            return true;
        }

        case 3:
        if(_p1hit[y][x] == 'x' || _p2hit[y][x] == 'x' || _p3hit[y][x] == 'x')
        {
            cout << "Please enter valid coordinates!\n";
            return true;
        }

        default:
        return false;

        break;
    }

}


bool Table::checkRange(int x, int y)
{
    if(x > _width || x < 1 || y > _height || y < 1)
    {
        cout << "The given value is out of the table's range!\n";
        return true;
    }
    else
        return false;
}





void Table::addHit(int i, int x, int y)
{
    switch(i)
    {
        case 0:
        _p1hit[y][x] = 'x';
        break;

        case 1:
        _p2hit[y][x] = 'x';
        break;

        case 2:
        _p3hit[y][x] = 'x';
        break;

        case 3:
        _p4hit[y][x] = 'x';
        break;

        default:
        cout << "Invalid player wants to make a hit\n";
        break;
    }

}

void Table::redrawTable(char symbol[4])
{

   cout << endl;

   for(int y = 0; y < _height*2+2; y++)
    {
        for(int x = 0; x < _width*4+2; x++)
        {
            if(y % 2)
                cout << "-";
            else
            {
                if(!x)
                {
                    if(!y)
                        cout << "  ";
                    else
                        if(y < 20)
                        {
                            cout << y/2 << " ";
                        }
                        else
                            cout << y/2;
                }
                else
                {
                    if((!y && x < 40) || y)
                    {
                        if(!((x-1) % 4))
                        cout << "|";
                        else if(!(x % 2))
                            cout << " ";
                        else
                        {
                            if(!y)
                                cout << (x+1)/4;
                            else
                            {
                                if(_p1hit[y/2][(x+1)/4] == 'x')
                                    cout << symbol[0];
                                if(_p2hit[y/2][(x+1)/4] == 'x')
                                    cout << symbol[1];
                                if(_p3hit[y/2][(x+1)/4] == 'x')
                                    cout << symbol[2];
                                if(_p4hit[y/2][(x+1)/4] == 'x')
                                    cout << symbol[3];
                                if( (_p1hit[y/2][(x+1)/4] != 'x') && (_p2hit[y/2][(x+1)/4] != 'x') && (_p3hit[y/2][(x+1)/4] != 'x')
                                    && (_p4hit[y/2][(x+1)/4] != 'x') )
                                    cout << '.';
                            }
                        }
                    }
                    else
                    {
                        if(x > _width*4+1 - ((_width*4+1) / 41)*(_width-10))
                            cout << " ";
                        else if(!((x-1) % 3))
                            cout << "|";
                        else if(!((x+1) % 3))
                            cout << " ";
                        else
                            cout << (10+(x-39)/3);
                    }
                }
            }
        }
        cout << endl;
    }
}


bool Table::evaluateHit(int i)
{
    bool winReached = false;
    //sweep through the table, row by row, from left to right, and look for the symbol:
    for(int y = 0; y < _height; y++)
    {
        for(int x = 0; x < _width; x++)
        {
            switch(i)
            {
                case 0:
                if(_p1hit[y][x] == 'x')
                {
                    //hit found! Look around for the same symbol in the neighbouring fields:
                    winReached = sonar(_winMarkerNum, _p1hit, y, x);
                    if(winReached == true)
                        return true;
                }
                case 1:
                if(_p2hit[y][x] == 'x')
                {
                    //hit found! Look around for the same symbol in the neighbouring fields:
                    winReached = sonar(_winMarkerNum, _p2hit, y, x);
                    if(winReached == true)
                        return true;
                }
                case 2:
                if(_p3hit[y][x] == 'x')
                {
                    //hit found! Look around for the same symbol in the neighbouring fields:
                    winReached = sonar(_winMarkerNum, _p3hit, y, x);
                    if(winReached == true)
                        return true;
                }
                case 3:
                if(_p4hit[y][x] == 'x')
                {
                    //hit found! Look around for the same symbol in the neighbouring fields:
                    winReached = sonar(_winMarkerNum, _p4hit, y, x);
                    if(winReached == true)
                        return true;
                }
            }
        }
    }
    return false;
}

void Table::clearValues()
{
    for(int y = 0; y < 15; y++)
    {
        for(int x = 0; x < 15; x++)
        {
            _p1hit[y][x] = '\0';
            _p2hit[y][x] = '\0';
            _p3hit[y][x] = '\0';
            _p4hit[y][x] = '\0';
        }
    }
}

bool Table::checkTableFull()
{
    int occupiedFieldCounter = 0, totalFieldCounter;

    totalFieldCounter = _width * _height;

    for(int y=0; y <= _height; y++)
    {
        for(int x = 0; x <= _width; x++)
        {
            if(_p1hit[y][x] != '\0')
                occupiedFieldCounter++;
            if(_p2hit[y][x] != '\0')
                occupiedFieldCounter++;
            if(_p3hit[y][x] != '\0')
                occupiedFieldCounter++;
            if(_p4hit[y][x] != '\0')
                occupiedFieldCounter++;
        }
    }
    if(occupiedFieldCounter >= totalFieldCounter)
        return true;
    return false;
}
