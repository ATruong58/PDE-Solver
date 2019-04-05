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
class matrix
{
    public:
        virtual ~matrix(){}
        virtual myvector<T> operator[](int index)const = 0;
        virtual myvector<T>& operator[](int index) = 0;
        virtual myvector<T> operator*(const myvector<T> &rhs)const = 0;       

};

#endif