#ifndef PDEPROBLEM_H
#define PDEPROBLEM_H

/*! pdeProblem class
 *
 * preProblem class to hold a function
 *
 */
template <class T, class U>
class pdeProblem
{
    private: 
        U (*func) (T);

    public:
         /*! Paramatized Constructor
         *
         * 
         * \post Create a function pointer with the value of the function
         */
        pdeProblem(U (*function)(T));

         /*! Destructor
         *
         * \post Deallocate the class
         */
        ~pdeProblem(){}

        /*! operator ()
         *
         * \param T number to pass in to the function
         * 
         * \pre T = T must be implemented
         * 
         * \post Value of the function after passing in T 
         */
        U operator()(const T& num);
};

#include "pdeProblem.hpp"

#endif