#ifndef PDEPROBLEM_H
#define PDEPROBLEM_H

/*! pdeProblem struct
 *
 * preProblem struct to hold a function
 *
 */
template <class T, class U, class V, class W,class A, class B, class C, class D, class E>
struct pdeProblem
{
    U (*lower) (T);
    W (*upper) (V);
    B (*left)  (A);
    D (*right) (C);
    E upperBound;

     /*! Paramatized Constructor
     *
     * 
     * \post Create a function pointer with the value of the function
     */
    pdeProblem(U (*down)(T), W (*up)(V), B (*leftF)(A), D (*rightF)(C), E upBound);
     /*! Destructor
     *
     * \post Deallocate the class
     */
    ~pdeProblem(){}
};

#include "pdeProblem.hpp"

#endif