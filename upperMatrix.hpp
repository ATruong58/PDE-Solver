//Default Constructor
template <typename T>
upperMatrix<T>::upperMatrix()
{
    m_matrix = myvector<myvector<T> >(3);

    for(int i = 0; i < 3; i++)
    {
        m_matrix[i] = myvector<T>(3-i); 
    }

    m_size = 3;
}

//Paramitized Constructor
template <typename T>
upperMatrix<T>::upperMatrix(const int size)
{
    m_matrix = myvector<myvector<T> >(size);

    for(int i = 0; i < size; i++)
    {
        m_matrix[i] = myvector<T>(size - i); 
    }

    m_size = size;
}

//Copy Constructor
template <typename T>
upperMatrix<T>::upperMatrix(const upperMatrix &source)
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
upperMatrix<T>& upperMatrix<T>::operator=(const upperMatrix<T> &source)
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
upperMatrix<T>& upperMatrix<T>::operator=(upperMatrix<T> &&source)
{
    m_matrix = myvector<myvector<T> >(source.m_size);

    m_matrix = std::move(source.m_matrix);

    m_size = source.m_size;

    return *this;

}

//Binary + between a upper matrix and a matrix class
template <typename T>
denseMatrix<T> upperMatrix<T>::operator+(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
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

//Binary - between a upper matrix and a matrix class
template <typename T>
denseMatrix<T> upperMatrix<T>::operator-(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
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

//Binary * between a dense matrix and a matrix class
template <typename T>
denseMatrix<T> upperMatrix<T>::operator*(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
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


//Binary + between 2 upperMatrixs
template <typename T>
upperMatrix<T> upperMatrix<T>::operator+(const upperMatrix<T> &rhs)const
{
    upperMatrix<T> temp(m_size);
    
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

//Binary + between a upperMatrix and a lowerMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator+(const lowerMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i < j)
                {
                    temp[i][j] = duplicate(i,j);
                }
                else if(i >  j)
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

//Binary + between a upperMatrix and a diagonalMatrix
template <typename T>
upperMatrix<T> upperMatrix<T>::operator+(const diagonalMatrix<T> &rhs)const
{
    upperMatrix<T> temp(*this);
    
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

//Binary + between a upperMatrix and a tridiagonalMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator+(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i == j+1)
                {
                    temp[i][j] = rhs(i,j);
                }
                else if (i == j || i == j-1)
                {
                    temp[i][j] = duplicate(i,j) + rhs(i,j);
                }
                else if(i < j-1)
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

//Binary + between a upperMatrix and a symmetricMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator+(const symmetricMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i > j)
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

//Binary - between 2 upperMatrixs
template <typename T>
upperMatrix<T> upperMatrix<T>::operator-(const upperMatrix<T> &rhs)const
{
    upperMatrix<T> temp(m_size);
    
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

//Binary - between a upperMatrix and a lowerMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator-(const lowerMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i < j)
                {
                    temp[i][j] = duplicate(i,j);
                }
                else if(i > j)
                {
                    temp[i][j] = rhs(i,j);
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

//Binary - between a upperMatrix and a diagonalMatrix
template <typename T>
upperMatrix<T> upperMatrix<T>::operator-(const diagonalMatrix<T> &rhs)const
{
    upperMatrix<T> temp(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            temp(i,i) = temp(i,i) - rhs[i][i];
        }
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary - between a upperMatrix and a tridiagonalMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator-(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i == j+1)
                {
                    temp[i][j] = rhs(i,j) * -1;
                }
                else if (i == j || i == j-1)
                {
                    temp[i][j] = duplicate(i,j) - rhs(i,j);
                }
                else if(i < j-1)
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

//Binary - between a upperMatrix and a symmetricMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator-(const symmetricMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i > j)
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


//Binary * between 2 upperMatrixs
template <typename T>
upperMatrix<T> upperMatrix<T>::operator*(const upperMatrix<T> &rhs)const
{
    upperMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                for(int k = 0; k < m_size; k++)
                {
                    if(i <= j && i <= k)
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

//Binary * between a upperMatrix and a lowerMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator*(const lowerMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> copyVector(*this);
    upperMatrix<T> transpose(rhs.transpose());
    
    if(m_size == rhs.getSize())
    {

        for(int i = m_size-1; i >= 0; i--)
        {
            int size = 0;
            for(int j = m_size-1; j >= 0; j--)
            {
                {
                    if(size != copyVector[i].getSize())
                    {
                        size++;
                    }
                    myvector<T> tempVector1(size);
                    myvector<T> tempVector2(tempVector1.getSize());

                    for(int k = 0; k < tempVector1.getSize(); k++)
                    {
                        tempVector1[k] = copyVector(i,m_size-k-1);
                        tempVector2[k] = transpose(j,m_size-k-1);
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

//Binary * between a upperMatrix and a denseMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator*(const denseMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getColumnSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getColumnSize(); j++)
            {  
                for(int k = 0; k < rhs.getColumnSize(); k++)
                {
                    if(i <= k)
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

//Binary * between a upperMatrix and a tridiagonalMatrix
template <typename T>
denseMatrix<T> upperMatrix<T>::operator*(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getSize(); j++)
            {  
                for(int k = 0; k < rhs.getSize(); k++)
                {
                    if(i <= k)
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

//Binary * between a upperMatrix and a diagonalMatrix
template <typename T>
upperMatrix<T> upperMatrix<T>::operator*(const diagonalMatrix<T> &rhs)const
{
    upperMatrix<T> temp(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i <=j)
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
denseMatrix<T> upperMatrix<T>::operator*(const symmetricMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    upperMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getSize(); j++)
            {  
                for(int k = 0; k < rhs.getSize(); k++)
                {
                    if(i <= k)
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
myvector<T> upperMatrix<T>::operator*(const myvector<T> &rhs)const
{
    myvector<T> temp(m_size);
    
    if(m_size == rhs.getSize())
    {
        
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                if(i <= j)
                {
                    temp[i] = temp[i] + m_matrix[i][j-i] * rhs[j];
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
upperMatrix<T> upperMatrix<T>::operator*(const int scale)const
{
    upperMatrix<T> temp(m_size);
    
    for(int i = 0; i < m_size; i++)
    {
        temp[i] = m_matrix[i] * scale;
    }

    return temp;
}

//Operator []
template <typename T>
myvector<T> upperMatrix<T>::operator[](int index)const
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
myvector<T>& upperMatrix<T>::operator[](int index)
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
T upperMatrix<T>::operator()(const int i,const int j)const
{
    if(i < m_size && j < m_size)
    {
        if(i > j)
        {
            return 0;
        }
        else
        {
            return m_matrix[i][j-i];
        }
        
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Operator () with reference
template <typename T>
T& upperMatrix<T>::operator()(const int i,const int j)
{
    if(i < m_size && j < m_size)
    {
        if(i > j)
        {
            throw std::out_of_range( "Can Not Access that index");
        }
        else
        {
            return m_matrix[i][j-i];
        }
        
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Transpose function
template <typename T>
lowerMatrix<T> upperMatrix<T>::transpose()const
{
    lowerMatrix<T> temp(m_size);
    upperMatrix<T> copyMatrix(*this);

    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0+i; j < m_size; j++)
        {
            temp(j,i) = copyMatrix(i,j);
        }
    }

    return temp;

}

//Gettter for m_size
template <typename T>
int upperMatrix<T>::getSize()const
{
    return m_size;
}

//Output
template <typename T>
std::ostream& operator<<(std::ostream& os, const upperMatrix<T> &obj)
{
    for(int i = 0; i < obj.getSize(); i++)
    {
        for(int j = 0; j < obj.getSize(); j++)
        {
            os << obj(i,j) << " ";
        }      

       os << std::endl;
    }
    return os;  
}

//Input
template <typename T>
std::istream& operator>>(std::istream& in, upperMatrix<T> &obj)
{
    for(int i = 0; i < obj.getSize(); i++)
    {
        in >> obj[i];
    }

    return in;
}