//
// Created by Steve Owens on 9/25/19.
//
#include <iostream>
#include "readMatrix.hpp"

void readMatrix(int** matrix,  int matrixSize){

    int number {};

    // prompt users for all numbers within given size matrix

    // iterate through 2 nested for loops to populate the matrix with user input.
    for(int y = 0; y < matrixSize; y++) {

        for(int x = 0; x < matrixSize; x++){

            std::cout << "Enter row " + std::to_string(y + 1) + ", column " + std::to_string(x + 1) + ": ";

            std::cin >> number;
            matrix[y][x] = number;
        }
         
    }


    // use a flattened array

    
}