// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------
// Cruiser Size = 3
class Cruiser : public Ship
{
public:
  Cruiser() : Ship("Cruiser", 3) {}
  ~Cruiser(){}
};
