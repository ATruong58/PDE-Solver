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
class matrix
{
    private: 
        myvector<myvector<T>> m_matrix;
        int m_column_size;
        int m_row_size;
    
    public:
        virtual myvector<T> operator*(const myvector<T> &rhs)const = 0;
        virtual denseMatrix<T>& operator=(const denseMatrix<T> &source) = 0;
        virtual denseMatrix<T>& operator=(denseMatrix<T> &&source) = 0;
        virtual denseMatrix<T> operator+(const denseMatrix<T> &source)const = 0;
        virtual denseMatrix<T> operator-(const denseMatrix<T> &source)const = 0;
        virtual denseMatrix<T> operator*(const denseMatrix<T> &source)const = 0;
        virtual denseMatrix<T> operator*(const int scale)const = 0;
        virtual myvector<T>& operator[](int index) = 0;
        virtual myvector<T> operator[](int index)const = 0;
        virtual denseMatrix<T> transpose()const = 0;

        /*! Getter for m_column_size
         *
         * \return m_column_size
         */
        int getColumnSize()const {return m_column_size;}

        /*! Getter for m_row_size
         *
         * \return m_row_size
         */
        int getRowSize()const {return m_row_size;}
        
        
        

};



#endif