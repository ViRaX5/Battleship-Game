// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267
// -------------------------------------------
#include "Game.hpp"
// -------------------------------------------

Game::Game(Player *p1, Player *p2)
{
    Game::player1 = p1;
    Game::player2 = p2;
}

void Game::setup()
{
    std::cout << "Placing ships!" << std::endl;
    player1->placeAllShips();
    player2->placeAllShips();
}

void Game::start()
{
    bool gameOver = false;
    bool p1Won = false;
    int turn = 0;

    while (turn < MAX_TURNS_PER_PLAYER && !gameOver)
    {
        player1->makeMove(player2);
        if (player2->allShipsSunk())
        {
            p1Won = true;
            gameOver = true;
            break;
        }
        player2->makeMove(player1);
        if (player1->allShipsSunk())
        {
            p1Won = false;
            gameOver = true;
            break;
        }
        ++turn;
        displayStatus();
    }

    bool draw = (!gameOver && turn == MAX_TURNS_PER_PLAYER);

    if (draw)
        std::cout << "Simulation ended in a DRAW (Max turns reached)." << std::endl;

    std::cout << player1->getName() << "'s board:" << std::endl;
    player1->getGrid().print();
    std::cout << player2->getName() << "'s board:" << std::endl;
    player2->getGrid().print();
    
    if (!draw)
        std::cout << "Congragulation!\n"
                  << (p1Won ? player1->getName() : player2->getName()) << " won!" << std::endl;
}

bool Game::isGameOver() const
{
    return (player1->allShipsSunk() || player2->allShipsSunk());
}

void Game::displayStatus()
{
    using namespace std;
    cout << player1->getName() << "'s board:" << endl;
    player1->getGrid().print(true, true); // show Axes, hide ships;
}
