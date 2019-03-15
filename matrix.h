#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

template <class T>
class mymatrix
{
    private:
        myvector<myvector<T>> m_matrix;
        int m_size;
    
    public:
        mymatrix();
        ~mymatrix();
        mymatrix(const int size);
        mymatrix(const mymatrix &source);
        mymatrix operator+(const myvector<T> &source)const;
        mymatrix operator-(const myvector<T> &source)const;
        mymatrix operator*(const myvector<T> &source)const;
        mymatrix operator*(const int scale);








};

#include "matrix.hpp"


#endif 