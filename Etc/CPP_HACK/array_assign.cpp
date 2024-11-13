// assign(array/vector, Dim1, ..., DimK, value)
void assign(auto&A, auto n, auto...v){
    if constexpr(sizeof...(v) == 0) A = n;
    else for(int i=0;i<n;i++) assign(A[i], v...);
}