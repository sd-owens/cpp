/************************************************************************
** Program name: Matrix Determinant Caculator
** Author: Steven Owens
** Date: 9/29/2019
** Description:  Program to calculate the determinant of a matrix of size
** 2x2 or 3x3. Provides functionality for user to choose size of matrix
** and input integer data with error handling to prevent input of invalid
** data and safeguard againgst erroneous results.  This program should be
** compiled with the command "make" from the command line which produces
** an executable named "mcalc.bin". Run with the command ./mcalc.bin
************************************************************************/

#ifndef DETERMINANT_HPP
#define DETERMINANT_HPP

/* Calculates the deterimant of the 2D matrix using the Laplace expansion method.
   Takes two input parameters, the pointer to array of int pointers to arrays of 
   integers and the size of the matrix for the for loop. Returns the calculated
   result as an integer to the calling function. */
int determinant(int** matrix, int matrixSize);

#endif //DETERMINANT_HPP
