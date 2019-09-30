/************************************************************************
** Program name: Matrix Determinant Caculator
** Author: Steven Owens
** Date: 9/29/2019
** Description:  Program to calculate the determinant of a matrix of size
** 2x2 or 3x3. Provides functionality for user to choose size of matrix
** and input integer data with error handling to prevent input of invalid
** data and safeguard againgst erroneous results.
************************************************************************/

#ifndef READMATRIX_HPP
#define READMATRIX_HPP

/* Provides regex input validiation by taking a string input parameter and
   returns a boolean value. */
bool isValid(std::string input);

/* Validates and provides error handling for user input as a string and returns
   a fully qualified integer value back to the calling function. Prompts user
   for input following validiation failure. */
int validateInput(std::string input);

/* Takes user data as integers for given size matrix, takes a pointer to a 2D
   array of integers and an integer for the size of the matrix as input params.
   This function has a return type of void. */
void readMatrix(int** matrix,  int matrixSize);

#endif //READMATRIX_HPP
