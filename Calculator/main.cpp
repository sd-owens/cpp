#include <iostream>
#include <string>
#include "determinant.hpp"
#include "readMatrix.hpp"

using std::cin;

int setupCalculator() {

    std::cout << "\n*************************************************\n";
    std::cout << "*****************Matrix Calculator***************\n";
    std::cout << "*************************************************\n\n";
    std::cout << "This program calculates the determinant of a user\n"
                 "defined matrix of either size 2 x 2 or 3 x 3.\n\n";

    std::cout << "Choose a matrix size:\t(2) 2 x 2 matrix\n" 
                 "(select 2 or 3)\t\t(3) 3 x 3 matrix\n\n";
    
    std::cout << "Choice: ";
    std::string input{};

    // while there is input and user has not only pressed enter!
    while (getline(cin, input) && !input.empty()) {

        if (input == "2" || input == "3") {
            break;
        } else {
            //clears potential error flag on cin from invalid input.
            //skips up to 20 characters up to the next newline character.
            std::cin.ignore(20, '\n');
            std::cin.clear();
            std::cerr << "Must select option 2 or 3!\n";
        }
    }
    return std::stoi(input);
}

int** initMatrix(int inputSize) {

    int** array = new int*[inputSize];  // array of inputSize int pointers (rows)
    for (int i = 0; i < inputSize; i++){
        array[i] = new int[inputSize];  // arrays of length inputSize (columns)
    }
    return array;
}

void killMatrix(int** matrix, int inputSize) {

    for (int i = 0; i < inputSize; i++) {
        delete[] matrix[inputSize];
    }
    delete[] matrix;
    matrix = nullptr;
}

// helper function to print 2D matrix to console for debugging.
void printMatrix(int**matrix, int inputSize) {

    std::cout << "\n";

    for(int y = 0; y < (inputSize); y++) {

        std::cout << "{ ";

        for(int x = 0; x < inputSize; x++){

            std::cout << std::to_string(matrix[y][x]) + " ";
        }
         std::cout << "}\n";
    }
    std::cout << std::endl;
}

int main() {

    int matrixSize = setupCalculator();

    int** matrixPtr = initMatrix(matrixSize);

    readMatrix(matrixPtr, matrixSize);

    std::cout << "\nYou entered the matrix:\n";

    printMatrix(matrixPtr, matrixSize);

    std::cout << "\nThe determinant was calculated to be: ";

    std::cout << determinant(matrixPtr, matrixSize) << std::endl;
    std::cout << "\n\n"<< std::endl;

    return 0;
}