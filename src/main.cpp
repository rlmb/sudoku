#include <iostream>
#include "sudoku.h"
#include "cin_parser.h"

int main()
{   
    Sudoku sudoku;
    
    // Parse standard input and fill the sudoku
    try {
        CinParser::parse(sudoku);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 1;
    }
    
    // Check if input was correct
    if (!sudoku.isCorrect()) {
        std::cout << "Input for this sudoku is not correct." << std::endl;
        return 1;
    }
    
    sudoku.print();
    std::cout << "Solving..." << std::endl;
    
    // Solve it
    if (sudoku.solve()) {
        std::cout << "Solved" << std::endl;
        sudoku.print();
        return 0;
    } else {
        std::cout << "Could not solve the sudoku" << std::endl;
        return 1;
    }
    
}
