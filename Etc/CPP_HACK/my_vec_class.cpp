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
