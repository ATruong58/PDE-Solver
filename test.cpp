#include <iostream>
#include <cmath>

#include "denseMatrix.h"
#include "symmetricMatrix.h"
#include "gaussian.h"
#include "pdeProblem.h"
#include "pdeSolver.h"
using namespace std;

void printhello(int a)
{
    std::cout << "Hello " << a << std::endl;
}



int main()
{
    pdeProblem<double,double> a(sin);
    pdeSolver<double,double> b;
    myvector<double> things = b(a,4);

    return 0;
}