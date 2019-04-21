//Default Constructor
template <typename T>
lowerMatrix<T>::lowerMatrix()
{
    m_matrix = myvector<myvector<T> >(3);

    for(int i = 0; i < 3; i++)
    {
        m_matrix[i] = myvector<T>(i+1); 
    }

    m_size = 3;
}

//Paramitized Constructor
template <typename T>
lowerMatrix<T>::lowerMatrix(const int size)
{
    m_matrix = myvector<myvector<T> >(size);

    for(int i = 0; i < size; i++)
    {
        m_matrix[i] = myvector<T>(i+1); 
    }

    m_size = size;
}

//Copy Constructor
template <typename T>
lowerMatrix<T>::lowerMatrix(const lowerMatrix &source)
{
    m_matrix = myvector<myvector<T> >(source.m_size);

    for(int i = 0; i < source.m_size; i++)
    {
        m_matrix[i] = source[i];
    }

    m_size = source.m_size;
}

//Operator = 
template <typename T>
lowerMatrix<T>& lowerMatrix<T>::operator=(const lowerMatrix<T> &source)
{
    m_matrix = myvector<myvector<T> >(source.m_size);

    for(int i = 0; i < source.m_size; i++)
    {
        m_matrix[i] = source[i];
    }

    m_size = source.m_size;


    return *this;

}

//Operator = (move constructor)
template <typename T>
lowerMatrix<T>& lowerMatrix<T>::operator=(lowerMatrix<T> &&source)
{
    m_matrix = myvector<myvector<T> >(source.m_size);

    m_matrix = std::move(source.m_matrix);

    m_size = source.m_size;

    return *this;

}

