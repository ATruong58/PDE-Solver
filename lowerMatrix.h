#ifndef LOWERMATRIX_H
#define LOWERMATRIX_H

#include "matrix.h"

/*! lowerMatrix class
 *
 * lowerMatrix class with overloaded operator inhertit matrix class
 *
 */
template <class T>
class lowerMatrix : public matrix<T>
{
    private:
        myvector<myvector<T>> m_matrix;
        int m_size;

    public:
        lowerMatrix();

        ~lowerMatrix(){}

        lowerMatrix(const int size);

        lowerMatrix(const lowerMatrix &source);

        lowerMatrix<T>& operator=(const lowerMatrix &source);

        lowerMatrix<T>& operator=(lowerMatrix &&source);

        lowerMatrix<T> operator+(const lowerMatrix<T> &rhs)const;

        lowerMatrix<T> operator-(const lowerMatrix<T> &rhs)const;

        lowerMatrix<T> operator*(const lowerMatrix<T> &rhs)const;

        lowerMatrix<T> operator*(const int scale)const;

        T& operator()(int i, int j);

        T operator()(int i, int j)const;

        myvector<T> operator*(const myvector<T> &rhs)const;
};

#include "lowerMatrix.hpp"


#endif