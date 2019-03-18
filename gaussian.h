#ifndef GAUSSSIAN_H
#define GAUSSIAN_H

#include "vector.h"
#include <cmath>

/*! Gaussian solver class
 *
 * Guassian class with operator() overloaded to solve an augmented matrix with guassian elimnation
 *
 */
class Gaussian_solver
{
    public:

        /* operator () Guassian Elimnation 
         *
         * \param &set mymatrix class to use gussian elimnation to
         *        &b   myvector class to augment the matrix with     
         *     
         * *\return A myvector class with the solution to the augmented matrix 
         *
         * \pre Rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         *      mymatrix [] operator must be implmented
         *      = must be implemented for mymatrix
         *      Scalar multiplication must be define for mymatrix class
         *      myvector [] operator must be implmented
         *      getColumnSize must be defined for mymatrix
         *      getRowSize must be defined for mymatrix
         *      = must be implemented for myvector
         *      fabs() must be define
         *      myvector getmax() function must be define
         *      T / T must be define
         *      Parametized constructor (int,int) must be implemented for mymatrix class
         *      
         * 
         */
        template <typename T>
        myvector<T> operator()(const mymatrix<T>& set, const myvector<T>& b)const;

};

#include "gaussian.hpp"

#endif