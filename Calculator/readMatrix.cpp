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
#include <regex>
#include "readMatrix.hpp"

using std::cin;

/*  Provides user input validation by taking a string input parameter and
    returns a boolean value. Handles neg numbers "strings" by checking for and
    removing '-' char prior to validation, only allows this special char in the
    first char position.  Iterates through string and checks if all char are digits,
    if not it sets the isValidInput flag to false and breaks the loop since a single
    failed check means the input is invalid */

bool isValid(std::string input) {
   
    bool validInput = true;

    std::string cleanInput{};

    if(input.at(0) == '-'){ 
        cleanInput = input.erase(0,1);
    }

    for(unsigned int i = 0; i < cleanInput.length(); i++){

       if(!std::isdigit(cleanInput.at(i)) && validInput){
               
               validInput = false;
               break;
        }
    }

    return validInput;
}

/*  Validates and provides error handling for user input as a string and returns
    a fully qualified integer value back to the calling function. Prompts user
    for input following validiation failure. */

/*  cin methods fail, ignore, and cerr adapted from a post by user "int main" on
    20080715 from http://www.cplusplus.com/forum/beginner/2957/ Elected to not use
    cin.fail() and use string input for validation */
int validateInput(std::string input){

    while(!isValid(input)){

        //clears potential error flag on cin from invalid input.
        std::cerr << "Must enter an integer!\n";
        std::cin.clear();
        input = "";  // re-initializes input to empty string ""

        getline(cin, input);

    }

    return std::stoi(input);
}

/* Takes user data as integers for given size matrix, takes a pointer to a 2D
   array of integers and an integer for the size of the matrix as input params.
   This function has a return type of void. */
void readMatrix(int** matrix,  int matrixSize){

    std::string num = std::to_string(matrixSize);

    std::cout << "\nMatrix size " + num + " x " + num + " has been chosen.\n"
                 "Enter the values by row and column as indicated.\n\n";

    std::string input{};

    int number {};

    for(int row = 0; row < matrixSize; row++) {

        for(int col = 0; col < matrixSize; col++){

            std::cout << "Enter row " + std::to_string(row + 1) + ", column " + std::to_string(col + 1) + ": ";

            getline(cin, input);

            number = validateInput(input);

            matrix[row][col] = number;
        }
    }   
}