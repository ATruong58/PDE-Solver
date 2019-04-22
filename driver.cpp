#include "denseMatrix.h"
#include "upperMatrix.h"
#include "lowerMatrix.h"
#include "diagonalMatrix.h"
#include "tridiagonalMatrix.h"
#include "symmetricMatrix.h"
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
            denseMatrix<double> matrix(loop); 
            myvector<double> b_vector(loop);
            bool sameTranspose = false;
            myvector<double> x;
            
            for(int i = 0; i < loop; i++)
            {
		        fs >> matrix[i];
	        }

            fs >> b_vector;

            if(matrix.isUpper())
            {
                denseMatrix<double> temp(matrix);
                upperMatrix<double> matrix = temp.toUpper();

                std::cout << matrix.transpose();
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
            else if(matrix.isLower())
            {
                denseMatrix<double> temp(matrix);
                lowerMatrix<double> matrix = temp.toLower();

                std::cout << matrix.transpose();
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
            else if(matrix.isTridiagonal())
            {
                denseMatrix<double> temp(matrix);
                tridiagonalMatrix<double> matrix = temp.toTridiagonal();

                std::cout << matrix.transpose();
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
            else if(matrix.isDiagonal())
            {
                denseMatrix<double> temp(matrix);
                diagonalMatrix<double> matrix = temp.toDiagonal();
                sameTranspose = true;

                std::cout << "A * A^T:\n";

                std::cout <<  matrix * matrix << std::endl << std::endl << std::endl;
    
                std::cout << "x:\n";
                x = b_vector;
    
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
            else if(matrix.isSymmetric())
            {
                denseMatrix<double> temp(matrix);
                symmetricMatrix<double> matrix = temp.toSymmetric();
                sameTranspose = true;
                
                std::cout << "A * A^T:\n";

                std::cout <<  matrix * matrix << std::endl << std::endl << std::endl;

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

                std::cout << "A * A^T:\n";

                std::cout <<  matrix * matrix << std::endl << std::endl << std::endl;

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
