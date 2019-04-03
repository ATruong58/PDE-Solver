//Guassian Elimnation
template <typename T>
myvector<T> Gaussian_solver::operator()(const denseMatrix<T>& set, const myvector<T>& b)const
{
    int size = set.getColumnSize();
    denseMatrix<T> aug_matrix(set.getColumnSize(),set.getRowSize()+1);
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
        double maxEl = fabs(matrix[i][i]/matrix[i].getmax());
        int maxRow = i;
        myvector<T> temp;

        for(int j = i+1; j < size; j++) 
        {
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
        x[i] = round(aug_matrix[i][size]/aug_matrix[i][i] *100000000.0) /100000000.0;
        
        for (int k = i-1 ; k >= 0; k--)
        {
            aug_matrix[k][size] -= aug_matrix[k][i] * x[i];
        }
    }

    return x;

}
