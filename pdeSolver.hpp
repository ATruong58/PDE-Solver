template<typename T, typename U>
myvector<T> pdeSolver<T,U>::operator()(pdeProblem<T,U> &P, int n)
{

    double stepSize = (1.0 / n) * -1.0;
    int size = pow(n-1,2);
    symmetricMatrix<T> a_matrix(size);
    myvector<T> b_vector(size);
    int count = 2;

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
        if(i == 0)
        {
            b_vector[i] = 2 * P(M_PI/n);
        }
        else if(i > 0 && i < n - 1)
        {
            b_vector[i] = P(((i+1) * M_PI) / n);
        }
        else if( i >= (n - 1) && i % (n - 1) == 0)
        {
            b_vector[i] = P((count * M_PI) / n );
            count++;
        }
        else
        {
            b_vector[i] = 0;
        }
    }
    std::cout << b_vector << std::endl; 



    myvector<T> hello(3);
    return hello; 
}