//
// Created by Steve Owens on 9/25/19.
//
#include "determinant.hpp"

// calculate the deterimant of the 2D array matrix and return as an integer.
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


    


    
    
    

