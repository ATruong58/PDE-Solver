template<typename T, typename U>
pdeProblem<T,U>::pdeProblem(U (*function)(T))
{
    func = function;
}

template<typename T, typename U>
U pdeProblem<T,U>::operator ()(const T& num)
{
    return func(num);
}