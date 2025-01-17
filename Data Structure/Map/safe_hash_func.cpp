// source: https://codeforces.com/blog/entry/62393

struct safe_hash {
    using u64 = uint64_t;
    static u64 splitmix64(u64 x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(u64 x) const {
        static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<u64, u64> x) const{
        return (*this)(x.first) ^ ((*this)(x.second) >> 1);
    }
};

// unordered_map<int64_t, int, safe_hash> safe_map;
// #include <ext/pb_ds/assoc_container.hpp>
// __gnu_pbds::gp_hash_table<int64_t, int, safe_hash> safe_hash_table;