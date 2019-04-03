#include "denseMatrix.h"
#include "matrix.h"
#include "gaussian.h"
#include <fstream>

int main(int argc,  char * argv[])
{
    Gaussian_solver GS;
    int loop;
    try
    {
        if(argc > 1)
        {
            std::ifstream fs(argv[1]);
            if (!(fs.is_open() && fs.good()))
            {
                throw std::out_of_range( "File not read correctly\n");
            }
            fs >> loop;
            denseMatrix<double> matrix(loop,loop); 
            myvector<double> b_vector(loop);
            
            for(int i = 0; i < loop; i++)
            {
		        fs >> matrix[i];
	        }


            fs >> b_vector;

            myvector<double> x;

            std::cout << "A * A^T:\n";
            std::cout <<  matrix * matrix.transpose() << std::endl << std::endl << std::endl;
            
            std::cout << "x:\n";
            x = GS(matrix, b_vector);

            for(int i = 0; i < x.getSize(); i++)
            {
                std::cout << x[i] << "\n";
            }

            myvector<double> A_x;

            A_x =  matrix * x;

            std::cout << "\n\n\nA * x:\n";
            for(int i = 0; i < x.getSize(); i++)
            {
                std::cout << A_x[i] << "\n";
            }

            

        }
        else
        {
            throw std::out_of_range( "No dataset is passed.\n");
        }
    }
    catch (std::out_of_range e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
