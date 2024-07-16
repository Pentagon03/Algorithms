#include"bits/stdc++.h"
// put headers before define
// g++ -std=c++20 -D LOCAL
#ifdef LOCAL
#include<Pentagon03/debug.h>
#else
#define dbg(...) 
#define dbgArr(...)
#endif

#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
template<typename T> istream& operator>> (istream&in, vector<T>&v){for(auto&x:v)in>>x; return in;}
template<typename T> T randint(T l, T r) {static std::mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); std::uniform_int_distribution<T> dist(l, r); return dist(gen);}
#define all(v) (v).begin(),(v).end()
#define setarr(A, x) memset(A, x, sizeof A)
#define nl '\n'
#define sp ' '
#define int int64_t
using ll = int64_t; using ld = long double; using pii = pair<int,int>; int cur_tc;


int32_t main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios::badbit | ios::failbit);
    // cout<<fixed<<setprecision(15);
    int tc = 1;
    cin >> tc;
    auto solve_tc = [&](){
        
    };
    for(cur_tc=1;cur_tc<=tc;cur_tc++) solve_tc();
    return 0;
}