#ifndef ONLINE_JUDGE
#define Pentagon03
#include<Pentagon03/debug.h>
#else
#define dbg(...) 
#define dbgArr(...)
#endif

#pragma GCC optimize("Ofast,unroll-loops")
#include"bits/stdc++.h"
using namespace std;
using ll = int64_t; using ld = long double; int cur_tc;
template<typename T> istream& operator>> (istream&in, vector<T>&v){for(auto&x:v)in>>x; return in;}
template<typename T> T randint(T l, T r) {static std::mt19937_64 gen(time(NULL)); std::uniform_int_distribution<T> dist(l, r); return dist(gen);}
#define ALL(v) (v).begin(),(v).end()
#define INIT(v, x) memset(v, x, sizeof v)
#define nl '\n'
#define sp ' '
#define int ll
using pii = pair<int,int>;


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