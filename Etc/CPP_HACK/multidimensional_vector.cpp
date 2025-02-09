/* How to Use
    Vec<4, int64_t> f(n, k, 2, 2, -3); // = f[n][k][2][2] initialized with -3
    Vec<2, int> adj(n); // graph, adjacent list with n vertices
    
    vector<int> dim = {1, 2, 3, 4, 5};
    Vec<5, int> vec(dim, -1); // = vec[1][2][3][4][5] initialized with -1

    vec.location_at({0, 0, 0, 1, 1}) returns  vec[0][0][0][1][1] as reference

    // global functions, apply to every element in vector
    Vec_for_each
    Vec_for_each_location
    Vec_accumulate
*/

using DimensionInfo = std::vector<size_t>;
template<size_t D, typename T>
struct Vec : public std::vector<Vec<D - 1, T>> {
    static_assert(D >= 2, "Dimension must be greater than 1");
    template <typename... Args>
    Vec(int n = 0, Args... args) : std::vector<Vec<D-1, T>>(n, Vec<D - 1, T>(args...)) {}
    Vec(const DimensionInfo &dim_v, T init = T()){
        assert(dim_v.size() >= D);
        size_t cur_dim = end(dim_v)[-D];
        std::vector<Vec<D - 1, T>>::operator=(
            std::move(std::vector<Vec<D - 1, T>>(cur_dim, Vec<D - 1, T>(dim_v, init)))
        );
    }
    T& location_at(const DimensionInfo &location){
        assert(location.size() >= D);
        size_t cur_loc = end(location)[-D];
        return ((*this)[cur_loc]).location_at(location);
    }
};

template <typename T>
struct Vec<1, T> : public std::vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
    Vec(const DimensionInfo &dim_v, T init = T()){
        assert(dim_v.size() >= 1);
        size_t cur_dim = end(dim_v)[-1];
        std::vector<T>::operator=(
            std::move(std::vector<T>(cur_dim, init))
        );
    }
    
    T& location_at(const DimensionInfo &location){
        assert(location.size() >= 1);
        size_t cur_loc = end(location)[-1];
        return ((*this)[cur_loc]);
    }

};

// f: T->void
template<size_t D, typename T>
void Vec_for_each(Vec<D, T>&v, auto&&f){
    for(auto&nv: v){
        if constexpr(D == 1) f(nv);
        else Vec_for_each<D-1, T>(nv, f);
    }
}

template<size_t D, typename T>
void Vec_for_each_location(Vec<D, T>&v, auto&&f){
    DimensionInfo location(D);
    return _Vec_for_each_location<D, T>(v, location, f);
}
// f:T, Coor->void
template<size_t D, typename T>
void _Vec_for_each_location(Vec<D, T>&v, DimensionInfo &location, auto&&f){
    assert(location.size() >= D);
    for(int i = 0; i < v.size(); i++){
        if constexpr(D == 1){
            end(location)[-D] = i;
            f(v[i], location);
        }else{
            end(location)[-D] = i;
            _Vec_for_each_location<D-1, T>(v[i], location, f);
        }
    }
}
// f:T, Coor->T
template<size_t D, typename T>
T Vec_accumulate(const Vec<D,T>&v, auto&&f){
    T res{};
    for(auto&nv: v){
        if constexpr(D == 1) res += f(nv);
        else res += Vec_accumulate<D-1, T>(nv, f);
    }
    return res;
}
