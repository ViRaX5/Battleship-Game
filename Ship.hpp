// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#pragma once
// -------------------------------------------
#include <iostream>
#include <string.h>
// -------------------------------------------
using std::string;
// -------------------------------------------

class Ship
{
private:
  char* name;  
  int size;
  int hitsTaken;
  int row;
  int column;
  bool horizontal;

public:
  /* -----------------------------------------------------------------------------------------
 * Function: Ship::Ship
 * Purpose : Creates a ship with a given size and tracking state (hits).
 * Input   : size (>0)
 * Output  : none
 * Notes   : Initializes hit counter (or hit array) to zero.
 * ----------------------------------------------------------------------------------------- */
  Ship(const char *shipName, int shipSize): size(shipSize) ,hitsTaken(0) {name = new char[strlen(shipName) + 1]; strcpy(name, shipName);}

  virtual ~Ship() {delete[] name;}

  /* -----------------------------------------------------------------------------------------
 * Function: Ship::takeHit
 * Purpose : Registers a successful hit on this ship.
 * Input   : none (or hit index if you store per-part hits)
 * Output  : none
 * Notes   : Should not exceed ship size; used to detect when ship becomes sunk.
 * ----------------------------------------------------------------------------------------- */
  virtual void takeHit();

  /* -----------------------------------------------------------------------------------------
 * Function: Ship::isSunk
 * Purpose : Checks whether the ship is fully destroyed.
 * Input   : none
 * Output  : true if sunk, false otherwise
 * Notes   : True when hitCount == size (or all parts hit).
 * ----------------------------------------------------------------------------------------- */
  inline bool isSunk() const {return  hitsTaken >= size;}

  /* -----------------------------------------------------------------------------------------
 * Function: Ship::getSize
 * Purpose : Returns ship length (number of cells).
 * Input   : none
 * Output  : ship size
 * Notes   : Used for placement validation and UI messages.
 * ----------------------------------------------------------------------------------------- */
  inline int getSize() {return size;}

  /* -----------------------------------------------------------------------------------------
 * Function: <CLASS>::setCoord
 * Purpose : Sets the ship's starting coordinate (row, col) and orientation (horizontal/vertical).
 * Input   : row (int) [0..9], col (int) [0..9], hor (bool) true=horizontal, false=vertical
 * Output  : none
 * Notes   : Assumes the caller already validated that the coordinate + ship size fit the grid
 *           and that the placement does not overlap other ships.
 * ----------------------------------------------------------------------------------------- */
  inline void setCoord(int r, int c, bool hor) {row = r; column = c; horizontal = hor;}

  /* -----------------------------------------------------------------------------------------
 * Function: <CLASS>::getRow
 * Purpose : Returns the starting row of this object (ship placement coordinate).
 * Input   : none
 * Output  : int row (expected range 0..9)
 * Notes   : Does not validate bounds; should reflect previously set/valid coordinates.
 * ----------------------------------------------------------------------------------------- */
  inline int getRow() {return row;}

  /* -----------------------------------------------------------------------------------------
 * Function: <CLASS>::getCol
 * Purpose : Returns the starting column of this object (ship placement coordinate).
 * Input   : none
 * Output  : int column (expected range 0..9)
 * Notes   : Does not validate bounds; should reflect previously set/valid coordinates.
 * ----------------------------------------------------------------------------------------- */
  inline int getCol() {return column;}

  //inline void setHorizontal(bool hor) {horizontal = hor;}
  /* -----------------------------------------------------------------------------------------
 * Function: <CLASS>::isHorizontal
 * Purpose : Returns whether the object is placed horizontally.
 * Input   : none
 * Output  : bool true if horizontal, false if vertical
 * Notes   : Orientation is typically set via setCoord(...).
 * ----------------------------------------------------------------------------------------- */
  inline bool isHorizontal() {return horizontal;}

/* -----------------------------------------------------------------------------------------
 * Function: Ship::getName
 * Purpose : Returns a readable name for printing/UI.
 * Input   : none
 * Output  : ship name string/const char*
 * Notes   : Optional but useful for “You sunk my ...”.
 * ----------------------------------------------------------------------------------------- */
  inline char* getName() {return name;}
};

/*
Carrier (size = 5)
Battleship (size = 4)
Cruiser (size = 3)
Submarine (size = 3)
Destroyer (size = 2)
*/


