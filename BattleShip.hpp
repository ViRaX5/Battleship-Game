
#pragma once

#include "Ship.hpp"

class BattleShip : public Ship
{
public:
  BattleShip() : Ship("Battleship ", 4) {}
  ~BattleShip(){}
};
