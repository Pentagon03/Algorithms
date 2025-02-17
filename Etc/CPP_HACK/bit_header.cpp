#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
// #define int ll
using u32 = uint32_t;

/*
- uint32_t n에 대해 생각.
- n 이상의 최소 2의 거듭제곱: bit_ceil(n)
- n 이하의 최대 2의 거듭제곱: bit_floor(n)
- log2(n)을 구하고 싶은 경우: bit_width(n) - 1 (n = 0의 경우 -1이 된다)  (or) __lg(n)
- 2의 거듭제곱인지 확인하고 싶은 경우: has_single_bit(n)
- 켜진 비트의 개수: popcount(n)
- 가장 작은 켜진 비트 : countr_zero(n)
- 가장 큰 켜진 비트 : bit_width(n) - 1 (or) countl_zero(0ULL) - countl_zero(n) - 1
*/
void solve(int cur_tc){
    using bset = bitset<5>;
    for(auto i{0};i<=0B1111;i++){
        cout << "i = " << i << " = " << bset(i) << '\n';
        // rotl
        cout << "rotl 1: " << bset(rotl((u32)i, 1)) << '\n'; 
        // rotr
        cout << "rotr 1: " << bset(rotr((u32)i, 1)) << '\n';

        // bit_width (이 수를 표현하기 위한 최소 너비)
        cout << "bit_width: " << bit_width((u32)i) << '\n';
        // popcount (1의 개수)
        cout << "popcount: " << popcount((u32)i) << '\n';

        // has_single_bit (2의 거듭제곱인지 검사)
        cout << "has_single_bit: " << has_single_bit((u32)i) << '\n';
        // bit_ceil (N 이상의 최소 2의 거듭제곱)
        cout << "bit_ceil: " << bit_ceil((u32)i) << '\n';
        // bit_floor (N 이하의 최대 2의 거듭제곱)
        cout << "bit_floor: " << bit_floor((u32)i) << '\n';
        
        // countl_zero (clz)
        cout << "countl_zero: " << countl_zero((u32)i) << '\n';
        // countl_one
        cout << "countl_one: " << countl_one((u32)i) << '\n';
        // countr_zero (crz)
        cout << "countr_zero: " << countr_zero((u32)i) << '\n';
        // countr_one
        cout << "countr_one: " << countr_one((u32)i) << '\n';
        
        cout << '\n';
    }
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++) solve(i);
}
