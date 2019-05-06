template<typename T, typename U>
myvector<T> pdeSolver<T,U>::operator()(pdeProblem<T,U> &P, int n)
{

    double stepSize = (1.0 / n) * -1.0;
    int size = pow(n-1,2);
    symmetricMatrix<T> a(size);
    std::cout<< 6 % 3 << std::endl;
    for(int i = 0; i < size; i++)
    {
        a(i,i) = 1;
        
        if(n+i <= size)
        {
            a(i,n+i-1) = stepSize;
        }
        if((i + 1) % (n - 1) != 0 && i+1 < size)
        {
            a(i,i+1) = stepSize;
        }
    }

    std::cout << a << std::endl; 



    myvector<T> hello(3);
    return hello; 
}