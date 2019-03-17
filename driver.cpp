#include "matrix.h"

int main()
{
    mymatrix<double> hi(3,3);
    mymatrix<double> x;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            hi[i][j] = j+1;
        }
    }

    mymatrix<double> what(3,4);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            what[i][j] = j+3;
        }
    }

    std::cout << hi;
    std::cout << what;
    std::cout << hi * what;

    return 0;
}