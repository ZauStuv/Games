/*
    Ascii Rougelike game by Zaustuv (aka Niznize), 2018
    License according to GNU GPL

    This game is a text-based command line rougelike game, with customizable levels, adjustable difficulty and load/save funcions.
    Each level is built up on a <> x <> map, from characters having the following meaning:

    @: Player. You can move up/down/left/right by pressing one of the WSAD buttons at once. You cannot walk through walls, enemies, shops
        or exits, but you can press 'E' to enter the latter two, or <spacebar> to attack the enemy. You can also have different wearpons
        which you can change in the menu.
    S: Enemy. They move in a random fashion, and can attack 1 tile away from you.
    Z: Super enemy. They have more life, and can attack you from 2 tiles away.
    M: Shop. You can buy many useful items here.
    Q: savestate.
    #: Wall. You cannot walk through this place.
    H: Door: Press 'E' in front of it to enter to the next level!

    Other important notes:
    - Enemies do not move until you move.
    - You can get money and XP after defeating enemies. after reaching enough XP, you can level up!
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
