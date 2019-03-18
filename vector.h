/*!Name: Alan Truong                                 
 *Date: 3/10/2019                                   
 *Course: Object Orient Numerical Method            
 *Purpose: Learn how to use OOP to make a matrix class
           and to implement the Guassian method       
 */                                                   


#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>


/*! myvector class
 *
 * myvector class with overloaded operator
 *
 */
template <class T>
class myvector
{
    private:
	std::unique_ptr<T[]> m_array;
        int m_size;
        
        
    
    public:
        /*! Constructs an empty myvector.
         *
         * \post m_array created with size of 1
         */
        myvector();

        /*! Destructor
         *
         * \post Deallocate the class
         */
        ~myvector(){}

        /*! Paramatized Constructor
         *
         * \pre T = 0 must be implemented
         * 
         * \post Creates a new vector with passed in number of element
         *       with value all equal to 0
         */
        myvector(const int size);

        /*! Copy Constructor
         *
         * \pre T = T must be implemented
         * 
         * \post Creates a new vector with copies of elements from source
         *       and underlying storage size equal to that of source's storage.
         */
        myvector(const myvector &source);

        /*! Unary - 
         *
         * \pre T = T must be implemented
         * 
         * \pre *= Must be defined for the calling obj
         *      T = T must be implemented
         *      T *-1 must be assign
         * 
         * \return a vector with lhs value multiple by -1  
         */
        myvector<T> operator-()const;

        /*! Binary - 
         *
         * \param source  myvector class to subtract lhs myvector class value to
         * \return A myvector class with the difference of the two 
         *
         * \pre Rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         *      T - T must be defined
         *      T = T must be implemented
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        myvector<T> operator-(const myvector<T> &source)const;

        /*! Binary + 
         *
         * \param &source myvector class to add with lhs myvector class value to
         * \return A myvector class with the sum of the two 
         *
         * \pre Rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         *      T + T must be defined
         *      T = T must be implemented
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        myvector<T> operator+(const myvector<T> &source)const;

        /*! Binary *
         *
         * \param rhs number to multiply with all valye in lhs myvector class value
         * \return A myvector class with the all value multiply with rhs
         *
         * \pre Lhs myvector class must have a reference [] operator define
         *      T * T must be defined
         *      T = T must be implemented
         * 
         */
        myvector<T> operator*(const T rhs)const;

        /*! Reads an element of the vector.
         *
         * \param index the index of the element to read.
         * \return The element at position idx is returned.
         *
         * \pre idx is within the range [0, length()).
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        T operator[](int index)const;

        /*! Return the element of the vector.
         *
         * \param index the index of the element to read.
         * \return The element at position idx is returned with reference so it is changable
         *
         * \pre idx is within the range [0, length()).
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        T& operator[](int index);

         /*! Return the max element of the vector.
         *
         * \pre T > T must be define
         *      T = T must be define
         * 
         * \return The biggest elemenet in the vector
         *
         */
        T getmax()const;

        /*! Dot product 
         * \param source myvector to dot product with lhs.
         * \return a double with the value of the dot product
         *
         * \pre Rhs myvector class and lhs myvector class must have the same size
         *      and value assign to all index in the array 
         *      Must have += define
         *      T = T must be implemented
         * \throws std::invalid_argument is thrown if size is not the same
         */
        double operator*(const myvector<T> &source)const;

	/*! Operator =
         *
         * \pre T = T must be define
         * 
         * \post Set lhs vector with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        myvector<T>&  operator=(const myvector<T> &source);

        /*! Operator = (move constructor)
         *
         * \pre T = T must be define
         *      move must be define
         * 
         * \post Set lhs vector with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        myvector<T>&  operator=(myvector<T> &&source);


        /*! Getter for m_size
         *
         * \return m_size
         */
        int getSize()const;
};

        /*! Stream insertion operator for myvector class.
         *
         * \pre Stream insertion operator is defined.
         * \post The contents of the vector are printed to the ouptut stream.
         * \return the modified output stream.
         *
         */
        template <typename U>
        std::ostream& operator<<(std::ostream& os, const myvector<U> &obj);


        /*! Stream output operator for myvector class.
         *
         * \pre Stream outpit operator is defined.
         * \post The contents of the vector are read into the given variable
         * \return the modified input stream.
         *
         */
        template <typename U>
        std::istream& operator>>(std::istream& in, myvector<U> &obj);

         /*! Guass_sidel method
         *
         * \param matrix a vector class of myvector
         * \pre Stream output operator is defined.
         *      Abs() must be define
         *      -Subtraction must be define
         *      +Addition Must be define
         *      *Multiplication Must be define
         *      vector passed in must be of type myvector
         *      myvector class must be defined
         * \post output of linear depenence will be prinited. 1 if linear dependent
         *       0 if linear independent. If linear depended will out put the x that leades
         *       for the matrix to be linear dependent
         * 
         *
         */
        template <typename U>
        void guass_Sidel(const std::vector<U>& matrix);

#include "vector.hpp"

#endif 
