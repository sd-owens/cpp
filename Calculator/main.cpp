#include <iostream>
#include <string>
#include "determinant.hpp"
#include "readMatrix.hpp"

using std::cin;

int calcSetup() {

    std::cout << "\n*************************************************\n";
    std::cout << "**************** Matrix Calculator **************\n";
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

int** initMatrix(int matrixSize) {

    int** matrix = new int*[matrixSize];  // array of matrixSize int pointers (rows)
    for (int i = 0; i < matrixSize; i++){
        matrix[i] = new int[matrixSize];  // arrays of length matrixSize (columns)
    }
    return matrix;
}

void delMatrix(int** matrix, int matrixSize) {

    for (int i = 0; i < matrixSize; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

// helper function to print 2D matrix to console for debugging.
void printMatrix(int** matrix, int matrixSize) {

    std::cout << "\n";

    for(int y = 0; y < (matrixSize); y++) {

        std::cout << "{ ";

        for(int x = 0; x < matrixSize; x++){

            std::cout << std::to_string(matrix[y][x]) + " ";
        }
         std::cout << "}\n";
    }
    std::cout << std::endl;
}

void showDeterminant(int** matrix, int matrixSize){

    std::cout << "\nYou entered the matrix:\n";

    printMatrix(matrix, matrixSize);

    std::cout << "\nThe determinant was calculated to be: ";

    std::cout << determinant(matrix, matrixSize) << std::endl;
    std::cout << "\n\n"<< std::endl;
}

int main() {

    int matrixSize = calcSetup();

    int** matrixPtr = initMatrix(matrixSize);

    readMatrix(matrixPtr, matrixSize);

    showDeterminant(matrixPtr, matrixSize);

    delMatrix(matrixPtr, matrixSize);

    return 0;
}