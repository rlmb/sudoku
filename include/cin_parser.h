#pragma once

#include "sudoku.h"

class CinParser
{

public:
    /**
     * @brief Parse the standard input to fill a sudoku grid
     *
     * @param reference of the sudoku object
     */
    static void parse(Sudoku& sudoku);

private:
    /**
     * @brief Parse the standard input to fill a sudoku grid
     *
     * @param reference of the sudoku object
     * @param row
     */
    static void parseLine(Sudoku& sudoku, size_t row);

};
