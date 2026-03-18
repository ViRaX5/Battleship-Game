// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#include "AiPlayer.hpp"
#include <cstdlib>      
// -------------------------------------------

AiPlayer::AiPlayer(const char* name) : Player(name) {}

int AiPlayer::getRowToPlaceShip()
{
    return getRandomCoordinate();
}

int AiPlayer::getColToPlaceShip()
{
    return getRandomCoordinate();
}

bool AiPlayer::getOrientationToPlaceShip()
{
    return getRandomCoordinate()%2;
}

int AiPlayer::getRandomCoordinate()
{
    return std::rand() % 10;
}

void AiPlayer::makeMove(Player* opponent)
{
    std::cout << "The AI is making a move!" << std::endl;
    while (true)
    {
        int row = getRowToPlaceShip();
        int col = getColToPlaceShip();
        if (opponent->getGrid().getCell(row, col) == '~')
        {
            std::cout << "The AI is attacking (" << row << "," << col << ")!" << std::endl;
            opponent->getGrid().markMiss(row, col);
            break;
        }
        else if (opponent->getGrid().getCell(row, col) == 'S')
        {
            for (int i = 0; i < NUM_OF_SHIPS; i++)
            {
                if (opponent->getShips()[i]->isHorizontal())
                {
                    if (row == opponent->getShips()[i]->getRow())
                    {
                        if (col >= opponent->getShips()[i]->getCol() && col < (opponent->getShips()[i]->getCol() + opponent->getShips()[i]->getSize()))
                        {
                            std::cout << "The AI is attacking (" << row << "," << col << ")!" << std::endl;
                            opponent->getShips()[i]->takeHit();
                            break;
                        }
                    }
                }
                else
                {
                    if (col == opponent->getShips()[i]->getCol())
                    {
                        if (row >= opponent->getShips()[i]->getRow() && row < (opponent->getShips()[i]->getRow() + opponent->getShips()[i]->getSize()))
                        {
                            std::cout << "The AI is attacking (" << row << "," << col << ")!" << std::endl;
                            opponent->getShips()[i]->takeHit();
                            break;
                        }
                    }
                }
            }
            opponent->getGrid().markHit(row, col);
            break;
        }
    }
}