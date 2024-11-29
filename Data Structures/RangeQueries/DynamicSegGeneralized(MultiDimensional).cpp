/*
# Dynamic Seg Generalized<Range, S> (Point Update)
- `void upd(point, unary function(S&x), combine function(S&x, S&l, S&r))`
- `V qry(point, unary function(S&x), fold function(V x, S&x), V init)`
- ex) 2D Dynamic Seg (Point set, Range gcd) 
- https://www.acmicpc.net/source/share/a89464037ad243afa3dca9ddfc5aedd7
*/
template<   class Range,
            class S>
struct DynamicSeg{
    static constexpr Range NIL = numeric_limits<Range>::max();
    struct Node{
        S value;
        Range only;
        Node *l, *r;
        Node(S val, Range only = NIL): value(val), only(only), l(NULL), r(NULL){}
    };
    inline Node* make(S val, Range only = NIL){
        Node *nd = new Node(val, only);
        return nd;
    }
    Range L, R;
    Node *root;
    S eval;
    DynamicSeg() = default;
    explicit DynamicSeg(Range l, Range r, S ev):L(l), R(r), eval(ev){
        root = make(eval);
    }
    DynamicSeg& operator=(const DynamicSeg& rht) {
        L = rht.L; R = rht.R; eval = rht.eval;
        root = copydfs(rht, rht.root);
        return *this;
    }
    DynamicSeg(const DynamicSeg& rht){
        *this = rht;
    }
    Node* copydfs(const DynamicSeg& rht, Node*rnd){
        if(not rnd) return NULL;
        Node* nd = make(rnd->value, rnd->only);
        nd->l = copydfs(rht, rnd->l);
        nd->r = copydfs(rht, rnd->r);
        return nd;
    }
    // unary(A[x])
    template<class U, class C>
    void upd(Range i, U &&unary, C &&combine){
        assert(L <= i and i <= R);
        upd(i, unary, combine, root, L, R);
    }
    // fold(init, A[l]) ... r
    template<class U, class C, class V>
    V qry(Range l, Range r, U &&unary, C &&fold, V init) const{
        // assert(l <= r);
        if(l > r) return init;
        if(r < L or R < l) return init;
        l = clamp(l, L, R); r = clamp(r, L, R);
        return qry(l, r, unary, fold, init, root, L, R);
    }
    template<class U>
    auto qry_all(U &&unary) const{
        return unary(root->value);
    }
    // r such that fold(A[0]...A[r-1]) = true, op(A[0]...A[r]) = false. a.k.a first false
    template<typename G, class C, class V>
    Range partition_point(G &&g, C &&fold, V init){
        if(not g(init)) return L;
        V allval = fold(init, root->value);
        if(g(allval)) return R + 1;
        return partition_point(g, fold, init, root, L, R);
    }
    template<class U, class C>
    void upd(Range i, U &&unary, C &&combine, Node *nd, Range ns, Range ne){
        assert(nd);
        if(ns == ne or nd->only == i){
            assert(ns <= i and i <= ne);
            unary(nd->value);
            return;
        }
        Range nm = midpoint(ns, ne);
        if(nd->only != NIL){
            auto &ch = (nd->only <= nm) ? nd->l : nd->r;
            assert(not ch);
            ch = make(nd->value, nd->only);
            nd->only = NIL;
        }
        if(i <= nm){
            if(not nd->l){
                nd->l = make(eval, i);
                unary(nd->l->value);
            }else{
                upd(i, unary, combine, nd->l, ns, nm);
            }
        }else{
            if(not nd->r){
                nd->r = make(eval, i);
                unary(nd->r->value);
            }else{
                upd(i, unary, combine, nd->r, nm+1, ne);
            }
        }
        assert(nd->l or nd->r);
        combine(nd->value, nd->l ? nd->l->value : eval, nd->r ? nd->r->value : eval);
    }
    template<class U, class C, class V>
    V qry(Range l, Range r, U &&unary, C &&fold, V init, Node *nd, Range ns, Range ne) const{
        assert(nd);
        if(r < ns or ne < l) return init;
        if(l <= ns and ne <= r) return unary(nd->value);
        if(nd->only != NIL){
            if(l <= nd->only and nd->only <= r) return unary(nd->value);
            else return init;
        }
        Range nm = midpoint(ns, ne);
        V ans = init;
        if(nd->l) ans = fold(ans, qry(l, r, unary, fold, init, nd->l, ns, nm));
        if(nd->r) ans = fold(ans, qry(l, r, unary, fold, init, nd->r, nm+1, ne));
        return ans;
    }
    template<typename G, class C, class V>
    Range partition_point(G &&g, C &&fold, V val, Node* nd, Range ns, Range ne){
        assert(nd);
        assert(g(val));
        if(ns == ne) return ns;
        if(nd->only != NIL){
            V nval = fold(val, nd->value);
            assert(not(g(nval)));
            return nd->only;
        }
        assert(nd->l or nd->r);
        Range nm = midpoint(ns, ne);
        if(not nd->l) return partition_point(g, fold, val, nd->r, nm+1, ne);
        assert(nd->l);
        V lval = fold(val, nd->l->value);
        if(not g(lval)) return partition_point(g, fold, val, nd->l, ns, nm);
        assert(nd->r);
        return partition_point(g, fold, lval, nd->r, nm+1, ne);
    }
    void deldfs(Node *nd){
        if(not nd) return;
        deldfs(nd->l); deldfs(nd->r);
        delete nd;
    }
    ~DynamicSeg(){
        deldfs(root);
    }
};