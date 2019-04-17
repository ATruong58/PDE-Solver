/*!Name: Alan Truong                                 
 *Date: 3/10/2019                                   
 *Course: Object Orient Numerical Method            
 *Purpose: Learn how to use polymporphism and inheritance
            to make a lower, upper and full matrix class 
            and to implement the Guassian method       
 */    

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

template <class T>
class denseMatrix;

template <class T>
class upperMatrix;

template <class T>
class lowerMatrix;

template <class T>
class diagonalMatrix;

template <class T>
class symmetricMatrix;

template <class T>
class tridiagonalMatrix;

/*! matrix class
 *
 * abstract class for matrixies
 *
 */
template <class T>
class matrix
{
    public:
        /*! Pure Virtual Destructor
         *
         * \post Deallocate the class
         * 
         */
        virtual ~matrix(){}

        /*! Pure Virtual operator[]
         *
         * \param index index to return from object 
         * 
         * \return  a vector of the matrix class
         * 
         */
        virtual myvector<T> operator[](int index)const = 0;

        /*! Pure Virtual operator[] with reference
         *
         * \param index index to return from object 
         * 
         * \return a vector of the matrix class with reference so user can change value
         * 
         */
        virtual myvector<T>& operator[](int index) = 0;

        /*! Pure Virtual binaray * with a vector
         *
         * \param rhs myvector class to multiple matrixes by
         * 
         * \return a vector of the product of the myvector and matraxies
         * 
         */
        virtual myvector<T> operator*(const myvector<T> &rhs)const = 0;       

};

#endif
