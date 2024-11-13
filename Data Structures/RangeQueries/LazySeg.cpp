/* Lazy Segtree
put 'fail' information for Segment Tree Beats
S: monoid for tree
S op(S a, S b): monoid action
S e() : identity of S
F: mapping function
S mapping(F f, S x) : f(x)
F composition(F f, F g): f(g(x)) -> h(x)
F id(): identity of f
See examples: https://github.com/Pentagon03/Algorithms/blob/master/Data%20Structures/RangeQueries/lazyseg_examples.md
*/

// S : range max, F : range add
using S = int; // max
constexpr S MIN = numeric_limits<S>::min() / 2; 
S op(S a, S b){return max(a, b);}
constexpr S e(){return MIN;}
using F = int; // add
// f(x)
S mapping(F f, S x){return x + f;}
// f(g(x))
F composition(F f, F g){return g + f;}
constexpr F id(){return 0;}

// template<   class S, S (*op)(S, S), S (*e)(),
//             class F, S (*mapping)(F, S),
//             F (*composition)(F, F), F(*id)()>
struct LazySeg{
    public:
    LazySeg(int n = 0) : LazySeg(vector(n, e())) {}
    LazySeg(const vector<S>& v){
        n = bit_ceil(size(v));
        tree = vector (n<<1, e());
        lz = vector (n, id());
        ranges::copy(v, begin(tree) + n);
        for(int i=n-1;i>=0;i--) pull(i);
    }
    // i \in [l, r] -> tree[i] = f(i)
    void upd(int l, int r, F f, int nd = 1, int ns = 0, int ne = -1){
        assert(0 <= l and l <= r and r <= n - 1);
        if(ne == -1) ne = n - 1;
        if(r < ns or ne < l) return;
        if(l <= ns and ne <= r){
            apply(nd, f);
            return;
        }
        push(nd); 
        int nm = midpoint(ns, ne);
        upd(l, r, f, nd << 1, ns, nm); upd(l, r, f, nd << 1 | 1, nm+1, ne);
        pull(nd);
    }
    S qry(int l, int r, int nd = 1, int ns = 0, int ne = -1){
        assert(0 <= l and l <= r and r <= n - 1);
        if(ne == -1) ne = n - 1;
        if(r < ns or ne < l) return e();
        if(l <= ns and ne <= r) return tree[nd];
        push(nd);
        int nm = midpoint(ns, ne);
        return op(qry(l, r, nd << 1, ns, nm), qry(l, r, nd << 1 | 1, nm+1, ne));
    }
    S qry_all(){ return tree[1]; }
    
    private:
    int n;
    vector<S> tree; vector<F> lz;
    void pull(int i){ tree[i] = op(tree[i<<1], tree[i<<1|1]);}
    void apply(int i, F f){
        tree[i] = mapping(f, tree[i]);
        if(i < n){
            lz[i] = composition(f, lz[i]);
            // if(tree[i].fail) push(i), pull(i); // SegTree Beats
        }
    }
    void push(int i){
        apply(i << 1, lz[i]);
        apply(i << 1 | 1, lz[i]);
        lz[i] = id();
    }
};