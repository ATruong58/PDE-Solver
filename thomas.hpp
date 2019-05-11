//Thomas Algorithm for tridiaognalMatrix
template <typename T>
myvector<T> Thomas_solver::operator()(const tridiagonalMatrix<T>& set, const myvector<T>& b)const
{
    if(set.getSize() == b.getSize())
    {   
        tridiagonalMatrix<T> duplicateM = set;
        myvector<T> duplicateV = b;
        myvector<T> solution(b.getSize());

        int iter = set.getSize() - 1;

        for(int i = 1; i < iter+1; i++)
        {
            duplicateM(i, i-1) = duplicateM(i, i-1) / duplicateM(i-1, i-1);
            duplicateM(i,i) = duplicateM(i,i) - duplicateM(i, i-1) * duplicateM(i-1, i); 
            duplicateV[i] = duplicateV[i] - duplicateM(i, i-1) * duplicateV[i-1];
        }

        solution[iter] = (duplicateV[iter] / duplicateM(iter,iter));

        for(int i = iter; i-- > 0;)
        {
            solution[i] = (duplicateV[i] - ((duplicateM(i,i+1) * solution[i+1]))) / duplicateM(i,i);
        }
        return solution;
    }
    else
    {
        throw std::out_of_range("Size not equal");
    }
    
}