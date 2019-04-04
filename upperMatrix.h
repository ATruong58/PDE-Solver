#ifndef UPPERMATRIX_H
#define UPPERMATRIX_H

#include "matrix.h"

/*! upperMatrix class
 *
 * upperMatrix class with overloaded operator inhertit matrix class
 *
 */
template <class T>
class upperMatrix : public matrix<T>
{
    private:
        myvector<myvector<T>> m_matrix;
        int m_size;

    public:
        upperMatrix();

        ~upperMatrix(){}

        upperMatrix(const int size);

        upperMatrix(const upperMatrix &source);

        upperMatrix<T>& operator=(const upperMatrix &source);

        upperMatrix<T>& operator=(upperMatrix &&source);

        upperMatrix<T> operator+(const upperMatrix<T> &rhs)const;

        upperMatrix<T> operator-(const upperMatrix<T> &rhs)const;

        upperMatrix<T> operator*(const upperMatrix<T> &rhs)const;

        upperMatrix<T> operator*(const int scale)const;

        T& operator()(int i, int j);

        T operator()(int i, int j)const;

        myvector<T> operator*(const myvector<T> &rhs)const;
};

#include "upperMatrix.hpp"


#endif