#ifndef GLOBALOPTIONS_H
#define GLOBALOPTIONS_H
#include <conio.h>
#include "PaintScreen.h"


class GlobalOptions
{
    public:
        GlobalOptions();
        void optionsMenu(PaintScreen cPaint, GlobalOptions &cOptions);

        //setters:
        void setLife(int life);
        void setNumOfEnemies(int num_of_enemies);
        void setStartingBudget(int starting_budget);
        void setSaveDuringGame(bool save_during_game);
        void setShopAvailable(bool shop_available);

        //getters:
        int getLife();
        int getNumOfEnemies();
        int getStartingBudget();
        bool getSaveDuringGame();
        bool getShopAvailable();


    private:

        int _life;
        int _num_of_enemies;
        int _starting_budget;
        bool _shop_available;
        bool _save_during_game;

        int _optionsArrow;
        char _optionsKey;

        bool selectOption(GlobalOptions &cOptions);
        //private getters and setters:
        void setOptionsArrow(int optionsArrow);
        void setOptionsKey(char optionsKey);
        int getOptionsArrow();
        char getOptionsKey();
};

#endif // GLOBALOPTIONS_H
