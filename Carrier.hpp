// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#pragma once
// -------------------------------------------
#include "Ship.hpp"
// -------------------------------------------
// Carrier Size = 5
class Carrier :  public Ship
{ 
public:
  Carrier() : Ship("Carrier",5) {}
  ~Carrier(){}
};

