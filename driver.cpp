#include <iostream>
#include <cmath>
#include "denseMatrix.h"
#include "upperMatrix.h"
#include "lowerMatrix.h"
#include "symmetricMatrix.h"
#include "gaussian.h"

#include "cholesky.h"
#include "pdeProblem.h"
#include "pdeSolver.h"
#include <cstring>
using namespace std::chrono;


int main(int argc, char * argv[])
{
    try
    {
        if(argc == 3)
        {
            Gaussian_solver GS;
            Cholesky_solver CS;
            pdeProblem<double,double> a(sin);
            pdeSolver b;
            myvector<double> solution;
            int n = atoi(argv[1]);

            auto start = high_resolution_clock::now(); 
            if(strcmp(argv[2], "GS") == 0)
            {
                solution = b(a ,n, GS);
            }
            else if (strcmp( argv[2], "CS") == 0)
            {
                solution = b(a ,n, CS);
            }
            else
            {
                throw std::out_of_range( "Incorrect Value Type\n");
            }
            auto stop = high_resolution_clock::now(); 
            auto duration = duration_cast<microseconds>(stop - start); 

            std::cout << "Time take to use " << argv[2] << " to run N size of " << n << " : "
                  << duration.count() * .000001 << " seconds" << std::endl;

            std::cout << solution << std::endl;

            
        }
        else
        {
            throw std::out_of_range( "No N or method type is pass\n");
        }

    }
    catch (std::out_of_range e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
