// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#include "Ship.hpp"
#include <iostream>
// -------------------------------------------

/*
increments hitsTaken and Prints "<shipname> got hit!"
*/
void Ship::takeHit()
{
  hitsTaken++;
  std::cout << "A ship was hit!" << std::endl;
  if (hitsTaken == size)
  {
    std::cout << name << " sunk!" << std::endl;
  }
  
}