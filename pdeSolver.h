#ifndef PDESOLVER_H
#define PDESOLVER_H

/*! pdeProblem class
 *
 * preProblem class to solve a pdeProblem
 *
 */
template <class T, class U>
class pdeSolver
{
    public:
        /*! operator () to solve pdeProblem
         *
         * \param &P pdeProblem class with the function we are solving 
         * \param n number that we want to section the matrix for accurate answer    
         *     
         * *\return A myvector class with the solution to the problem 
         *
         * \pre Rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         *      symmetricMatrix [] operator must be implmented
         *      = must be implemented for symmetricMatrix
         *      Scalar multiplication must be define for symmetricMatrix class
         *      myvector [] operator must be implmented
         *      getSize must be defined for symmetricMatrix
         *      getRowSize must be defined for symmetricMatrix
         *      = must be implemented for myvector
         *      fabs() must be define
         *      denseMatrix class must be define
         *      Guassian Solver for symmetricMatrix and denseMatrix must be define
         *      T / T must be define
         *      T + T must be define
         *      T * T must be define
         *      Parametized constructor (int,int) must be implemented for symmetricMatrix class
         * 
         */
        myvector<T> operator()(pdeProblem<T,U> &P, int n);
};

#include "pdeSolver.hpp"

#endif