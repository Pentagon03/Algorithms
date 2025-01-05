// https://github.com/Pentagon03/Algorithms
#pragma GCC optimize("Ofast", "unroll-loops")
// #pragma GCC target("avx2", "popcnt")
#include"bits/stdc++.h"
// ext headers here: ext/pb_ds/assoc_container.hpp, tr2/dynamic_bitset
using namespace std;
// istringstream iss(s = "1 2 3 4 5"); // iss >> x;
template<typename T> istream& operator>> (istream&in, vector<T>&v){for(auto&x:v)in>>x; return in;}
template<typename T> ostream& operator<< (ostream&out, vector<T>&v){for(auto&x:v)out<<x<<' '; return out;}
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
template<int SZ> using ia = array<int, SZ>;
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