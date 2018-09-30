#ifndef TABLE_H
#define TABLE_H


void cGetChar(char *singleChar);
void cGetCharB(char *singleChar);
void cGetInt(int *singleNum);
void checkWinMarker(int winMarker, int width, int height);

class Table
{
    public:
        Table();
        void initTable();
        void createTable();
        void redrawTable(char*);
        bool checkHit(int, int, int);
        bool checkRange(int, int);
        void addHit(int, int, int);
        bool evaluateHit(int);
        void clearValues();



    private:
        int _width, _height, _winMarkerNum;
        char _p1hit[17][17];
        char _p2hit[17][17];
        char _p3hit[17][17];
        char _p4hit[17][17];
};

#endif // TABLE_H
