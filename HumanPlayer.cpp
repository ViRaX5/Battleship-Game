// Dor Mandel;      ID : 315313825
// Amit Lachmann;   ID : 207448267 
// -------------------------------------------
#include "HumanPlayer.hpp"
// -------------------------------------------
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
// -------------------------------------------

HumanPlayer::HumanPlayer(const char* name) : Player(name){}

int HumanPlayer::getRowToPlaceShip()
{
    std::cout << "Please choose a row (0-9)" << std::endl;
    std::string str;
    int row = -1;
    while (!(row >= 0 && row <= 9))
    {
        std::cin >> str;
        try
        {
            row = std::stoi(str);
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << "Invalid input, try again" << std::endl;
            continue;
        }
        catch(const std::out_of_range& e)
        {
            std::cout << "Invalid row number, try again" << std::endl;
            continue;
        }
        if (!(row >= 0 && row <= 9))
        {
            std::cout << "Invalid row number, try again" << std::endl;
        }  
    }
    return row;
}

int HumanPlayer::getColToPlaceShip()
{
    std::cout << "Please choose a column (0-9)" << std::endl;
    std::string str;
    int column = -1;
    while (!(column >= 0 && column <= 9))
    {
        std::cin >> str;
        try
        {
            column = std::stoi(str);
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << "Invalid input, try again" << std::endl;
            continue;
        }
        catch(const std::out_of_range& e)
        {
            std::cout << "Invalid column number, try again" << std::endl;
            continue;
        }
        if (!(column >= 0 && column <= 9))
        {
            std::cout << "Invalid column number, try again" << std::endl;
        }  
    }
    return column;
}

bool HumanPlayer::getOrientationToPlaceShip()
{
    while (true)
    {
        std::cout << "Please choose in what orientation you want the ship to be (horizontal/vertical/h/v)" << std::endl;
        std::string orientation;
        std::cin >> orientation;
        std::transform(orientation.begin(), orientation.end(), orientation.begin(), ::tolower);
        if (orientation == "horizontal" || orientation == "h")
        {
            return true;
        }
        else if (orientation == "vertical" || orientation == "v")
        {
            return false;
        }
        else
        {
            std::cout << "invalid input, write horizontal or vertical, try again." << std::endl;
        } 
    }
    return true;
}

void HumanPlayer::makeMove(Player* opponent)
{
    std::cout << "It is " << getName() << "'s turn!" << std::endl;
    while (true)
    {
        std::cout << opponent->getName() << "'s grid:" << std::endl;
        opponent->displayGrid();
        std::cout << "Make an attack! Where would you like to attack?" << std::endl;
        int row = getRowToPlaceShip();
        int col = getColToPlaceShip();
        if (opponent->getGrid().getCell(row, col) == '~')
        {
            opponent->getGrid().markMiss(row, col);
            break;
        }
        else if (opponent->getGrid().getCell(row, col) == 'S')
        {
            for (int i = 0; i < NUM_OF_SHIPS; i++)
            {
                if (opponent->getShips()[i]->isHorizontal())
                {
                    if (row == opponent->getShips()[i]->getRow())
                    {
                        if (col >= opponent->getShips()[i]->getCol() && col < (opponent->getShips()[i]->getCol() + opponent->getShips()[i]->getSize()))
                        {
                            opponent->getShips()[i]->takeHit();
                            break;
                        }
                    }
                }
                else
                {
                    if (col == opponent->getShips()[i]->getCol())
                    {
                        if (row >= opponent->getShips()[i]->getRow() && row < (opponent->getShips()[i]->getRow() + opponent->getShips()[i]->getSize()))
                        {
                            opponent->getShips()[i]->takeHit();
                            break;
                        }
                    }
                }
            }
            opponent->getGrid().markHit(row, col);
            break;
        }
        else
        {
            std::cout << "You are trying to hit somewhere you have already shot at, try again." << std::endl;
        }
    }
}