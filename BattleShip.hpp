// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------
// BattleShip Size = 4
class BattleShip : public Ship
{
public:
  BattleShip() : Ship("Battleship ", 4) {}
  ~BattleShip(){}
};
