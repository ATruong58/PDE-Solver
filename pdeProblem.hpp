template<typename T, typename U, typename V, typename W, typename A, typename B, typename C, typename D, typename E>
pdeProblem<T,U,V,W,A,B,C,D,E>::pdeProblem(U (*down)(T), W (*up)(V), B (*leftF)(A), D (*rightF)(C), E upBound)
{
    lower = down;
    upper = up;
    left = leftF;
    right = rightF;
    upperBound = upBound;
}
