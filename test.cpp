#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define int ll

namespace V = std::ranges::views;
void solve(int cur_tc){
    std::string s(10, '0');
    for (int i = 0; i < 10 / 2; ++i) s[i * 2] = '1';
    for (const auto word : V::split(s, '1'))
        std::cout << std::string_view(&*begin(word), std::ranges::distance(begin(word), end(word))) << ' ';
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++) solve(i);
}