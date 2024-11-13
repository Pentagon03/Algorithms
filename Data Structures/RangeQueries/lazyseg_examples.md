# Lazy Segtree
- put 'fail' information for Segment Tree Beats
- S: monoid for tree
- S op(S a, S b): monoid action
- S e() : identity of S
- F: mapping function
- S mapping(F f, S x) : f(x)
- F composition(F f, F g): f(g(x)) -> h(x)
- F id(): identity of f

## Example 1
```cpp
// S: range sum, F: range add
struct S{
    ll sum;
    int cnt;
};
S op(S a, S b){return {
    a.sum + b.sum,
    a.cnt + b.cnt
};};
S e(){return {0, 0};}
using F = ll; // add f
// f(x)
S mapping(F f, S x){return {x.sum + x.cnt * f, x.cnt};}
// f(g(x))
F composition(F f, F g){return g + f;}
F id(){return 0;}
```

## Example 2
```cpp
// S : range max, F : range add
using S = int; // max
constexpr S MIN = numeric_limits<S>::min() / 2; 
S op(S a, S b){return max(a, b);}
S e(){return MIN;}
using F = int; // add
// f(x)
S mapping(F f, S x){return x + f;}
// f(g(x))
F composition(F f, F g){return g + f;}
F id(){return 0;}
```

## Example 3
```cpp
// S : range add, F : range mul, add, set 
// https://www.acmicpc.net/problem/13925
constexpr int MOD = (int)1e9 + 7;
struct S{
    int sum;
    int cnt;
};
int add(int a,int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}
int mul(int a,int b){
    return 1LL * a * b % MOD;
}
S op(S a, S b){
    return {add(a.sum, b.sum), a.cnt + b.cnt};
}
S e(){return {0, 0};}

struct F{
    int mul, add;
};
S mapping(F f, S x){
    if(!x.cnt) return e();
    return {add(mul(x.sum, f.mul), mul(x.cnt, f.add)), x.cnt};
}
F composition(F f, F g){
    return F{
        mul(g.mul, f.mul),
        add(mul(g.add, f.mul), f.add)
    };
}
F id(){
    return F{
        1,
        0
    };
}
```

