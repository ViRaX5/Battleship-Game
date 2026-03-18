// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267
// -------------------------------------------
#pragma once
// -------------------------------------------
// Grid Size: 10 X 10
#define  GRID_X_AXIS_MAX 10
#define  GRID_Y_AXIS_MAX 10
//
#define VALID_GRID_INPUT(row, col) ((row >= 0) && (row < GRID_X_AXIS_MAX) && (col >= 0) && (col < GRID_Y_AXIS_MAX))

// -------------------------------------------
#include <iostream>
#include <exception>
#include <stdexcept>
#include <iomanip>
// -------------------------------------------
// S = Ship
// X = Hit
// M = Miss
// horizontal = 1(Up/Down) : 0(Left/Right) ;

class Grid
{
private:
  char cells[GRID_X_AXIS_MAX][GRID_Y_AXIS_MAX];
  
public:
/* -----------------------------------------------------------------------------------------
 * Function: Grid::Grid
 * Purpose : Initialize the 10x10 grid cells to '~' (empty water).
 * Input   : none
 * Output  : none
 * Notes   : Called automatically when a Grid is created.
 * ----------------------------------------------------------------------------------------- */
  Grid();

  ~Grid() {}

/* -----------------------------------------------------------------------------------------
 * Function: Grid::isTileOccupied
 * Purpose : Check if a cell already contains a ship or a previous hit.
 * Input   : row,col (0..9)
 * Output  : true if occupied, false otherwise
 * Notes   : Used to prevent overlapping ships.
 * ----------------------------------------------------------------------------------------- */
  inline bool isTileOccupied(int row, int col) const{return VALID_GRID_INPUT(row,col)? (cells[row][col] != '~') : false ;}

/* -----------------------------------------------------------------------------------------
 * Function: Grid::inBounds
 * Purpose : Validate that a ship placement fits inside the grid.
 * Input   : row,col (0..9), shipSize (>0), horizontal (true=H, false=V)
 * Output  : true if placement fits, false otherwise
 * Notes   : Does not check overlap, only boundaries.
 * ----------------------------------------------------------------------------------------- */
  bool inBounds(int row,int col,int shipSize,bool horizontal)const;

/* -----------------------------------------------------------------------------------------
 * Function: Grid::placeShip
 * Purpose : Place a ship symbol across consecutive cells (if placement already validated).
 * Input   : row,col, shipSize, horizontal, symbol (usually 'S')
 * Output  : none
 * Notes   : Caller should ensure inBounds + not occupied before calling.
 * ----------------------------------------------------------------------------------------- */
  void placeShip(int row,int col,int shipSize, bool horizontal, char symbol);

/* -----------------------------------------------------------------------------------------
 * Function: Grid::markHit
 * Purpose : Mark a successful hit at (row,col) with 'X'.
 * Input   : row,col (0..9)
 * Output  : none
 * Notes   : Caller should prevent double-shot before calling.
 * ----------------------------------------------------------------------------------------- */
  void markHit(int row, int col);

/* -----------------------------------------------------------------------------------------
 * Function: Grid::markMiss
 * Purpose : Mark a miss at (row,col) with 'M'.
 * Input   : row,col (0..9)
 * Output  : none
 * Notes   : Caller should prevent double-shot before calling.
 * ----------------------------------------------------------------------------------------- */
  void markMiss(int row, int col);

/* -----------------------------------------------------------------------------------------
 * Function: Grid::getCell
 * Purpose : Return the cell character at (row,col).
 * Input   : row,col (0..9)
 * Output  : char representing '~','S','X','M'
 * Notes   : Used to decide hit vs miss.
 * ----------------------------------------------------------------------------------------- */
  char getCell(int row,int col)const;

  // HELPER FUNCTIONS:
  void printGrid();
  
  void print(bool showAxes = true, bool hideShips = false) const;

  bool isInBounds(int row,int col) const;

  bool isAlreadyShot(int row, int col) const;
};

