//Cholesky Algorithm for symmetricMatrix
template <typename T>
myvector<T> Cholesky_solver::operator()(const symmetricMatrix<T>& set, const myvector<T>& b)const
{
    if(set.getSize() == b.getSize())
    {   
        Gaussian_solver gs;
        int n = set.getSize();
        lowerMatrix<T> lower(n);
        myvector<T> y;
  
        for (int i = 0; i < n; i++) 
        { 
            for (int j = 0; j <= i; j++) 
            { 
                double sum = 0; 
    
                if (j == i)  
                { 
                    for (int k = 0; k < j; k++) 
                    {
                        sum += pow(lower(j,k), 2); 
                    }
                    lower(j,j) = sqrt(set(j,j) - sum); 
                } 
                else 
                {  
                    for (int k = 0; k < j; k++) 
                    {
                        sum += (lower(i,k) * lower(j,k)); 
                    }
                    lower(i,j) = (set(i,j) - sum) / lower(j,j); 
                } 
            } 
        } 
        
        y = gs(lower,b);
        return gs(lower.transpose(), y);
       
    }
    else
    {
        throw std::out_of_range("Size not equal");
    }
    
}