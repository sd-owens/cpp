//
// Created by Steve Owens on 9/25/19.
//
#include "determinant.hpp"

int determinant(int** matrix, int matrixSize) {

    if (matrixSize == 2) {

        return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    }

        int A {};
        int B {};
        int C {};

        A = (matrix[0][0] * (matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));
        B = (matrix[1][0] * (matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
        C = (matrix[2][0] * (matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][2]));

        return (A - B + C);
}

    // calculate the deterimant of the 2darray matrix and return as an int

    // [a][b]     "using Laplace expansion"
    // [c][d]     determinant is (a*d) - (c*b) 


    // [a][b][c]  "using Laplace expansion"
    // [d][e][f]
    // [g][h][i]  determinant is = a(ei-fh) - b(di-fg) + c(dh-eg)

