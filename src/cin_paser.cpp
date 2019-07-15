#include <iostream>
#include <vector>
#include <stdexcept>
#include "cin_parser.h"

void CinParser::parse(Sudoku& sudoku)
{
    for (size_t i=0; i<9; i++) {
        CinParser::parseLine(sudoku, i);
    }
}

void CinParser::parseLine(Sudoku& sudoku, size_t row)
{
    std::string input;
    std::cin >> input;
 
    // Parse standard input   
    std::vector<int> values;
    std::string value_str;
    for (size_t i=0; i<input.size(); i++) {
        if (input[i] == ',') {
            values.push_back(std::atoi(value_str.c_str()));
            value_str = "";
        } else {
            value_str += input[i];
        }
    }
    if (value_str.size()) {
        values.push_back(std::atoi(value_str.c_str()));
    }
    
    if (values.size() != 9) {
        throw std::invalid_argument("expected 9 places for input " + input);
    }

    // Fill the sudoku
    for (size_t i=0; i<values.size(); i++) {
        sudoku.setValue(row, i, values[i]);
    }
}
