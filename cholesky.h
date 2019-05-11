#ifndef CHOLESKY_H
#define CHOLESKY_H

#include "vector.h"
#include <cmath>

class Cholesky_solver
{
  public:
   /*! operator () Cholesky Algorithm for symmetricMatrix
    *
    * \param &set symmetricMatrix class to use Cholesky Algorithm to
    * \param b myvector class to augment the matrix with     
    *     
    * *\return A myvector class with the solution to the augmented matrix 
    *
    * \pre Rhs myvector class and lhs myvector class must have the same size
    *      and value assign to all index in the array 
    *      symmetricMatrix [] operator must be implmented
    *      = must be implemented for symmetricMatrix
    *      Scalar multiplication must be define for symmetricMatrix class
    *      myvector [] operator must be implmented
    *      symmetricMatrix overloaded () must be defined
    *      getSize must be defined for symmetricMatrix
    *      = must be implemented for myvector
    *      fabs() must be define
    *      myvector getmax() function must be define
    *      T / T must be define
    *      T * T must be define
    *      Parametized constructor (int) must be implemented for symmetricMatrix class
    *      Parametized (int,int) must be implemented to access data
    *      
    * 
    */
    template<typename T>
    myvector<T> operator()(const symmetricMatrix<T>& set, const myvector<T>& b)const;

};

#include "cholesky.hpp"

#endif