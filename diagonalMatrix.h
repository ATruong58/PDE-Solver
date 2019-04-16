#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "matrix.h"

/*! diagonalMatrix class
 *
 * diagonalMatrix class with overloaded operator inhertit matrix class
 *
 */
template <class T>
class diagonalMatrix : public matrix<T>
{
    private:
        myvector<T> m_matrix;
        int m_size;

    public:
        /*! Constructs an diagonalMatrix fill with zero of size 3.
         *
         * \pre T = 0 must be implemented
         * 
         * \post m_vector of myvector<T> with column size 3 and row size of 3 and decrease by 1 is created
         */
        diagonalMatrix();

        /*! Destructor
         *
         * \post Deallocate the class
         */
        ~diagonalMatrix(){}

        /*! Paramatized Constructor
         *
         * \pre T = 0 must be implemented
         * 
         * \post Creates a new matrix with passed in size
         *       with value all equal to 0
         */
        diagonalMatrix(const int size);

        /*! Copy Constructor
         *
         * \pre T = T must be implemented
         * 
         * \post Creates a new matrix with copies of elements from source
         *       and underlying storage size equal to that of source's storage.
         */
        diagonalMatrix(const diagonalMatrix &source);

        /*! Operator =
         *
         * \pre T = T must be define
         * 
         * \post Set lhs matrix with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        diagonalMatrix<T>& operator=(const diagonalMatrix &source);

        /*! Operator = (move constructor)
         *
         * \pre T = T must be define
         *      move must be define
         * 
         * \post Set lhs matrix with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        diagonalMatrix<T>& operator=(diagonalMatrix &&source);

        /*! Binary + bewtween two diagonalMatrix
         *
         * \param rhs diagonalMatrix class to add lhs diagonalMatrix class value to
         * \return A diagonalMatrix class with the sum of the two 
         *
         * \pre Rhs diagonalMatrix class and lhs diagonalMatrix class must have the same 
         *      row and column size and value assign to all index in the array 
         *      T + T must be defined
         *      T = T must be implemented
         *      Parametized constructor (int) must be implemented
         *      Paramter (int,int) must be implemented for diagonalMatrix to access data
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        diagonalMatrix<T> operator+(const diagonalMatrix<T> &rhs)const;

        /*! Binary - bewtween two diagonalMatrix
         *
         * \param rhs diagonalMatrix class to subtract lhs diagonalMatrix class value to
         * \return A diagonalMatrix class with the difference of the two 
         *
         * \pre Rhs diagonalMatrix class and lhs diagonalMatrix class must have the same 
         *      row and column size and value assign to all index in the array 
         *      T - T must be defined
         *      T = T must be implemented
         *      Parametized constructor (int) must be implemented
         *      Paramter (int,int) must be implemented for diagonalMatrix to access data
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        diagonalMatrix<T> operator-(const diagonalMatrix<T> &rhs)const;

        /*! Binary * bewtween two diagonalMatrix
         *
         * \param rhs diagonalMatrix class to multiply lhs diagonalMatrix class value to
         * \return A diagonalMatrix class with the product of the two 
         *
         * \pre Rhs diagonalMatrix class and lhs diagonalMatrix class must have the same 
         *      row and column size and value assign to all index in the array 
         *      T + T must be defined
         *      T = T must be implemented
         *      Parametized constructor (int) must be implemented
         *      Paramter (int,int) must be implemented for diagonalMatrix to access data
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        diagonalMatrix<T> operator*(const diagonalMatrix<T> &rhs)const;

        /*! Binary * bewtween a diagonalMatrix and an lowerMatrix
         *
         * \param rhs lowerMatrix class to multiply lhs diagonalMatrix class value to
         * \return A dense class with the multiple of the two matrixies
         *
         * \pre Rhs lowerMatrix class size must be equal to lhs diagonalMatrix 
         *      row and column size and value assign to all index in the array 
         *      T * T must be defined
         *      T = T must be implemented
         *      vector dot product must be implmented
         *      Parametized constructor (int) must be implemented
         *      Paramter (int,int) must be implemented for lowerMatrix and diagonalMatrix to access data 
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        denseMatrix<T> operator*(const lowerMatrix<T> &rhs)const;

        /*! Scalar multiplication
         *
         * \param scale a number to muliply all element of the matrix by
         * \return A diagonalMatrix class with the all element in the matrix class multiply by the scale
         *
         * \pre Value assign to all index in the array 
         *      T = T must be implemented
         *      T * T must be implemented
         *      Parametized constructor (int) must be implemented
         * 
         * \throws std::invalid_argument is thrown if rhs size and lhs row size are not the same
         * 
         */
        diagonalMatrix<T> operator*(const int scale)const;

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
std::ostream& operator<<(std::ostream& os, const diagonalMatrix<U> &obj);


/*! Stream output operator for diagonalMatrix class.
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
std::istream& operator>>(std::istream& in, diagonalMatrix<U> &obj);

#include "diagonalMatrix.hpp"


#endif
