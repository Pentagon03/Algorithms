# Lazy Segtree
- put 'fail' information for Segment Tree Beats
- S: monoid for tree
- S op(S a, S b): monoid action
- S e() : identity of S
- F: mapping function
- S mapping(F f, S x) : f(x)
- F composition(F f, F g): f(g(x)) -> h(x)
- F id(): identity of f

## Example 1: S: range sum, F: range add
```cpp
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

## Example 2: S : range max, F : range add
```cpp
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
