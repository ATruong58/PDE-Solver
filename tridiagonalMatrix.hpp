//Default Constructor
template <typename T>
tridiagonalMatrix<T>::tridiagonalMatrix()
{
    m_matrix = myvector<myvector<T>>(3);

    for(int i = 0; i < 3; i++)
    {   
        if(i == 0)
        {
            m_matrix[i] = myvector<T>(3); 
        }
        else
        {
            m_matrix[i] = myvector<T>(2);
        }
        
    }

    m_size = 3;
}

//Paramitized Constructor
template <typename T>
tridiagonalMatrix<T>::tridiagonalMatrix(const int size)
{
    m_matrix = myvector<myvector<T>>(3);

    for(int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            m_matrix[i] = myvector<T>(size); 
        }
        else
        {
            m_matrix[i] = myvector<T>(size-1);
        }
    }

    m_size = size;
}

//Copy Constructor
template <typename T>
tridiagonalMatrix<T>::tridiagonalMatrix(const tridiagonalMatrix &source)
{
    m_matrix = myvector<myvector<T>>(source.m_size);

    for(int i = 0; i < 3; i++)
    {
        m_matrix[i] = source[i];
    }

    m_size = source.m_size;
}

//Operator = 
template <typename T>
tridiagonalMatrix<T>& tridiagonalMatrix<T>::operator=(const tridiagonalMatrix<T> &source)
{
    m_matrix = myvector<myvector<T>>(source.m_size);

    for(int i = 0; i < 3; i++)
    {
        m_matrix[i] = source[i];
    }

    m_size = source.m_size;


    return *this;
}

//Operator = (move constructor)
template <typename T>
tridiagonalMatrix<T>& tridiagonalMatrix<T>::operator=(tridiagonalMatrix<T> &&source)
{
    m_matrix = myvector<myvector<T>>(source.m_size);

    m_matrix = std::move(source.m_matrix);

    m_size = source.m_size;

    return *this;

}

//Binary + between 2 matrixs
template <typename T>
tridiagonalMatrix<T> tridiagonalMatrix<T>::operator+(const tridiagonalMatrix<T> &rhs)const
{
    tridiagonalMatrix<T> temp(m_size);
    
    if(m_size == rhs.m_size)
        {
        for(int i = 0; i < 3; i++)
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

//Binary + between 2 matrixs
template <typename T>
tridiagonalMatrix<T> tridiagonalMatrix<T>::operator-(const tridiagonalMatrix<T> &rhs)const
{
    tridiagonalMatrix<T> temp(m_size);
    
    if(m_size == rhs.m_size)
        {
        for(int i = 0; i < 3; i++)
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

//Binary * between 2 tridiagonalMatrixs
template <typename T>
denseMatrix<T> tridiagonalMatrix<T>::operator*(const tridiagonalMatrix<T> &rhs)const
{
    denseMatrix<T> temp(m_size,m_size);
    const tridiagonalMatrix<T> duplicate(*this);
    
    if(m_size == rhs.m_size)
    {
        for(int i = 0; i < m_size; i++)
        {
            for(int j = 0; j < rhs.m_size; j++)
            {
                for(int k = 0; k < rhs.m_size; k++)
                {
                    temp[i][j] =  temp[i][j] + (duplicate(i,k) * duplicate(j,k));
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
tridiagonalMatrix<T> tridiagonalMatrix<T>::operator*(const int scale)const
{
    tridiagonalMatrix temp(m_size);

    for(int i = 0; i < 3; i++)
    {
        temp.m_matrix[i] = m_matrix[i] * scale;
    }

    return temp;
}

//Binary * between a matrix and a vector
template <typename T>
myvector<T> tridiagonalMatrix<T>::operator*(const myvector<T> &rhs)const
{
    myvector<T> temp(m_size);
    const tridiagonalMatrix<T> duplicate(*this);
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
myvector<T> tridiagonalMatrix<T>::operator[](int index)const
{
    if(3 > index && index > -1)
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
myvector<T>& tridiagonalMatrix<T>::operator[](int index)
{
    if(3 > index && index > -1)
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
T tridiagonalMatrix<T>::operator()(const int i,const int j)const
{
    if(i < m_size && j < m_size)
    {
        if(i == j)
        {
            return m_matrix[0][j];
        }
        else if (i == j - 1)
        {
            return m_matrix[1][j-1];
        }
        else if (i == j + 1)
        {
            return m_matrix[2][j];
        }
        else
        {
            return 0;
        }
        
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Operator ()
template <typename T>
T& tridiagonalMatrix<T>::operator()(const int i,const int j)
{
    if(i < m_size && j < m_size)
    {
        if(i == j)
        {
            return m_matrix[0][j];
        }
        else if (i == j - 1)
        {
            return m_matrix[1][j-1];
        }
        else if (i == j + 1)
        {
            return m_matrix[2][j];
        }
        else
        {
            throw std::out_of_range( "Cannot access that index");
        }
        
    }
    else
    {
        throw std::out_of_range( "Index out of bounds");
    }
}

//Transpose function
template <typename T>
denseMatrix<T> tridiagonalMatrix<T>::transpose()const
{
    denseMatrix<T> temp(m_size, m_size);
    tridiagonalMatrix duplicate(*this);

    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            temp[i][j] = duplicate(i,j);
        }
    }

    return temp;

}

//Gettter for m_size
template <typename T>
int tridiagonalMatrix<T>::getSize()const
{
    return m_size;
}

//Output
template <typename T>
std::ostream& operator<<(std::ostream& os, const tridiagonalMatrix<T> &obj)
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
std::istream& operator>>(std::istream& in, tridiagonalMatrix<T> &obj)
{
    for(int i = 0; i < obj.getSize(); i++)
    {
        in >> obj[i];
    }

    return in;
}
