#ifndef GAUSSSIAN_H
#define GAUSSIAN_H

#include "vector.h"
#include <cmath>


class Gaussian_solver
{
    public:
        template <typename T>
        myvector<T> operator()(const mymatrix<T>& set, const myvector<T>& b)const;

};

#include "gaussian.hpp"

#endif