template <typename T>
mymatrix<T>::mymatrix()
{
    m_matrix = myvector<myvector<T>>(3);

    for(int i = 0; i < 3; i++)
    {
        m_matrix[i] = myvector<T>(3); 
    }

    m_column_size = 3;
    m_row_size = 3;
}

template <typename T>
mymatrix<T>::mymatrix(const int column_size, const int row_size)
{
    m_matrix = myvector<myvector<T>>(column_size);

    for(int i = 0; i < column_size; i++)
    {
        m_matrix[i] = myvector<T>(row_size); 
    }

    m_column_size = column_size;
    m_row_size = row_size;
}

template <typename T>
mymatrix<T>::mymatrix(const mymatrix &source)
{
    m_matrix = myvector<myvector<T>>(source.m_column_size);

    for(int i = 0; i < source.m_column_size; i++)
    {
        m_matrix[i] = source[i];
    }

    m_column_size = source.m_column_size;
    m_row_size = source.m_row_size;
}

template <typename T>
mymatrix<T>& mymatrix<T>::operator=(const mymatrix<T> &source)
{
    m_matrix = myvector<myvector<T>>(source.m_column_size);

    for(int i = 0; i < source.m_column_size; i++)
    {
        m_matrix[i] = source[i];
    }

    m_column_size = source.m_column_size;
    m_row_size = source.m_row_size;

    return *this;

}

template <typename T>
mymatrix<T>& mymatrix<T>::operator=(mymatrix<T> &&source)
{
    m_matrix = myvector<myvector<T>>(source.m_column_size);

    m_matrix = std::move(source.m_matrix);

    m_column_size = source.m_column_size;
    m_row_size = source.m_row_size;

    return *this;

}

template <typename T>
mymatrix<T> mymatrix<T>::operator+(const mymatrix<T> &rhs)const
{
    mymatrix<T> temp(m_column_size, m_row_size);
    
    if(m_column_size == rhs.m_column_size && m_row_size == rhs.m_row_size)
        {
        for(int i = 0; i < m_column_size; i++)
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

template <typename T>
mymatrix<T> mymatrix<T>::operator-(const mymatrix<T> &rhs)const
{
    mymatrix<T> temp(m_column_size, m_row_size);
    
    if(m_column_size == rhs.m_column_size && m_row_size == rhs.m_row_size)
        {
        for(int i = 0; i < m_column_size; i++)
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

template <typename T>
mymatrix<T> mymatrix<T>::operator*(const mymatrix<T> &rhs)const
{
    mymatrix<T> temp(m_column_size, rhs.m_row_size);
    mymatrix<T> transpose = rhs.transpose();
    
    if(m_row_size == rhs.m_column_size)
    {

        for(int i = 0; i < m_column_size; i++)
        {
            for(int j = 0; j < rhs.m_row_size; j++)
            {
                temp[i][j] = m_matrix[i] * transpose[j];
            }    
        }

    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;

}

template <typename T>
myvector<T> mymatrix<T>::operator*(const myvector<T> &rhs)const
{
    myvector<T> temp(m_column_size);
    
    if(m_row_size == rhs.getSize())
    {
        
        for(int i = 0; i < m_column_size; i++)
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

template <typename T>
mymatrix<T> mymatrix<T>::operator*(const int scale)const
{
    mymatrix<T> temp(m_column_size, m_row_size);
    
    for(int i = 0; i < m_column_size; i++)
    {
        temp[i] = m_matrix[i] * scale;
    }

    return temp;
}

template <typename T>
myvector<T> mymatrix<T>::operator[](int index)const
{
    if(m_column_size >= index)
    {
        return m_matrix[index];
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

template <typename T>
myvector<T>& mymatrix<T>::operator[](int index)
{
    if(m_column_size>= index)
    {
        return m_matrix[index];
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

template <typename T>
mymatrix<T> mymatrix<T>::transpose()const
{
    mymatrix temp(m_row_size, m_column_size);

    for(int i = 0; i < m_row_size; i++)
    {
        for(int j = 0; j < m_column_size; j++)
        {
            temp[i][j] = m_matrix[j][i];
        }
    }

    return temp;


}

template <typename T>
int mymatrix<T>::getColumnSize()const
{
    return m_column_size;
}

template <typename T>
int mymatrix<T>::getRowSize()const
{
    return m_row_size;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const mymatrix<T> &obj)
{
    for(int i = 0; i < obj.getColumnSize(); i++)
    {
        os << obj[i] << std::endl;
    }
    return os;  
}

template <typename T>
std::istream& operator>>(std::istream& in, mymatrix<T> &obj)
{
    for(int i = 0; i < obj.getColumnSize(); i++)
    {
        in >> obj[i];
    }

    return in;
}