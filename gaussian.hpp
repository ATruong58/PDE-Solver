//Guassian Elimination for denseMatrix
template <typename T>
myvector<T> Gaussian_solver::operator()(const denseMatrix<T>& set, const myvector<T>& b)const
{
    int size = set.getColumnSize();
    denseMatrix<T> matrix = set;
    myvector<T> bvector = b;

    myvector<T> x(size);
    
    for(int i = 0; i < size; i++) {
        // Search for maximum in this column
        if(matrix[i].getmax() == 0)
        {
            throw std::out_of_range( "Dividing by zero");
        }
        double maxEl = fabs(matrix[i][i]/matrix[i].getmax());
        int maxRow = i;
        myvector<T> temp;

        for(int j = i+1; j < size; j++) 
        {
            if(matrix[j].getmax() == 0)
            {
                throw std::out_of_range( "Dividing by zero");
            }
            if(fabs(matrix[j][i]/matrix[j].getmax()) > maxEl)
            {
                maxEl = fabs(matrix[j][i]/matrix[j].getmax());
                maxRow = j;
            }
        }

        // Swap maximum row with current row
        temp = matrix[maxRow];
        matrix[maxRow] = matrix[i];
        matrix[i] = temp;

        // Make all rows below this one 0 in current column
        for(int j = i+1; j < size; j++) 
        {
            if(matrix[i][i] == 0)
            {
                throw std::out_of_range( "Dividing by zero");
            }
            double scale = -matrix[j][i]/matrix[i][i];
            for(int k = i; k < size+1; k++)
            {   
                if(i==k)
                {
                    matrix[j][k] = 0;
                } 
                else
                {
                    matrix[j][k] += scale * matrix[i][k];
                    
                }
            }
            bvector[j] += scale * bvector[i];
        }
    }

    //Make the solution vector 
    for(int i = size-1; i >= 0; i--)
    {
        //round the number to 8 decimal place
        if(matrix[i][i] == 0)
        {
            throw std::out_of_range( "Dividing by zero");
        }
        x[i] = round(bvector[i]/matrix[i][i] *100000000.0) /100000000.0;
        
        for (int k = i-1 ; k >= 0; k--)
        {
            bvector[k] -= matrix[k][i] * x[i];
        }
    }

    return x;

}

//Guassian Elimination for upperMatrix
template <typename T>
myvector<T> Gaussian_solver::operator()(const upperMatrix<T>& set, const myvector<T>& b)const
{
    myvector<T> solution(set.getSize());
    
    if(b.getSize() != set.getSize())
    {
        throw std::out_of_range("Size not equal");
    }

    for(int i = set.getSize(); i > 0; i--)
    {
        double sum = 0;

        for(int j = 0; j < set[i-1].getSize(); j++)
        {
            sum += solution[i-1+j] * set(i-1,i-1+j);
        }
        if(set(i-1,i-1) == 0)
        {
            throw std::out_of_range( "Dividing by zero");
        }
        solution[i-1] = (b[i-1] - sum)/set(i-1,i-1);
    }

    return solution;

}

//Guassian Elimination for lowerMatrix
template <typename T>
myvector<T> Gaussian_solver::operator()(const lowerMatrix<T>& set, const myvector<T>& b)const
{
    if(set.getSize() == b.getSize())
    {
        myvector<T> solution(set.getSize());

        for(int i = 0; i < set.getSize(); i++)
        {
            double sum = 0;

            for(int j = 0; j < i+1 ; j++)
            {
                sum += solution[j] * set(i,j);
            }
            if(set(i,i) == 0)
            {
                throw std::out_of_range( "Dividing by zero");
            }
            solution[i] = (b[i] - sum)/set(i,i);
        }

        return solution;

    }
    else
    {
        throw std::out_of_range("Size not equal");
    }
}

//Guassian Elimination for symmetricMatrix
template <typename T>
myvector<T> Gaussian_solver::operator()(const symmetricMatrix<T>& set, const myvector<T>& b)const
{

    symmetricMatrix<T> matrix = set;
    denseMatrix<T> copy(matrix.getSize());
    for(int i = 0; i < matrix.getSize(); i++)
    {
        for (int j = 0; j < matrix.getSize(); j++)
        {
            copy[i][j] = matrix(i,j);
        }
    }

    return this->operator()(copy,b);


}