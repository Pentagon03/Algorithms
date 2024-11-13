# Lazy Segtree Tutorial
- S: monoid for tree
- S e() : identity of S
- S op(S a, S b): monoid action
- F: mapping function
- F id(): identity of f
- void mapping(F f, S&x) : x => f(x)
- void composition(F f, F&g): g(x) => f(g(x))
- (optional) `LazySeg<S, e, op, F, id, mapping, composition>`
- `upd(l, r, f) : i \in [l, r], A[i] => f(A[i])`
- `qry(l, r) : op(A[l], ... , A[r])`
- Tutorial(+Beats): https://github.com/Pentagon03/Algorithms/blob/master/Data%20Structures/RangeQueries/LazySeg_Tutorial.md

# SegTree Beats Tutorial
## mapping to try_mapping
- 1. add `bool fail` variable into `S`.
- 2. if mapping(F f, S x) can't be made, put `fail = true`, otherwise `fail = false`.
- 3. uncomment `if(tree[i].fail) push(i), pull(i);` in `apply` function.
## (optional) strengthened break condition
- put additional condition for returning `upd` function at the first.

# Examples
## Example 1
```cpp
// https://www.acmicpc.net/problem/10999
// S: range sum, F: range add
struct S{
    ll sum;
    int cnt;
};
constexpr S e(){return {0, 0};}
S op(S a, S b){return {
    a.sum + b.sum,
    a.cnt + b.cnt
};};
using F = ll; // add
constexpr F id(){return 0;}
// x = f(x)
void mapping(F f, S&x){x.sum += x.cnt * f;}
// g(x) = f(g(x))
void composition(F f, F&g){g += f;}
```

## Example 2
```cpp
// S : range max, F : range add
// https://www.acmicpc.net/problem/30857
using S = int; // max
constexpr S MIN = numeric_limits<S>::min() / 2; 
constexpr S e(){return MIN;}
S op(S a, S b){return max(a, b);}
using F = int; // add
// x => f(x)
constexpr F id(){return 0;}
void mapping(F f, S&x){x += f;}
// g(x) => f(g(x))
void composition(F f, F&g){g += f;}
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