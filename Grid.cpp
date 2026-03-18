// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#include "Grid.hpp"

//Added for GridPrint:
#include <iostream>
#include <iomanip>
// -------------------------------------------

Grid::Grid()
{
  for(int row = 0 ; row < GRID_X_AXIS_MAX ;row++)
  {
    for(int col = 0 ; col < GRID_Y_AXIS_MAX ;col++)
    {
      cells[row][col] = '~';
    }
  }
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
  using namespace std;
  if (!VALID_GRID_INPUT(row, col))
  {
    cout << "Invalid row/column" << endl;
    return false;
  }
  if (shipSize <= 0)
  {
    cout << "Invalid Ship Size!" << endl;
    return false;
  }

  else if (horizontal)
    return (col + shipSize - 1) < GRID_Y_AXIS_MAX;
  else
    return (row + shipSize - 1) < GRID_X_AXIS_MAX;
}

void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol = 'S')
{
  // checkUps:
  if (!inBounds(row, col, shipSize, horizontal) || (shipSize <= 0) || (symbol != 'S'))
  {
    std::cout << "Ship cannot Be Placed!" << std::endl;
    return;
  }
  if (horizontal)
  {
    for (int i = 0; i < shipSize; i++)
      cells[row][col + i] = symbol;
  }
  else
  {
    for (int i = 0; i < shipSize; i++)
      cells[row + i][col] = symbol;
  }
}

void Grid::markHit(int row, int col)
{
  using namespace std;
  if (!VALID_GRID_INPUT(row, col))
    cout << "MarkMiss out of Bounds! try again" << endl;
  if (cells[row][col] == 'X' || cells[row][col] == 'M')
    return;
  cells[row][col] = 'X';
}

void Grid::markMiss(int row, int col)
{
  using namespace std;
  if (!VALID_GRID_INPUT(row, col))
    cout << "MarkMiss out of Bounds! try again" << endl;
  if (cells[row][col] == 'X' || cells[row][col] == 'M')
    return;
  cells[row][col] = 'M';
}

char Grid::getCell(int row, int col) const
{
  return Grid::cells[row][col];
}

// Helper Funcs:
void Grid::printGrid()
{
  print(true,true); // show axes , hide ships. 
}

void Grid::print(bool showAxes, bool hideShips) const
{
  using namespace std;
  const int N = 10; // GRID_BoardSize

  // if showAxes available :
  // " " gives space so the numbers align above the columns.
  // Loop prints: 0 1 2 3 4 5 6 7 8 9
  // --- top axis ---
  if(showAxes)
  {
    cout<<"     ";
    for(int col = 0; col < N; ++col) {cout<<col<<" ";}
    cout<< "\n";
  }
  
  // Print the top border line (each cell is 2 -> N*2)
  cout<< "   +";
  for (int i = 0; i < N*2; ++i){cout << "-";}
  cout << "-+\n";  
  
  // Print each row: row number + cells
  for (int row = 0; row < N; ++row)
  {
    // setw(*) = prevents misalingments -> make sure there is a space ;
    if(showAxes) cout<<setw(2) <<row<< " | ";
    else cout<< "| ";

    for(int col = 0 ; col < N ; ++col)
    {
      char ch = cells[row][col];
      if(hideShips && ch =='S')
        ch ='~';
      cout<<ch<<" ";
    }
    cout<<"|\n";
  }
  //
  cout<<"   +";
  for (int i = 0; i < N * 2 + 1; ++i) {cout<<"-";}
  cout<<"+\n";
  
}

bool Grid::isInBounds(int row, int col) const
{
  return VALID_GRID_INPUT(row,col);
}

bool Grid::isAlreadyShot(int row, int col) const
{
  char ch = cells[row][col];
  return (ch == 'X' || ch == 'M');
}
