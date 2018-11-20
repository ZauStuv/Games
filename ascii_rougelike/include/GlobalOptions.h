#ifndef GLOBALOPTIONS_H
#define GLOBALOPTIONS_H
#include <conio.h>
#include "PaintScreen.h"


class GlobalOptions
{
    public:
        GlobalOptions();

        /** @brief: Prints out the options menu.
        *
        *   Clears the screen and prints out the options menu to the display, and the arrow where it
        *   is pointing to.
        *
        *   @param: PaintScreen cPaint, GlobalOptions &cOptions
        *   @return: void
        */
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
        bool _save_during_game;
        bool _shop_available;
        int _starting_budget;


        int _optionsArrow;
        char _optionsKey;

        /** @brief: Changes the adjustable parameters.
        *
        *   Function waits until the user hits a button, then evaluates it.
        *   Case 'w', subtracts one from the <_optionsArrow> parameter.
        *   Case 's' adds one to it.
        *   Case 'a' subtracts 1 from the value of <_life>, <__num_of_enemies>, <_starting_budget>, <_shop_available> or <_save_during_game>,
        *   depending on the value of <_optionsArrow>
        *   Case 'd' adds 1 to the value of <_life>, <__num_of_enemies>, <_starting_budget>, <_shop_available> or <_save_during_game>,
        *   depending on the value of <_optionsArrow>
        *
        *   @param: cOptions: is needed because all the adjustable variables (including the arrow) are stored in this object.
        *   @return: void
        */
        bool selectOption(GlobalOptions &cOptions);
        //private getters and setters:
        void setOptionsArrow(int optionsArrow);
        void setOptionsKey(char optionsKey);
        int getOptionsArrow();
        char getOptionsKey();
};

#endif // GLOBALOPTIONS_H
