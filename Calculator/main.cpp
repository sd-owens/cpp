/************************************************************************
** Program name: Matrix Determinant Caculator
** Author: Steven Owens
** Date: 9/29/2019
** Description:  Program to calculate the determinant of a matrix of size
** 2x2 or 3x3. Provides functionality for user to choose size of matrix
** and input integer data with error handling to prevent input of invalid
** data and safeguard againgst erroneous results.
************************************************************************/

#include <iostream>
#include <string>
#include <limits>
#include <regex>
#include "determinant.hpp"
#include "readMatrix.hpp"

using std::cin;

// function prototypes 
bool isValidInput(std::string input);
int calcSetup();
int** initMatrix(int matrixSize);
void delMatrix(int** matrix, int matrixSize);
void printMatrix(int** matrix, int matrixSize);
void showDeterminant(int** matrix, int matrixSize);

/* Provides regex input validiation by taking a string input parameter and
   returns a boolean value. Only allows positive ints 2 or 3. */

/* Regex string user input validation adapted from a post by Jan Goyvaerts on 
    20170707 from https://www.regular-expressions.info/numericranges.html
    and a post by Akshay Pai on (no date) from https://www.hackerearth.com/practice/
    notes/validating-user-input-in-c/ and finally syntax and snippets from a post
    by user "Galik" on 20150618 from https://stackoverflow.com/questions/30921932/understanding-c-regex-by-a-simple-example **/

bool isValidInput(std::string input) {
   
    std::regex r("^[2-3]$"); 
    std::smatch m;
    std::regex_search(input, m, r);

    return !m.empty();
}

/* Provides console interface for user input, takes no parameters and returns a
   fully qualified integer value for the size of the matrix. Additionaly, provides
   validation and error checking of user input before conversion to a integer and 
   returning it to the caller.*/
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
    getline(cin, input);

    while (!isValidInput(input)) {

        //clears potential error flag on cin from invalid input.
        std::cerr << "Must select option 2 or 3!\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(cin, input);
    }

    return std::stoi(input);
}

/*  Dynamically allocates memory on the heap for a 2D matrix.  Takes an single input
    parameter of an integer as the size of the matrix and returns a pointer to the 2D
    array on the heap (Pointer to an array of int pointers to arrays of integers) */

/*  Snippet by user Alex on 20150814 from https://www.learncpp.com/cpp-tutorial/ 
    6-14-pointers-to-pointers/ as linked from the module 1 coursework. */
int** initMatrix(int matrixSize) {

    int** matrix = new int*[matrixSize];  // array of matrixSize int pointers (rows)
    for (int i = 0; i < matrixSize; i++){
        matrix[i] = new int[matrixSize];  // arrays of length matrixSize (columns)
    }
    return matrix;
}

/*  Deallocates memory dynamically assigned on the heap for the 2D matrix.  Take two
    parameters, the pointer to array of int pointers to arrays of integers and the 
    size of the matrix for the for loop.  Re-assigns the pointer to nullptr. */

/*  Snippet by user Alex on 20150814 from https://www.learncpp.com/cpp-tutorial/ 
    6-14-pointers-to-pointers/ as linked from the module 1 coursework. */
void delMatrix(int** matrix, int matrixSize) {

    for (int i = 0; i < matrixSize; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

/*  Prints 2D matrix to console for user feedback that input matches expected.  
    Takes two parameters, the pointer to array of int pointers to arrays 
    of integers and the size of the matrix for the for loop.  Additionally used 
    for debugging during development */
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

/*  Provides feedback to user that input matches expected and calls the function
    to calculate the determinant.  Provides user feedback on calculated value.  
    Takes two parameters, the pointer to array of int pointers to arrays 
    of integers and the size of the matrix for the for loop. Return type is void */
void showDeterminant(int** matrix, int matrixSize){

    std::cout << "\nYou entered the matrix:\n";

    printMatrix(matrix, matrixSize);

    std::cout << "\nThe determinant was calculated to be: ";

    std::cout << determinant(matrix, matrixSize) << std::endl;
    std::cout << "\n\n"<< std::endl;
}

/*  Main function for program, takes no parameters and returns a 0 if execution is
    successful otherwise early termination results in other integers values. Provides
    overall program setup and flow control including deallocation of dynamic memory */
int main() {

    int matrixSize = calcSetup();

    int** matrixPtr = initMatrix(matrixSize);

    readMatrix(matrixPtr, matrixSize);

    showDeterminant(matrixPtr, matrixSize);

    delMatrix(matrixPtr, matrixSize);

    return 0;
}