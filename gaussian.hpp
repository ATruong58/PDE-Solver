//Guassian Elimnation for denseMatrix
template <typename T>
myvector<T> Gaussian_solver::operator()(const denseMatrix<T>& set, const myvector<T>& b)const
{
    int size = set.getColumnSize();
    denseMatrix<T> aug_matrix(set.getRowSize()+1);
    denseMatrix<T> matrix = set;
    
    //Make the augmented matrix
    for(int i = 0; i < set.getColumnSize(); i++)
    {
        for(int j = 0; j < set.getRowSize(); j++)
        {
            aug_matrix[i][j] = set[i][j];
        }
        
        aug_matrix[i][aug_matrix.getRowSize()-1] = b[i];
    }

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
        temp = aug_matrix[maxRow];
        aug_matrix[maxRow] = aug_matrix[i];
        aug_matrix[i] = temp;

        // Make all rows below this one 0 in current column
        for(int j = i+1; j < size; j++) 
        {
            if(aug_matrix[i][i] == 0)
            {
                throw std::out_of_range( "Dividing by zero");
            }
            double scale = -aug_matrix[j][i]/aug_matrix[i][i];
            for(int k = i; k < size+1; k++)
            {
                if(i==k)
                {
                    aug_matrix[j][k] = 0;
                } 
                else
                {
                    aug_matrix[j][k] += scale * aug_matrix[i][k];
                }
            }
        }
    }

    //Make the solution vector 
    for(int i = size-1; i >= 0; i--)
    {
        //round the number to 8 decimal place
        if(aug_matrix[i][i] == 0)
        {
            throw std::out_of_range( "Dividing by zero");
        }
        x[i] = round(aug_matrix[i][size]/aug_matrix[i][i] *100000000.0) /100000000.0;
        
        for (int k = i-1 ; k >= 0; k--)
        {
            aug_matrix[k][size] -= aug_matrix[k][i] * x[i];
        }
    }

    return x;

}

//Guassian Elimnation for upperMatrix
template <typename T>
myvector<T> Gaussian_solver::operator()(const upperMatrix<T>& set, const myvector<T>& b)const
{
    myvector<T> solution(set.getSize());

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

//Guassian Elimnation for lowerMatrix
template <typename T>
myvector<T> Gaussian_solver::operator()(const lowerMatrix<T>& set, const myvector<T>& b)const
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

