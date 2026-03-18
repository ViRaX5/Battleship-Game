// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------
// Destroyer Size = 2
class Destroyer : public Ship
{
public:
  Destroyer() : Ship("Destroyer", 2) {}
  ~Destroyer(){}
};
