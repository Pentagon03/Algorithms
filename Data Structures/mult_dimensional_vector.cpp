// source: somewhere from codeforces

struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};

template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};

/* Example
    Vec<4, int64_t> f(n, k, 2, 2); // = f[n][k][2][2];
    Vec<2, int> adj(n); // graph
*/

/** Multidimensional Vector
 * modified, source: https://judge.yosupo.jp/submission/172003
 * usage: vector(D1, D2, ... , Initial Value)
 */
auto vec(int n, auto&&... s) {
    static_assert(sizeof...(s) >= 1 and "last parameter should be initial value");
    if constexpr (sizeof...(s) == 1) return vector (n, s...);
    else return vector (n, vec(s...));
}

