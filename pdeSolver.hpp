//Solve the pde
template<typename T, typename U, typename V,  typename W,  typename A,  typename B,  typename C,  typename D,  typename E, typename F>
myvector<T> pdeSolver::operator()(pdeProblem<T,U,V,W,A,B,C,D,E> &P, int n, F method)
{
    double stepSize = (1.0 / 4) * -1.0;
    int size = (n-1) * (n-1);
    symmetricMatrix<T> a_matrix(size);
    myvector<T> b_vector(size);
    int countleft = 2;
    int countright = 2;
    

    for(int i = 0; i < size; i++)
    {
        a_matrix(i,i) = 1;
        
        if(n+i <= size)
        {
            a_matrix(i,n+i-1) = stepSize;
        }
        if((i + 1) % (n - 1) != 0 && i+1 < size)
        {
            a_matrix(i,i+1) = stepSize;
        }
    }

    for(int i = 0; i < size; i++)
    {
        //For bottom left point
        if(i == 0)
        {
            b_vector[i] = (P.left(P.upperBound/n) / 4) + (P.lower(P.upperBound/n) / 4);
        }
        //For bottom right point
        else if(i == n-2 )
        {
            b_vector[i] = (P.right(P.upperBound/n) / 4) + (P.lower(P.upperBound/n) / 4);
        }
        //For top left point
        else if(i == size-n+1)
        {
             b_vector[i] = (P.left(P.upperBound/n) / 4) + (P.upper(P.upperBound/n) / 4);
        }
        //For top right point
        else if(i == size-1)
        {
             b_vector[i] = (P.right(P.upperBound/n) / 4) + (P.upper(P.upperBound/n) / 4);
        }
        //For points on the bottom row that isnt a corner
        else if(i > 0 && i < n - 1)
        {
            b_vector[i] = P.lower(((i+1) * P.upperBound) / n)/ 4;
        }
        //For points on the left row that isnt a corner
        else if( i >= (n - 1) && i % (n - 1) == 0)
        {
            b_vector[i] = P.left((countleft * P.upperBound) / n ) / 4;
            countleft++;
        }
        //For points on the right row that isnt a corner
        else if( i >= (n-1) && (i + n - 1 ) % (n - 1) == 0)
        {
            b_vector[i] = P.right((countright * P.upperBound) / n ) / 4;
            countright++;
        } 
        //For points on the top row that isnt a corner
        else if(i > size - n + 1)
        {
            b_vector[i] = P.upper(((i-size+ n -1) * P.upperBound) / n)/ 4;
        }
    }


    return method(a_matrix, b_vector);
}