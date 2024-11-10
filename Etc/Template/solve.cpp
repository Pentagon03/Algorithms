// https://github.com/Pentagon03/Algorithms
// g++ -std=c++20 -D _DEBUG
#ifdef _DEBUG
#define Pentagon03
#include<Pentagon03/debug.h>
#else
#define dbg(...)
#define dbgArr(...)
#endif
#pragma GCC optimize("Ofast", "unroll-loops")
// #pragma GCC target("avx2", "popcnt")
#include"bits/stdc++.h"
// ext headers here: ext/pb_ds/assoc_container.hpp, tr2/dynamic_bitset
using namespace std;
namespace R = std::ranges;
namespace V = std::ranges::views;
string input(char delim = '\n'){
    string t; getline(cin, t, delim);
    return move(t);
}
template<typename T> istream& operator>> (istream&in, vector<T>&v){for(auto&x:v)in>>x; return in;}
template<typename T> ostream& operator<< (ostream&out, vector<T>&v){for(auto&x:v)out<<x<<' '; return out;}
auto vec(int n, auto&&... s) {
    static_assert(sizeof...(s) >= 1 and "last parameter should be initial value");
    if constexpr (sizeof...(s) == 1) return vector (n, s...);
    else return vector (n, vec(s...));
}
void assign(auto&A, auto&&n, auto&&...v){
    if constexpr(sizeof...(v) == 0) A = n;
    else for(int i=0;i<n;i++) assign(A[i], v...);
}
void append(auto&x, auto&&y){x.reserve(x.size()+y.size()), x.insert(x.end(), y.begin(), y.end());}
void addv(auto&v, auto&&...x){(v.push_back(x),...);}
template<typename T> T randint(T l, T r) {static std::mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); return std::uniform_int_distribution<T>(l,r)(gen);}
#define all(v) (v).begin(),(v).end()
#define nl '\n'
#define sp ' '
#define rep(i, n) for(int i=0;i<(n);i++)
#define rep1(i, n) for(int i=1;i<=(n);i++)
#define repr(i, a, b) for(int i=(a);i<=(b);i++)
#define repd(i, b, a) for(int i=(b);i>=(a);i--)
#define int int64_t
using ll = int64_t; using pii = pair<int,int>; int cur_tc;
constexpr int inf = (int) 1e9 + 3; constexpr ll infl = (ll) 1e18 + 3;


int32_t main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios::badbit | ios::failbit);
    // cout<<fixed<<setprecision(15);
    int tc = 1;
    // cin >> tc;
    auto solve_tc = [&](){
        ${0}
    };
    for(cur_tc=1;cur_tc<=tc;cur_tc++) solve_tc();
    return 0;
}