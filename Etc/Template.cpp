#pragma GCC optimize("Ofast,unroll-loops")
#include"bits/stdc++.h"
using namespace std;
#define nl '\n'
#define sp ' '
#define all(v) (v).begin(),(v).end()
#define INIT(v, x) memset(v, x, sizeof v)
int _dbg, cur_tc;
#define dbg(i) if(!_dbg||_dbg==cur_tc) cerr << "Line(" << __LINE__ << ") -> " << #i << " = " << (i) << endl;
#define dbgs(...) if(!_dbg||_dbg==cur_tc)fprintf(stderr, __VA_ARGS__)
template<typename T> istream& operator>> (istream&in, vector<T>&v){for(auto&x:v)in>>x; return in;}
using ll = int64_t;
#define int ll

int32_t main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios::badbit | ios::failbit);
    // cout<<fixed<<setprecision(15);
    int tc = 1;
    // cin >> tc;
    auto solve_tc = [&](){
        
    };
    for(cur_tc=1;cur_tc<=tc;cur_tc++) solve_tc();
    return 0;
}