//Binary + between a lower matrix and a matrix class
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator+(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
        {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                temp[i][j] = duplicate(i,j) + rhs(i,j);
            }
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary - between a lower matrix and a matrix class
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator-(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
        {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                temp[i][j] = duplicate(i,j) - rhs(i,j);
            }
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary * between a lower matrix and a matrix class
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator*(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                for(int k = 0; k < m_size; k++)
                {
                    temp[i][j] = temp[i][j] + (duplicate(i,k) * rhs(k,j));
                }
            }
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary + between 2 matrixs
template <typename T>
lowerMatrix<T> lowerMatrix<T>::operator+(const lowerMatrix<T> &rhs)const
{
    lowerMatrix<T> temp(m_size);
    
    if(m_size == rhs.m_size)
        {
        for(int i = 0; i < m_size; i++)
        {
            temp[i] = m_matrix[i] + rhs.m_matrix[i];
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary + between a lowerMatrix and a diagonalMatrix
template <typename T>
lowerMatrix<T> lowerMatrix<T>::operator+(const diagonalMatrix<T> &rhs)const
{
    lowerMatrix<T> temp(*this);
    
    if(m_size == rhs.getSize())
        {
        for(int i = 0; i < m_size; i++)
        {
            temp(i,i) = temp(i,i) + rhs(i,i);
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary + between a lowerMatrix and a tridiagonalMatrix
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator+(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
             if(i == j-1)
                {
                    temp[i][j] = rhs(i,j);
                }
                else if (i == j || i == j+1)
                {
                    temp[i][j] = duplicate(i,j) + rhs(i,j);
                }
                else if(i > j+1)
                {
                    temp[i][j] = duplicate(i,j);
                }
            }
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary + between a lowerMatrix and a symmetricMatrix
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator+(const symmetricMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i < j)
                {
                    temp[i][j] = rhs(i,j);
                }
                else
                {
                    temp[i][j] = duplicate(i,j) + rhs(i,j);
                }
            }
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary - between 2 matrixs
template <typename T>
lowerMatrix<T> lowerMatrix<T>::operator-(const lowerMatrix<T> &rhs)const
{
    lowerMatrix<T> temp(m_size);
    
    if(m_size == rhs.m_size)
        {
        for(int i = 0; i < m_size; i++)
        {
            temp[i] = m_matrix[i] - rhs.m_matrix[i];
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary - between a lowerMatrix and a diagonal
template <typename T>
lowerMatrix<T> lowerMatrix<T>::operator-(const diagonalMatrix<T> &rhs)const
{
    lowerMatrix<T> temp(*this);
    
    if(m_size == rhs.getSize())
        {
        for(int i = 0; i < m_size; i++)
        {
            temp(i,i) = temp(i,i) - rhs(i,i);
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary - between a lowerMatrix and a tridiagonalMatrix
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator-(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        temp = *this + rhs *-1;
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary - between a lowerMatrix and a symmetricMatrix
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator-(const symmetricMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i < j)
                {
                    temp[i][j] = rhs(i,j) *-1;
                }
                else
                {
                    temp[i][j] = duplicate(i,j) - rhs(i,j);
                }
            }
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary * between 2 lowerMatrixs
template <typename T>
lowerMatrix<T> lowerMatrix<T>::operator*(const lowerMatrix<T> &rhs)const
{
    lowerMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                for(int k = 0; k < m_size; k++)
                {
                    if(i >= j && i >= k)
                    {
                        temp(i,j) = temp(i,j) + (duplicate(i,k) * rhs(k,j));
                    }   
                }
            }
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;

}

//Binary * between a lowerMatrix and a upperMatrix
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator*(const upperMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> copyVector(*this);
    lowerMatrix<T> transpose(rhs.transpose());
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            int size = 0;
            for(int j = 0; j < m_size; j++)
            {
                {
                    if(size != copyVector[i].getSize())
                    {
                        size++;
                    }
                    myvector<T> tempVector1(size);
                    myvector<T> tempVector2(tempVector1.getSize());

                    for(int k = 0; k <tempVector1.getSize(); k++)
                    {
                        tempVector1[k] = copyVector(i,k);
                        tempVector2[k] = transpose(j,k);
                    }
                    
                    temp[i][j] = tempVector1 * tempVector2;

                }  
            }
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;

}

//Binary * between a lowerMatrix and a denseMatrix
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator*(const denseMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getColumnSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getColumnSize(); j++)
            {  
                for(int k = 0; k < rhs.getColumnSize(); k++)
                {
                    if(i >= k)
                    {
                        temp[i][j] =  temp[i][j] + (duplicate(i,k) * rhs[k][j]);
                    }
                }
            }
            
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary * between a lowerMatrix and a tridiagonalMatrix
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator*(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getSize(); j++)
            {  
                for(int k = 0; k < rhs.getSize(); k++)
                {
                    if(i >= k)
                    {
                        temp[i][j] =  temp[i][j] + (duplicate(i,k) * rhs(k,j));
                    }
                }
            }
            
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary * between a lowerMatrix and a diagonalMatrix
template <typename T>
lowerMatrix<T> lowerMatrix<T>::operator*(const diagonalMatrix<T> &rhs)const
{
    lowerMatrix<T> temp(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i >=j)
                {
                    temp(i,j) =  temp(i,j) * rhs[0][j];
                }
            }
        }

    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary * between a upperMatrix and a symmetricMatrix
template <typename T>
denseMatrix<T> lowerMatrix<T>::operator*(const symmetricMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    lowerMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getSize(); j++)
            {  
                for(int k = 0; k < rhs.getSize(); k++)
                {
                    if(i >= k)
                    {
                        temp[i][j] =  temp[i][j] + (duplicate(i,k) * rhs(k,j));
                    }
                }
            }
            
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary * between a matrix and a vector
template <typename T>
myvector<T> lowerMatrix<T>::operator*(const myvector<T> &rhs)const
{
    myvector<T> temp(m_size);
    
    if(m_size == rhs.getSize())
    {
        
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i >= j)
                {
                    temp[i] = temp[i] + m_matrix[i][j] * rhs[j];
                }
            }
        }

    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;


}

//Scalar multiplication
template <typename T>
lowerMatrix<T> lowerMatrix<T>::operator*(const int scale)const
{
    lowerMatrix<T> temp(m_size);
    
    for(int i = 0; i < m_size; i++)
    {
        temp[i] = m_matrix[i] * scale;
    }

    return temp;
}

//Operator []
template <typename T>
myvector<T> lowerMatrix<T>::operator[](int index)const
{
    if(m_size >= index)
    {
        return m_matrix[index];
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Operator [] with reference
template <typename T>
myvector<T>& lowerMatrix<T>::operator[](int index)
{
    if(m_size >= index)
    {
        return m_matrix[index];
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Operator ()
template <typename T>
T lowerMatrix<T>::operator()(const int i,const int j)const
{
    if(i < m_size && j < m_size)
    {
        if(i < j)
        {
            return 0;
        }
        else
        {
            return m_matrix[i][j];
        }
        
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Operator () with reference
template <typename T>
T& lowerMatrix<T>::operator()(const int i,const int j)
{
    if(i < m_size && j < m_size)
    {
        if(i < j)
        {
            throw std::out_of_range( "Can Not Access that index");
        }
        else
        {
            return m_matrix[i][j];
        }
        
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Transpose function
template <typename T>
upperMatrix<T> lowerMatrix<T>::transpose()const
{
    upperMatrix<T> temp(m_size);
    lowerMatrix<T> copyMatrix(*this);

    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0+i; j < m_size; j++)
        {
            temp(i,j) = copyMatrix(j,i);
        }
    }

    return temp;

}

//Gettter for m_size
template <typename T>
int lowerMatrix<T>::getSize()const
{
    return m_size;
}

//Output
template <typename T>
std::ostream& operator<<(std::ostream& os, const lowerMatrix<T> &obj)
{
    for(int i = 0; i < obj.getSize(); i++)
    {

        for(int j = 0; j < obj.getSize(); j++)
        {
            os << obj(i,j) << " ";
        }

        std::cout << std::endl;
    }
    return os;  
}

//Input
template <typename T>
std::istream& operator>>(std::istream& in, lowerMatrix<T> &obj)
{
    for(int i = 0; i < obj.getSize(); i++)
    {
        in >> obj[i];
    }

    return in;
}