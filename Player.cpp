// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267
// -------------------------------------------
#include "Player.hpp"
#include <string.h>
// -------------------------------------------

Player::Player(const char *name)
{
    // **************************************
    // Safety check for null pointer
    if (name)
    {
        playerName = new char[strlen(name) + 1];
        strcpy(playerName, name);
    }
    else
    {
        playerName = new char[8];
        strcpy(playerName, "Unknown");
    }
    // **************************************
    
    BattleShip *b = new BattleShip();
    Carrier *ca = new Carrier();
    Cruiser *cr = new Cruiser();
    Destroyer *d = new Destroyer();
    Submarine *s = new Submarine();
    ships[0] = b;
    ships[1] = ca;
    ships[2] = cr;
    ships[3] = d;
    ships[4] = s;
}

Player::~Player()
{
    delete[] playerName;
    for (int i = 0; i < NUM_OF_SHIPS; i++)
    {
        // delete ships[i];
        if (ships[i])
        {
            delete ships[i];
            ships[i] = nullptr; // 
        }
    }
}

void Player::placeAllShips()
{
    int i = 0;
    while (i < NUM_OF_SHIPS)
    {
        std::cout << "Please place the ship: " << ships[i]->getName() << std::endl;
        int row = getRowToPlaceShip();
        int col = getColToPlaceShip();
        bool orientation = getOrientationToPlaceShip();
        if (!grid.inBounds(row, col, ships[i]->getSize(), orientation))
        {
            std::cout << "Can't place ship there, out of bounds, try again" << std::endl;
            continue;
        }
        bool overlap = false;
        for (int k = 0; k < ships[i]->getSize(); k++)
        {
            int r = row + (orientation ? 0 : k);
            int c = col + (orientation ? k : 0);
            if (grid.isTileOccupied(r, c))
            {
                overlap = true;
                break;
            }
        }
        if (overlap)
        {
            std::cout << "Can't place ship, it will overlap with other ships!" << std::endl;
            continue;
        }
        grid.placeShip(row, col, ships[i]->getSize(), orientation, 'S');
        ships[i]->setCoord(row, col, orientation);
        i++;
    }
}

bool Player::allShipsSunk() const
{
    for (int i = 0; i < NUM_OF_SHIPS; i++)
    {
        if (!ships[i]->isSunk())
        {
            return false;
        }
    }
    return true;
}

void Player::displayGrid() { grid.print(true, true); }
