#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

template <class T>
class mymatrix
{
    private:
        myvector<myvector<T>> m_matrix;
        int m_column_size;
        int m_row_size;
    
    public:
        mymatrix();
        ~mymatrix(){}
        mymatrix(const int column_size, const int row_size);
        mymatrix(const mymatrix &source);
        
        mymatrix<T>& operator=(const mymatrix<T> &source);
        mymatrix<T>& operator=(mymatrix<T> &&source);
        
        mymatrix<T> operator+(const mymatrix<T> &source)const;
        mymatrix<T> operator-(const mymatrix<T> &source)const;
        mymatrix<T> operator*(const mymatrix<T> &source)const;
        mymatrix<T> operator*(const int scale)const;

        myvector<T> operator*(const myvector<T> &rhs)const;
        myvector<T> operator[](int index)const;
        myvector<T>& operator[](int index);
        
        mymatrix<T> transpose()const;
        int getColumnSize()const;
        int getRowSize()const;








};

template <typename U>
std::ostream& operator<<(std::ostream& os, const mymatrix<U> &obj);

template <typename U>
std::istream& operator>>(std::istream& in, mymatrix<U> &obj);

#include "matrix.hpp"


#endif 