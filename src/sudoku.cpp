#include "sudoku.h"
#include <iostream>
#include <unordered_map>
#include <limits>
#include <algorithm>


Sudoku::Sudoku()
{
    // Add line constraints
    for (size_t line=0; line<9; line++) {
        auto constraint = std::make_shared<BlockConstraint>();
        constraints.push_back(constraint);
        for (size_t i=0; i<9; i++) {
            constraint->addPlace(grid[line][i]);
        }
    }
    
    // Add columns constraints
    for (size_t col=0; col<9; col++) {
        auto constraint = std::make_shared<BlockConstraint>();
        constraints.push_back(constraint);
        for (size_t i=0; i<9; i++) {
            constraint->addPlace(grid[i][col]);
        }
    }
    
    // Add square constraints
    for (size_t block_line=0; block_line<3; block_line++) {
        for (size_t block_col=0; block_col<3; block_col++) {
            auto constraint = std::make_shared<BlockConstraint>();
            constraints.push_back(constraint);
            constraint->addPlace(grid[block_line*3+0][block_col*3+0]);
            constraint->addPlace(grid[block_line*3+0][block_col*3+1]);
            constraint->addPlace(grid[block_line*3+0][block_col*3+2]);
            constraint->addPlace(grid[block_line*3+1][block_col*3+0]);
            constraint->addPlace(grid[block_line*3+1][block_col*3+1]);
            constraint->addPlace(grid[block_line*3+1][block_col*3+2]);
            constraint->addPlace(grid[block_line*3+2][block_col*3+0]);
            constraint->addPlace(grid[block_line*3+2][block_col*3+1]);
            constraint->addPlace(grid[block_line*3+2][block_col*3+2]);
        }
    }    
}

void Sudoku::setValue(size_t row, size_t column, int newValue)
{
    grid[row][column].setValue(newValue);
}

int Sudoku::getValue(size_t row, size_t column)
{
    return grid[row][column].getValue();
}

void Sudoku::unsetValue(size_t row, size_t column)
{
    grid[row][column].unsetValue();
}

bool Sudoku::isDone()
{
    for (const auto& row: grid) {
        for (const auto& place: row) {
            if (!place.isSet()) {
                return false;
            }
        }
    }
    
    return true;
}

bool Sudoku::isCorrect()
{
    for (auto& constraint: constraints) {
        if (!constraint->isSatisfied()) {
            return false;
        }
    }
    
    return true;
}

bool Sudoku::solve()
{
    std::vector<Place*> history;

    while (!this->isDone()) {
        // Assign value to place with the minimum number of possibilities
        Place* place_to_update = nullptr;
        size_t min_possibilities = std::numeric_limits<std::size_t>::max();
        for (size_t line=0; line<9; line++) {
            for (size_t col=0; col<9; col++) {
                auto& place = grid[line][col];
                if (std::find(history.begin(), history.end(), &place) != history.end()) {
                    continue;
                }
                
                if (!place.isSet()) {
                    const auto& nb_possibilities = place.getPossibilities().size();
                    if (nb_possibilities < min_possibilities) {
                        place_to_update = &place;
                        min_possibilities = nb_possibilities;
                    }
                }
            }
        }
        
        if (place_to_update == nullptr) {
            // something went wrong, it should have stop before
            return false;
        }
        
        // Assign a new possible value
        history.push_back(place_to_update);
        while (!place_to_update->assignNextPossibility()) {
            if (history.size() == 0) {
                // tried everything but could not get any solution ...
                return false;
            }
            
            history.pop_back();
            place_to_update = history.back();
        }
    }
    
    return true;
}

void Sudoku::print()
{
    for (size_t line=0; line<9; line++) {
        for (size_t col=0; col<9; col++) {
            const auto& place = grid[line][col];
            if (place.isSet()) {
                std::cout << place.getValue();
            } else {
                std::cout << "x";
            }
            
            if (col < 8) {
                std::cout << ",";
            }
        }
        std::cout << std::endl;
    }
}
