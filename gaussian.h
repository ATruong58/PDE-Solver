#ifndef GAUSSIAN_H
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

        /*! operator () Guassian Elimnation for denseMatrix
         *
         * \param &set denseMatrix class to use gussian elimnation to
         * \param b   myvector class to augment the matrix with     
         *     
         * *\return A myvector class with the solution to the augmented matrix 
         *
         * \pre Rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         *      denseMatrix [] operator must be implmented
         *      = must be implemented for denseMatrix
         *      Scalar multiplication must be define for denseMatrix class
         *      myvector [] operator must be implmented
         *      getColumnSize must be defined for denseMatrix
         *      getRowSize must be defined for denseMatrix
         *      = must be implemented for myvector
         *      fabs() must be define
         *      myvector getmax() function must be define
         *      T / T must be define
         *      Parametized constructor (int,int) must be implemented for denseMatrix class
         *      
         * 
         */
        template <typename T>
        myvector<T> operator()(const denseMatrix<T>& set, const myvector<T>& b)const;

        /*! operator () Guassian Elimnation for upperMatrix
         *
         * \param &set upperMatrix class to use gussian elimnation to
         * \param b   myvector class to augment the matrix with     
         *     
         * *\return A myvector class with the solution to the augmented matrix 
         *
         * \pre Rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         *      upperMatrix [] operator must be implmented
         *      = must be implemented for upperMatrix
         *      Scalar multiplication must be define for upperMatrix class
         *      myvector [] operator must be implmented
         *      upperMatrix overloaded () must be defined
         *      getSize must be defined for upperMatrix
         *      = must be implemented for myvector
         *      fabs() must be define
         *      myvector getmax() function must be define
         *      T / T must be define
         *      Parametized constructor (int) must be implemented for upperMatrix class
         *      
         * 
         */
        template <typename T>
        myvector<T> operator()(const upperMatrix<T>& set, const myvector<T>& b)const;

        /*! operator () Guassian Elimnation for lowerMatrix
         *
         * \param &set lowerMatrix class to use gussian elimnation to
         * \param b   myvector class to augment the matrix with     
         *     
         * *\return A myvector class with the solution to the augmented matrix 
         *
         * \pre Rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         *      lowerMatrix [] operator must be implmented
         *      = must be implemented for lowerMatrix
         *      Scalar multiplication must be define for lowerMatrix class
         *      myvector [] operator must be implmented
         *      lowerMatrix overloaded () must be defined
         *      getSize must be defined for lowerMatrix
         *      = must be implemented for myvector
         *      fabs() must be define
         *      myvector getmax() function must be define
         *      T / T must be define
         *      Parametized constructor (int) must be implemented for lowerMatrix class
         *      
         * 
         */
        template <typename T>
        myvector<T> operator()(const lowerMatrix<T>& set, const myvector<T>& b)const;

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
        template <typename T>
        myvector<T> operator()(const tridiagonalMatrix<T>& set, const myvector<T>& b)const;

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
        template <typename T>
        myvector<T> operator()(const symmetricMatrix<T>& set, const myvector<T>& b)const;

        


};

#include "gaussian.hpp"

#endif