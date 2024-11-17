// source: https://judge.yosupo.jp/submission/172003
// 1<<LG is bucket size, IS = Insert Order, LG heavily depends on situation
// use custom_hash for other data structures
// let (x, y) => (a, b) hash results. we combine them by => (a ^ (b>>1))
using u64 = uint64_t;
template <typename K = u64, typename V = int, int LG = 22, bool KEEP_IS = false>
struct HashMap {
    static const u64 FIXED_RANDOM;
    static constexpr int N = 1 << LG;
    u64* key = new u64[N];
    V* val = new V[N];
    vector<int> IS;
    std::bitset<N> vis;
    static uint32_t hash(u64 x) { return (u64(x + FIXED_RANDOM) * 11995408973635179863ULL) >> (64 - LG); }
    static uint32_t hash(pair<u64, u64> x){
        return (hash(x.first) ^ (hash(x.second) >> 1));
    }
    int index(K k) const {
        int i = hash(k);
        while (vis[i] && key[i] != k)
            i = (i + 1) & (N - 1);
        return i;
    }
    V& operator[](K k) {
        int i = index(k);
        if (!vis[i]) {
            vis[i] = true;
            key[i] = k;
            val[i] = {};
            if constexpr (KEEP_IS)
                IS.emplace_back(i);
        }
        return val[i];
    }
    V get(K k, V d = {}) const {
        int i = index(k);
        return vis[i] ? val[i] : d;
    }
    bool contains(K k) const {
        int i = index(k);
        return vis[i] and key[i] == k;
    }
    void clear() {
        vis.reset();
        if constexpr (KEEP_IS)
            IS.clear();
    }
    void enumerate(auto&& f) const {
        static_assert(KEEP_IS);
        for(auto i: IS)
            f(key[i], val[i]);
    }
    ~HashMap() {
        delete[] key;
        delete[] val;
    }
};
template <typename K, typename V, int LG, bool KEEP_IS>
const u64 HashMap<K, V, LG, KEEP_IS>::FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();