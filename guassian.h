#ifndef GUASSSIAN_H
#define GUASSIAN_H

#include "vector.h"

class Guassian_solver
{
    public:
        template <typename T>
        myvector<T> operator()(const myvector<myvector<T>>& set)const;

};

#include "guassian.hpp"

#endif