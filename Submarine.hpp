// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------
// Submarine Size = 3
class Submarine : public Ship
{
public:
  Submarine() : Ship("Submarine", 3) {}
  ~Submarine(){}
};
