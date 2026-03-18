
#pragma once

#include "Player.hpp"

class AiPlayer : public Player
{
public:
    AiPlayer(const char* name);
    ~AiPlayer(){}
    virtual int getRowToPlaceShip();
    virtual int getColToPlaceShip();
    virtual bool getOrientationToPlaceShip();
    int getRandomCoordinate();
    void virtual makeMove(Player* opponent);
};
