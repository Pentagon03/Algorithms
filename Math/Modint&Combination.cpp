/*
Modint Implementation and Combination
Reference: https://codeforces.com/blog/entry/127439 Problem E
*/
template<class T>
constexpr T power(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
template<int P>
struct Mint {
    int x;
    constexpr Mint() : x{} {}
    constexpr Mint(ll x) : x{norm(x % P)} {}
    
    constexpr int norm(int x) const {
        if (x < 0) x += P;
        if (x >= P) x -= P;
        return x;
    }
    constexpr int val() const {return x;}
    explicit constexpr operator int() const {return x;}
    constexpr Mint operator-() const {
        Mint res;
        res.x = norm(P - x);
        return res;
    }
    constexpr Mint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    constexpr Mint &operator*=(Mint rhs) {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    constexpr Mint &operator+=(Mint rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr Mint &operator-=(Mint rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr Mint &operator/=(Mint rhs) {
        return *this *= rhs.inv();
    }
    friend constexpr Mint operator*(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr Mint operator+(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr Mint operator-(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr Mint operator/(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, Mint &a) {
        ll v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(Mint lhs, Mint rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(Mint lhs, Mint rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<int P>
struct comb {
    using Z = Mint<P>;
    int n = 0;
    std::vector<Z> _fac = {1};
    std::vector<Z> _invfac = {1};
    std::vector<Z> _inv = {0};
    
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    int fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m].val();
    }
    int invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m].val();
    }
    int inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m].val();
    }
    int binom(int m, int k) {
        if (m < k || k < 0) return 0;
        return (Z(fac(m)) * invfac(k) * invfac(m - k)).val();
    }
};
