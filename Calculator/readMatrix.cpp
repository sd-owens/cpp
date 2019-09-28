//
// Created by Steve Owens on 9/25/19.
//
#include <iostream>
#include "readMatrix.hpp"

void readMatrix(int** matrix,  int matrixSize){

    std::string num = std::to_string(matrixSize);

    std::cout << "\nMatrix size " + num + " x " + num + " has been chosen.\n"
                 "Enter the matrix values by row and column as indicated.\n\n";

    int number{};

    // prompt users for all numbers within given size matrix

    // iterate through 2 nested for loops to populate the matrix with user input.
    for(int row = 0; row < matrixSize; row++) {

        for(int col = 0; col < matrixSize; col++){

            std::cout << "Enter row " + std::to_string(row + 1) + ", column " + std::to_string(col + 1) + ": ";

            std::cin >> number;
            matrix[row][col] = number;
        }
         
    }


    // use a flattened array

    
}