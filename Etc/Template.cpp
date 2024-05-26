#define LLHACK
/*Solution
https://acmicpc.net/problem/Template
1. 문제부터 정확히 읽는다.
2. 안 풀리면 naive 풀이 짜고 관찰한다.
3. 구현 틀렸으면 stress test 짠다.
화이팅
*/
#pragma GCC optimize("Ofast,unroll-loops")
#include"bits/stdc++.h"
using namespace std;
int cur_tc;
#define nl '\n'
#define sp ' '
#define dbg(i) cerr<<#i<<sp<<i<<endl
#define dbgs(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(),(v).end()
using ld = long double;
using ll = long long;
#ifdef LLHACK
#define int ll
#endif
using pii = pair<int,int>;
// __builtin_ctzll(x), __builtin_clzll(x), __builtin_popcountll(x)
int lsb(int x){return x>0?__builtin_ctz(x):-1;}
int msb(int x){return x>0?31-__builtin_clz(x):-1;}
int popcnt(int x){return __builtin_popcount(x);}
std::mt19937_64 gen(time(NULL));
ll randint(ll l, ll r) { std::uniform_int_distribution<ll> dist(l, r); return dist(gen);}
template<class T1,class T2>bool updmax(T1&l,T2 r){return (l<r?(l=r),true: false);}
template<class T1,class T2>bool updmin(T1&l,T2 r){return (l>r?(l=r),true: false);}
const int inf = (int)1e9 + 7;
const ll linf = (ll)4e18 + 7;

const int N = 7 + 1e5, mod = (int)1e9 + 7;
/*요약

*/
void _main(){
    
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);
    // cout<<fixed<<setprecision(15);
    int tc = 1;
    // cin >> tc;
    for(cur_tc=1;cur_tc<=tc;++cur_tc) _main();
    return 0;
}