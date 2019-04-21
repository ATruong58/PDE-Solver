#include "denseMatrix.h"
#include "upperMatrix.h"
#include "lowerMatrix.h"
#include "tridiagonalMatrix.h"
#include "diagonalMatrix.h"
#include "symmetricMatrix.h"
#include "gaussian.h"
#include <fstream>

using namespace std; 

int main()
{
    tridiagonalMatrix<double> matrix1;

    // matrix1(0,0) = 1;
    // matrix1(0,1) = 2;
    // matrix1(1,0) = 3;
    // matrix1(1,1) = 4;
    // matrix1(1,2) = 5;
    // matrix1(2,1) = 6;
    // matrix1(2,2) = 7;


    denseMatrix<double> matrix2;

    // matrix2(0,0) = 7;
    // matrix2(0,1) = 8;
    // matrix2(0,2) = 6;
    // matrix2(1,1) = 7;
    // matrix2(1,2) = 0;
    // matrix2(2,2) = 7;

    // matrix2(0,0) = 6;
    // matrix2(1,0) = 7;
    // matrix2(1,1) = 8;
    // matrix2(2,0) = 9;
    // matrix2(2,1) = 1;
    // matrix2(2,2) = 2;

    matrix2[0][0] = 1;
    matrix2[0][1] = 2;
    matrix2[0][2] = 0;
    matrix2[1][0] = 3;
    matrix2[1][1] = 4;
    matrix2[1][2] = 5;
    matrix2[2][0] = 0;
    matrix2[2][1] = 6;
    matrix2[2][2] = 7;

    // matrix2(0,0) = 7;
    // matrix2(0,1) = 2;
    // matrix2(1,0) = 9;
    // matrix2(1,1) = 5;
    // matrix2(1,2) = 3;
    // matrix2(2,1) = 4;
    // matrix2(2,2) = 8;
    
    // matrix2(0,0) = 5;
    // matrix2(1,1) = 4;
    // matrix2(2,2) = 3;

    matrix1 = matrix2.isTridiagonal();
    cout << matrix2 << endl;

    return 0;
}
