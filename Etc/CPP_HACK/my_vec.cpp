/** Multidimensional Vector
 * modified, source: https://judge.yosupo.jp/submission/172003
 * usage: auto V = vec(D1, D2, ... , Initial Value)
 */
auto vec(int n, auto&&... s) {
    static_assert(sizeof...(s) >= 1 and "last parameter should be initial value");
    if constexpr (sizeof...(s) == 1) return vector (n, s...);
    else return vector (n, vec(s...));
}
// array_assign.cpp
// append vector into vector
void append(auto&x, auto&&y){x.reserve(x.size()+y.size()), x.insert(x.end(), y.begin(), y.end());}
// add values into vector
void addv(auto&v, auto&&...x){(v.push_back(x),...);}