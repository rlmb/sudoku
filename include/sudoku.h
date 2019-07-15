#pragma once

#include <array>
#include <vector>
#include <memory>
#include "place.h"
#include "block_constraint.h"

class Sudoku
{

private:
    std::array<std::array<Place, 9>, 9> grid;
    std::vector<std::shared_ptr<BlockConstraint>> constraints;

public:
    /**
     * @brief Constructor
     */
    Sudoku();

    /**
     * @brief Set value for an element in the grid
     *
     * @param row
     * @param column
     * @param newValue
     */
    void setValue(size_t row, size_t column, int newValue);
    /**
     * @brief Get value for an element in the grid
     *
     * @param row
     * @param column
     *
     * @return value
     */
    int getValue(size_t row, size_t column);
    /**
     * @brief Unset value for an element in the grid
     *
     * @param row
     * @param column
     */
    void unsetValue(size_t row, size_t column);

    /**
     * @brief Check if the sudoku is finished
     *
     * @return true if finished otherwise false
     */
    bool isDone();
    /**
     * @brief Check if the sudoku is still correct
     *
     * @return true if still correct otherwise false
     */
    bool isCorrect();
    
    /**
     * @brief Solve the sudoku
     *
     * @return true if a solution was found otherwise false
     */
    bool solve();

    /**
     * @brief Print the sudoku in the standard output
     */
    void print();
};
