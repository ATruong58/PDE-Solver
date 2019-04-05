#ifndef UPPERMATRIX_H
#define UPPERMATRIX_H

#include "matrix.h"

template <class T>
class lowerMatrix;

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

        /*! Return a myvector class of T of the element
         *
         * \param index the index of the vector to return in the matrix class.
         * \return The element at position idx is returned.
         * 
         * \pre idx is within the range [0, length()).
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        myvector<T> operator[](int index)const;

        /*! Return a myvector class of T of the element 
         *
         * \param index the index of the vector to return in the matrix class.
         * \return The vector at position idx is returned with reference so it is changable
         *
         * \pre idx is within the range [0, length()).
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        myvector<T>& operator[](int index);

        T operator()(const int i,const int j)const;

        T& operator()(const int i,const int j);

        myvector<T> operator*(const myvector<T> &rhs)const;

        lowerMatrix<T> transpose()const;

        int getSize()const;
};

/*! Stream insertion operator for denseMatrix class.
         *
         * \pre Stream insertion operator is defined.
         *      myvector class insert must be defined
         * 
         * \post The contents of the matrix are printed to the ouptut stream.
         * 
         * \return the modified output stream.
         *
         */
template <typename U>
std::ostream& operator<<(std::ostream& os, const upperMatrix<U> &obj);


/*! Stream output operator for myvector class.
         *
         * \pre Stream output operator is defined.
         *      myvector output must be defined
         * 
         * \post The contents of the vector are read into the given variable
         * 
         * \return the modified input stream.
         *
         */
template <typename U>
std::istream& operator>>(std::istream& in, upperMatrix<U> &obj);

#include "upperMatrix.hpp"


#endif