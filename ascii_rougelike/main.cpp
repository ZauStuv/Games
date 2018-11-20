/*
    Ascii Rougelike game by Zaustuv (aka Niznize), 2018
    License according to GNU GPL

    This game is a text-based command line rougelike game, with 9 levels, adjustable difficulty and load/save funcions.
    Each level is built up on a customizable sized map, from characters having the following meaning:

    @: Player. You can move up/down/left/right by pressing one of the WSAD buttons at once. You cannot walk through walls, enemies, shops
        or exits. You can also use the WSAD buttons to attack an enemy in front of you. You can also have different wearpons or shields,
        but only one of each equipped. You can change this item in the player menu.
    S: Enemy. They move in a random fashion, and can attack 1 tile away from you.
    M: Shop. You can buy many useful items here.
    Q: Safe house.
    #: Wall. You cannot walk through this place.
    H: Door: Press 'E' in front of it to enter to the next level!

    Other important notes:
    - Enemies do not move until you move.
    - You can get money and XP after defeating enemies. after reaching enough XP, you can level up! Level up boost the stats of your equipped
    wearpon
*/


#include <iostream>
#include "GameSequence.h"

using namespace std;

int main()
{

    //Game start
    GameSequence mGame;


    //Main sequence game
    mGame.loadMainMenu();

    //Game end.



    return EXIT_SUCCESS;
}
