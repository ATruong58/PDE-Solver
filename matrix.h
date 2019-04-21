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

        /*! Pure Virtual operator+
         *
         * \param rhs matrix to add 
         * 
         * \return a denseMatrix of the matrix class
         * 
         */
        virtual denseMatrix<T> operator+(const matrix &rhs)const = 0;

        /*! Pure Virtual operator-
         *
         * \param rhs matrix to subtract
         * 
         * \return  a denseMatrix of the matrix class
         * 
         */
        virtual denseMatrix<T> operator-(const matrix &rhs)const = 0;

        /*! Pure Virtual operator*
         *
         * \param rhs matrix to multiply
         * 
         * \return a denseMatrix of the matrix class
         * 
         */
        virtual denseMatrix<T> operator*(const matrix &rhs)const = 0;

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

        /*! Pure Virtual operator() with reference
         *
         * \param index index to return from object 
         * 
         * \return a vector of the matrix class with reference so user can change value
         * 
         */
        virtual T& operator()(int i, int j) = 0;

        /*! Pure Virtual operator()
         *
         * \param index index to return from object 
         * 
         * \return  a vector of the matrix class
         * 
         */
        virtual T operator()(int i, int j)const = 0;

        /*! Pure Virtual getSize
         * 
         * \return a vector of the product of the myvector and matraxies
         * 
         */
        virtual int getSize() const = 0;       

};

#endif
