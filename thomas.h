#ifndef THOMAS_H
#define THOMAS_H

#include "vector.h"
#include <cmath>

class Thomas_solver
{
  public:
   /*! operator () Thomas Algorithm for tridiagonalMatrix
    *
    * \param &set tridiagonalMatrix class to use Thomas Algorithm to
    * \param b myvector class to augment the matrix with     
    *     
    * *\return A myvector class with the solution to the augmented matrix 
    *
    * \pre Rhs myvector class and lhs myvector class must have the same size
    *      and value assign to all index in the array 
    *      tridiagonalMatrix [] operator must be implmented
    *      = must be implemented for tridiagonalMatrix
    *      Scalar multiplication must be define for tridiagonalMatrix class
    *      myvector [] operator must be implmented
    *      tridiagonalMatrix overloaded () must be defined
    *      getSize must be defined for tridiagonalMatrix
    *      = must be implemented for myvector
    *      fabs() must be define
    *      myvector getmax() function must be define
    *      T / T must be define
    *      T * T must be define
    *      Parametized constructor (int) must be implemented for tridiagonalMatrix class
    *      Parametized (int,int) must be implemented to access data
    *      
    * 
    */
    template<typename T>
    myvector<T> operator()(const tridiagonalMatrix<T>& set, const myvector<T>& b)const;

};

#include "thomas.hpp"

#endif