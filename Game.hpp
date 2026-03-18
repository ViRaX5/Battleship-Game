// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Player.hpp"
// -------------------------------------------
#define MAX_TURNS_PER_PLAYER 100
// -------------------------------------------

class Game
{
private:
    Player* player1;
    Player* player2;
public:
    /* -----------------------------------------------------------------------------------------
     * Function: Game::Game
     * Purpose : Creates the game controller and assigns players.
     * Input   : player pointers/references (Human + AI) or names
     * Output  : none
     * Notes   : Does not run the game loop until start() is called.
     * ----------------------------------------------------------------------------------------- */
    Game(Player* p1, Player* p2);

    ~Game() { delete player1; delete player2; }

    void setup();

    /* -----------------------------------------------------------------------------------------
     * Function: Game::start
     * Purpose : Runs the full turn-based game loop until one player loses all ships.
     * Input   : none
     * Output  : none
     * Notes   : After each move: print boards, then check win condition.
     * ----------------------------------------------------------------------------------------- */
    void start();

    bool isGameOver() const;

    void displayStatus();
};

