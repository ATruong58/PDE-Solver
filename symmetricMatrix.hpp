//Default Constructor
template <typename T>
symmetricMatrix<T>::symmetricMatrix()
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
symmetricMatrix<T>::symmetricMatrix(const int size)
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
symmetricMatrix<T>::symmetricMatrix(const symmetricMatrix &source)
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
symmetricMatrix<T>& symmetricMatrix<T>::operator=(const symmetricMatrix<T> &source)
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
symmetricMatrix<T>& symmetricMatrix<T>::operator=(symmetricMatrix<T> &&source)
{
    m_matrix = myvector<myvector<T> >(source.m_size);

    m_matrix = std::move(source.m_matrix);

    m_size = source.m_size;

    return *this;

}


//Binary + between a  symmetric matrix and a matrix class
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator+(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    const symmetricMatrix<T> duplicate(*this);
    
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

//Binary - between a symmetric matrix and a matrix class
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator-(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    const symmetricMatrix<T> duplicate(*this);
    
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

//Binary * between a symmetric matrix and a matrix class
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator*(const matrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    
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

//Binary + between 2 symmetrixMatrixs
template <typename T>
symmetricMatrix<T> symmetricMatrix<T>::operator+(const symmetricMatrix<T> &rhs)const
{
    symmetricMatrix<T> temp(m_size,m_size);
    
    if(m_size == rhs.getSize())
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

//Binary + between a symmetrixMatrix and a denseMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator+(const denseMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    
    if(m_size == rhs.getRowSize())
    {
        temp = rhs + *this;
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary + between a symmetrixMatrix and a tridiagonalMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator+(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j< m_size; j++)
            {
                if(i == j || i == j+1 || i == j -1)
                {
                    temp[i][j] = duplicate(i,j) + rhs(i,j);
                }
                else
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

//Binary - between 2 symmetrixMatrixs
template <typename T>
symmetricMatrix<T> symmetricMatrix<T>::operator-(const symmetricMatrix<T> &rhs)const
{
    symmetricMatrix<T> temp(m_size);
    
    if(m_size == rhs.getSize())
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

//Binary - between a symmetrixMatrix and a denseMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator-(const denseMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    
    if(m_size == rhs.getRowSize())
    {
        temp = *this + rhs * -1;
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary - between a symmetrixMatrix and a tridiagonalMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator-(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j< m_size; j++)
            {
                if(i == j || i == j+1 || i == j -1)
                {
                    temp[i][j] = duplicate(i,j) - rhs(i,j);
                }
                else
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

//Binary * between a symmetricMatrix and a upperMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator*(const upperMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getSize(); j++)
            {  
                for(int k = 0; k < rhs.getSize(); k++)
                {
                    if(i <= k || j >= k)
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

//Binary * between a symmetricMatrix and a lowerMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator*(const lowerMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getSize(); j++)
            {  
                for(int k = 0; k < rhs.getSize(); k++)
                {
                    if(i >= k || j <= k)
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

//Binary * between a symmetricMatrix and a denseMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator*(const denseMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getRowSize())
    {

        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getRowSize(); j++)
            {  
                for(int k = 0; k < rhs.getRowSize(); k++)
                {
                    temp[i][j] =  temp[i][j] + (duplicate(i,k) * rhs[k][j]);
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

//Binary * between a symmetricMatrix and a diagonalMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator*(const diagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                temp[i][j] = duplicate(i,j) * rhs[0][j];
            }
        }

    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary * between a symmetricMatrix and a tridiagnolMatrix
template <typename T>
denseMatrix<T> symmetricMatrix<T>::operator*(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.getSize(); j++)
            {  
                for(int k = 0; k < rhs.getSize(); k++)
                {
                    if(i <= k + 1 || i >= k - 1 || i == k)
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

//Scalar multiplication
template <typename T>
symmetricMatrix<T> symmetricMatrix<T>::operator*(const int scale)const
{
    symmetricMatrix temp(m_size);

    for(int i = 0; i < m_size; i++)
    {
        temp.m_matrix[i] = m_matrix[i] * scale;
    }

    return temp;
}

//Binary * between a matrix and a vector
template <typename T>
myvector<T> symmetricMatrix<T>::operator*(const myvector<T> &rhs)const
{
    myvector<T> temp(m_size);
    symmetricMatrix<T> duplicate(*this);
    if(m_size == rhs.getSize())
    {
        
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < m_size; j++)
            {
                temp[i] = temp[i] + (duplicate(i,j) * rhs[j]);
            }
        }

    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;


}

//Operator []
template <typename T>
myvector<T> symmetricMatrix<T>::operator[](int index)const
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
myvector<T>& symmetricMatrix<T>::operator[](int index)
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
T symmetricMatrix<T>::operator()(const int i,const int j)const
{
    if(i < m_size && j < m_size)
    {
        if(i < j)
        {
            return m_matrix[j][i];
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
T& symmetricMatrix<T>::operator()(const int i,const int j)
{
    if(i < m_size && j < m_size)
    {
        if(i < j)
        {
            return m_matrix[j][i];
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

//Gettter for m_size
template <typename T>
int symmetricMatrix<T>::getSize()const
{
    return m_size;
}

//Output
template <typename T>
std::ostream& operator<<(std::ostream& os, const symmetricMatrix<T> &obj)
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
std::istream& operator>>(std::istream& in, symmetricMatrix<T> &obj)
{
    for(int i = 0; i < obj.getSize(); i++)
    {
        for(int j = 0; j < obj.getSize(); j++)
        {
            in >> obj(i,j);
        }
    }

    return in;
}