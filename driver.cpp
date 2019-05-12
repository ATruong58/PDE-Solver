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

template <typename T> 
T realAnswer(T x, T y)
{
    return (1/sinh(M_PI) * ((sin(x) * sinh(M_PI-y)) + ((sin(y) * sinh(M_PI-x)))));
}

int main(int argc, char * argv[])
{
    try
    {
        if(argc == 3)
        {
            Gaussian_solver GS;
            Cholesky_solver CS;
            auto ret0 = [](double num){num++; return 0.0;};
            pdeProblem<double,double,double,double,double,double,double,double,double> a(sin, ret0, sin, ret0, M_PI);
            pdeSolver b;
            myvector<double> solution;
            double norm = 0;
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


            myvector<double> exactAnswer(solution.getSize());
            int counter = 0;

            double h = M_PI/n;
            //std::cout << solution << std::endl;

            for(int i = 0; i < n-1 ; i++)
            {
                for(int j = 0; j < n-1; j++)
                {
                    exactAnswer[counter] = realAnswer((j+1)* M_PI/n , (i+1) * M_PI/n);
                    counter++;
                }
            }

            for(int i = 0; i < solution.getSize(); i++)
            {
                norm += pow(solution[i] - exactAnswer[i],2); 
            }


            norm = sqrt(pow(h,2) * norm);

            std::cout << "Time take to use " << argv[2] << " to run N size of " << n << " : " << duration.count() * .000001 << " seconds\n";
            std::cout << "The percent error using norm is: "<< norm * 100 << "% "<<std::endl;

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
