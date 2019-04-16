#ifndef TRIDIAGONALMATRIX_H
#define TRIDIAGONALMATRIX_H

#include "matrix.h"

/*! tridiagonalMatrix class
 *
 * tridiagonalMatrix class with overloaded operator inhertit matrix class
 *
 */
template <class T>
class tridiagonalMatrix : public matrix<T>
{
    private:
        myvector<myvector<T>> m_matrix;
        int m_size;

    public:
        /*! Constructs an tridiagonalMatrix fill with zero of size 3.
         *
         * \pre T = 0 must be implemented
         * 
         * \post m_vector of myvector<T> with column size 3 and row size of 3 and decrease by 1 is created
         */
        tridiagonalMatrix();

        /*! Destructor
         *
         * \post Deallocate the class
         */
        ~tridiagonalMatrix(){}

        /*! Paramatized Constructor
         *
         * \pre T = 0 must be implemented
         * 
         * \post Creates a new matrix with passed in size
         *       with value all equal to 0
         */
        tridiagonalMatrix(const int size);

        /*! Copy Constructor
         *
         * \pre T = T must be implemented
         * 
         * \post Creates a new matrix with copies of elements from source
         *       and underlying storage size equal to that of source's storage.
         */
        tridiagonalMatrix(const tridiagonalMatrix &source);

        /*! Operator =
         *
         * \pre T = T must be define
         * 
         * \post Set lhs matrix with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        tridiagonalMatrix<T>& operator=(const tridiagonalMatrix &source);

        /*! Operator = (move constructor)
         *
         * \pre T = T must be define
         *      move must be define
         * 
         * \post Set lhs matrix with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        tridiagonalMatrix<T>& operator=(tridiagonalMatrix &&source);

        /*! Binary + bewtween two tridiagonalMatrix
         *
         * \param rhs tridiagonalMatrix class to add lhs tridiagonalMatrix class value to
         * \return A tridiagonalMatrix class with the sum of the two 
         *
         * \pre Rhs tridiagonalMatrix class and lhs tridiagonalMatrix class must have the same 
         *      row and column size and value assign to all index in the array 
         *      T + T must be defined
         *      T = T must be implemented
         *      Parametized constructor (int) must be implemented
         *      Paramter (int,int) must be implemented for tridiagonalMatrix to access data
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        tridiagonalMatrix<T> operator+(const tridiagonalMatrix<T> &rhs)const;

        /*! Binary - bewtween two tridiagonalMatrix
         *
         * \param rhs tridiagonalMatrix class to subtract lhs tridiagonalMatrix class value to
         * \return A tridiagonalMatrix class with the difference of the two 
         *
         * \pre Rhs tridiagonalMatrix class and lhs tridiagonalMatrix class must have the same 
         *      row and column size and value assign to all index in the array 
         *      T - T must be defined
         *      T = T must be implemented
         *      Parametized constructor (int) must be implemented
         *      Paramter (int,int) must be implemented for tridiagonalMatrix to access data
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        tridiagonalMatrix<T> operator-(const tridiagonalMatrix<T> &rhs)const;

        /*! Binary * bewtween two tridiagonalMatrix
         *
         * \param rhs tridiagonalMatrix class to multiply lhs tridiagonalMatrix class value to
         * \return A tridiagonalMatrix class with the product of the two 
         *
         * \pre Rhs tridiagonalMatrix class and lhs tridiagonalMatrix class must have the same 
         *      row and column size and value assign to all index in the array 
         *      T + T must be defined
         *      T = T must be implemented
         *      Parametized constructor (int) must be implemented
         *      Paramter (int,int) must be implemented for tridiagonalMatrix to access data
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        tridiagonalMatrix<T> operator*(const tridiagonalMatrix<T> &rhs)const;

        /*! Binary * bewtween a tridiagonalMatrix and an lowerMatrix
         *
         * \param rhs lowerMatrix class to multiply lhs tridiagonalMatrix class value to
         * \return A dense class with the multiple of the two matrixies
         *
         * \pre Rhs lowerMatrix class size must be equal to lhs tridiagonalMatrix 
         *      row and column size and value assign to all index in the array 
         *      T * T must be defined
         *      T = T must be implemented
         *      vector dot product must be implmented
         *      Parametized constructor (int) must be implemented
         *      Paramter (int,int) must be implemented for lowerMatrix and tridiagonalMatrix to access data 
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        denseMatrix<T> operator*(const lowerMatrix<T> &rhs)const;

        /*! Scalar multiplication
         *
         * \param scale a number to muliply all element of the matrix by
         * \return A tridiagonalMatrix class with the all element in the matrix class multiply by the scale
         *
         * \pre Value assign to all index in the array 
         *      T = T must be implemented
         *      T * T must be implemented
         *      Parametized constructor (int) must be implemented
         * 
         * \throws std::invalid_argument is thrown if rhs size and lhs row size are not the same
         * 
         */
        tridiagonalMatrix<T> operator*(const int scale)const;

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

         /*! Return the correct element of the matrix.
         *
         * \param i constant index column to read
         * \param j constant index row to read
	 *
         * \return The element at position idx is returned with reference so it is changable
         *         Return 0 if i < j, since user is not changing the index does not need to throw error
         *
         * \pre idx is within the range [0, length()).
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         *         
         */
        T operator()(const int i,const int j)const;

        /*! Return the correct element of the matrix.
         *
         * \param i constant index column to read
	 * \param j constant index row to read
         * 
	 * \return The element at position idx is returned with reference so it is changable
         *
         * \pre idx is within the range [0, length()).
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         *         std::invalid_argument is thrown if i < j, since lowerTriangle must be zero at those index
         */
        T& operator()(const int i,const int j);

        /*! Return a myvector witht eh product of the vector and matrixes
         *
         * \param rhs the vector to me multiply by.
         * \return A vector that is the product of the matrixes and vector
         *
         * \pre idx is within the range [0, length()].
	 * 	T = T must be implemented
	 * 	T * T must be implemented
         *      lowerMatrix (int,int) must be overloaded to access data
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        myvector<T> operator*(const myvector<T> &rhs)const;

        /*! Transpose the calling matrix
         *
         * \return A lowerMatrix class with its value equal to the calling matrix transpose
         * 
         * \pre T = T must be implmented
         *      Parametized constructor (int) must be implemented for lowerMatrix
         *      lowerMatrix (int,int) must be overloaded to access data
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        lowerMatrix<T> transpose()const;

        /*! Getter for size
         *
         * \return m_size
         * 
         */
        int getSize()const;
};

/*! Stream insertion operator for upper Matrix class.
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
std::ostream& operator<<(std::ostream& os, const tridiagonalMatrix<U> &obj);


/*! Stream output operator for tridiagonalMatrix class.
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
std::istream& operator>>(std::istream& in, tridiagonalMatrix<U> &obj);

#include "tridiagonalMatrix.hpp"


#endif
