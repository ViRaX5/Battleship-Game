// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// ---------------------------------------
#include <iostream>
#include <cstdlib>   
#include <ctime>  
// -------------------------------------------   
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "AiPlayer.hpp"
// -------------------------------------------

int main() {
    // Seed the random number generator for AI placement and moves
    // You need it to stay HERE when you use random in the AiPlayer class
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create two players: one human, one AI
    Player* p1 = new HumanPlayer("Human");
    Player* p2 = new AiPlayer("Computer");

    // Create  2 AiPlayers:
    // Player* p1 = new AiPlayer("PC1");
    // Player* p2 = new AiPlayer("PC2");
    
    // Create the Game object with the two players
    Game game(p1, p2);

    // Set up the game (place all ships)
    game.setup();

    // Start the turn-by-turn gameplay
    game.start();

    return 0;
}