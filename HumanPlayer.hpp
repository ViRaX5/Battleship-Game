// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Player.hpp"
// -------------------------------------------

class HumanPlayer : public Player
{    
public:
    HumanPlayer(const char* name);
    ~HumanPlayer(){}
    virtual void makeMove(Player* opponent);
    virtual int getRowToPlaceShip();
    virtual int getColToPlaceShip();
    virtual bool getOrientationToPlaceShip();
};

