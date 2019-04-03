#ifndef UPPERMATRIX_H
#define UPPERMATRIX_H

#include "matrix.h"

template <class T>
class upperMatrix : public mymatrix
{
    upperMatrix();

    ~upperMatrix(){}

    upperMatrix(const int size);
    
    upperMatrix(const upperMatrix &source);

    upperMatrix<T>& operator=(const upperMatrix &source);

    upperMatrix<T>& operator=(upperMatrix &&source);

    mymatrix<T> operator+(const mymatrix<T> &source)const;


};



#endif