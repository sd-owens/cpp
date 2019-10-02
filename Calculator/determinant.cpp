/************************************************************************
** Program name: Matrix Determinant Caculator
** Author: Steven Owens
** Date: 9/29/2019
** Description:  Program to calculate the determinant of a matrix of size
** 2x2 or 3x3. Provides functionality for user to choose size of matrix
** and input integer data with error handling to prevent input of invalid
** data and safeguard againgst erroneous results.  This program should be
** compiled with the command "make" from the command line which produces
** an executable named "mcalc". Run with the command ./mcalc
************************************************************************/

#include "determinant.hpp"

/* Calculates the deterimant of the 2D matrix using the Laplace expansion method.
   Takes two input parameters, the pointer to array of int pointers to arrays of 
   integers and the size of the matrix for the for loop. Returns the calculated
   result as an integer to the calling function. */
int determinant(int** matrix, int matrixSize) {

    // matrixSize can only be 2 or 3 following validation.
    if (matrixSize == 2) {
                                // [a][b]     "using Laplace expansion"
                                // [c][d]     determinant is (a*d) - (c*b) 

        return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    }

        int A {};               // [a][b][c]  "using Laplace expansion"
        int B {};               // [d][e][f]
        int C {};               // [g][h][i]  determinant is = a(ei-fh) - b(di-fg) + c(dh-eg)

        A = (matrix[0][0] * (matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));
        B = (matrix[1][0] * (matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
        C = (matrix[2][0] * (matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][2]));

        return (A - B + C);
}


    


    
    
    

