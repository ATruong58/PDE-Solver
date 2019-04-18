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
    denseMatrix<double> matrix1;

    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[0][2] = 3;
    matrix1[1][0] = 4;
    matrix1[1][1] = 5;
    matrix1[1][2] = 6;
    matrix1[2][0] = 7;
    matrix1[2][1] = 8;
    matrix1[2][2] = 9;

    symmetricMatrix<double> matrix2;

    matrix2(0,0) = 1;
    matrix2(1,0) = 2;
    matrix2(1,1) = 3;
    matrix2(1,2) = 4;
    matrix2(2,0) = 5;
    matrix2(2,1) = 6;
    matrix2(2,2) = 7;

    cout<< matrix1 << matrix2;
    cout << matrix1 * matrix2;

    return 0;
}
