//Default Constructor
template <typename T>
upperMatrix<T>::upperMatrix()
{
    m_matrix = myvector<myvector<T>>(3);

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
    m_matrix = myvector<myvector<T>>(size);

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
    m_matrix = myvector<myvector<T>>(source.m_column_size);

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
    m_matrix = myvector<myvector<T>>(source.m_size);

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
    m_matrix = myvector<myvector<T>>(source.m_size);

    m_matrix = std::move(source.m_matrix);

    m_size = source.m_size;

    return *this;

}

//Binary + between 2 matrixs
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

//Binary - between 2 matrixs
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

//Binary * between 2 matrixs
template <typename T>
upperMatrix<T> upperMatrix<T>::operator*(const upperMatrix<T> &rhs)const
{
    upperMatrix<T> temp(m_size);
    
    if(m_size == rhs.m_size)
    {

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
            temp[i] = m_matrix[i] * rhs;
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
    upperMatrix<T> temp(m_size, m_size);
    
    for(int i = 0; i < m_size; i++)
    {
        temp[i] = m_matrix[i] * scale;
    }

    return temp;
}


//Operator [] with reference
template <typename T>
T& upperMatrix<T>::operator()(int i, int j)
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

//Operator []
template <typename T>
T upperMatrix<T>::operator()(int i, int j)const
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