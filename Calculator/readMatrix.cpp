//
// Created by Steve Owens on 9/25/19.
//
#include <iostream>
#include <string>
#include <regex>
#include "readMatrix.hpp"

using std::cin;

bool isValid(std::string input) {
   
    std::regex r("^\\d+$"); 
    std::smatch m;
    std::regex_search(input, m, r);

    return !m.empty();
}

int validateInput(std::string input){

    while(!isValid(input)){

        //clears potential error flag on cin from invalid input.
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cerr << "Must enter an integer!\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(cin, input);

    }

    return std::stoi(input);
}

void readMatrix(int** matrix,  int matrixSize){

    std::string num = std::to_string(matrixSize);

    std::cout << "\nMatrix size " + num + " x " + num + " has been chosen.\n"
                 "Enter the values by row and column as indicated.\n\n";

    std::string input{};
    int number {};

    // prompt users for all numbers within given size matrix
    for(int row = 0; row < matrixSize; row++) {

        for(int col = 0; col < matrixSize; col++){

            std::cout << "Enter row " + std::to_string(row + 1) + ", column " + std::to_string(col + 1) + ": ";

            getline(cin, input);

            number = validateInput(input);

            matrix[row][col] = number;
        }
    }   
}