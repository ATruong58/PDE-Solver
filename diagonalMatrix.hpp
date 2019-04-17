//Default Constructor
template <typename T>
diagonalMatrix<T>::diagonalMatrix()
{
    m_matrix = myvector<T>(3);

    m_size = 3;
}

//Paramitized Constructor
template <typename T>
diagonalMatrix<T>::diagonalMatrix(const int size)
{
    m_matrix = myvector<T>(size);

    m_size = size;
}

//Copy Constructor
template <typename T>
diagonalMatrix<T>::diagonalMatrix(const diagonalMatrix &source)
{
    m_matrix = source.m_matrix;
    m_size = source.m_size;
}

//Operator = 
template <typename T>
diagonalMatrix<T>& diagonalMatrix<T>::operator=(const diagonalMatrix<T> &source)
{
    m_matrix = source.m_matrix;
    m_size = source.m_size;

    return *this;

}

//Operator = (move constructor)
template <typename T>
diagonalMatrix<T>& diagonalMatrix<T>::operator=(diagonalMatrix<T> &&source)
{
    m_matrix = myvector<myvector<T> >(source.m_size);

    m_matrix = std::move(source.m_matrix);

    m_size = source.m_size;

    return *this;

}

//Binary + between 2 diagonalMatrixs
template <typename T>
diagonalMatrix<T> diagonalMatrix<T>::operator+(const diagonalMatrix<T> &rhs)const
{
    diagonalMatrix<T> temp(m_size);
    
    if(m_size == rhs.m_size)
    {
        temp.m_matrix = m_matrix + rhs.m_matrix;
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary - between 2 diagonalMatrixs
template <typename T>
diagonalMatrix<T> diagonalMatrix<T>::operator-(const diagonalMatrix<T> &rhs)const
{
    diagonalMatrix<T> temp(m_size);
    
    if(m_size == rhs.m_size)
    {
        temp.m_matrix = m_matrix - rhs.m_matrix;
    }
    else
    {
        throw std::out_of_range( "Size not equal");
    }

    return temp;
}

//Binary * between 2 diagonalMatrixs
template <typename T>
diagonalMatrix<T> diagonalMatrix<T>::operator*(const diagonalMatrix<T> &rhs)const
{
    diagonalMatrix<T> temp(m_size);
    
    if(m_size == rhs.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            temp.m_matrix[i] = m_matrix[i] * rhs.m_matrix[i];
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
diagonalMatrix<T> diagonalMatrix<T>::operator*(const int scale)const
{
    return m_matrix * scale;
}

//Binary * between a matrix and a vector
template <typename T>
myvector<T> diagonalMatrix<T>::operator*(const myvector<T> &rhs)const
{
    myvector<T> temp(m_size);
    
    if(m_size == rhs.getSize())
    {
        for(int i = 0; i < m_size; i++)
        {
            temp[i] = m_matrix[i] * rhs[i];
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
myvector<T> diagonalMatrix<T>::operator[](int index)const
{
    if(m_size >= index)
    {
        return m_matrix;
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Operator [] with reference
template <typename T>
myvector<T>& diagonalMatrix<T>::operator[](int index)
{
    if(m_size >= index)
    {
        return m_matrix;
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Operator ()
template <typename T>
T diagonalMatrix<T>::operator()(const int i,const int j)const
{
    if(i < m_size && j < m_size)
    {
        if(i != j)
        {
            return 0;
        }
        else
        {
            return m_matrix[i];
        }
        
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Operator () with reference
template <typename T>
T& diagonalMatrix<T>::operator()(const int i,const int j)
{
    if(i < m_size && j < m_size)
    {
        if(i != j)
        {
            throw std::out_of_range( "Can Not Access that index");
        }
        else
        {
            return m_matrix[i];
        }
        
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Gettter for m_size
template <typename T>
int diagonalMatrix<T>::getSize()const
{
    return m_size;
}

//Output
template <typename T>
std::ostream& operator<<(std::ostream& os, const diagonalMatrix<T> &obj)
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
std::istream& operator>>(std::istream& in, diagonalMatrix<T> &obj)
{
    in >> obj[0];

    return in;
}