#include <iostream>
#include <string>
#include "determinant.hpp"
#include "readMatrix.hpp"

using std::cin;



int setup() {

    std::string input{};

    std::cout << "Choose a matrix size: (Select 1 or 2)\n"
                 "(1) 2 x 2\n"
                 "(2) 3 x 3\n";

    // while there is input and user has not only pressed enter!
    while (getline(cin, input) && !input.empty()) {

        if (input == "1" || input == "2") {
            break;
        } else {
            std::cin.clear();  //clears potential error flag on cin from invalid input.
            std::cin.ignore(20, '\n'); //skips up to 20 characters up to the next newline character.
            std::cerr << "Must select option 1 or 2!\n";
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

    for(int y = 0; y < (inputSize); y++) {

        for(int x = 0; x < inputSize; x++){

            std::cout << matrix[y][x];
        }
         std::cout << "\n";
    }
    std::cout << std::endl;
}

int main() {

    int matrixSize = setup();

    int** matrixPtr = initMatrix(matrixSize);

    readMatrix(matrixPtr, matrixSize);

    printMatrix(matrixPtr, matrixSize);

    std::cout << determinant(matrixPtr, matrixSize) << std::endl;

    return 0;
}