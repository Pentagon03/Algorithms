/*
# Dynamic Seg Generalized (Point Update)
ex) https://www.acmicpc.net/source/share/1049c3d8d92f4f348e28d8af4a10795a
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
    // f(A[x])
    template<class F, class C>
    void upd(Range i, F &&unary, C &&combine){
        upd(i, unary, combine, root, L, R);
    }
    // fold(init, A[l]) ... r
    template<class F, class C, class V>
    V qry(Range l, Range r, F &&unary, C &&fold, V init) const{
        return qry(l, r, unary, fold, init, root, L, R);
    }
    template<class F, class C>
    void upd(Range i, F &&unary, C &&combine, Node *nd, Range ns, Range ne){
        assert(nd);
        if(ns == ne or nd->only == i){
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
        combine(nd, nd->l, nd->r);
    }
    template<class F, class C, class V>
    V qry(Range l, Range r, F &&unary, C &&fold, V init, Node *nd, Range ns, Range ne) const{
        assert(nd);
        if(r < ns or ne < l) return init;
        if(l <= ns and ne <= r) return unary(nd->value);
        if(nd->only != NIL){
            if(l <= nd->only and nd->only <= r) return unary(nd->value);
            else return init;
        }
        auto nm = midpoint(ns, ne);
        V ans = init;
        if(nd->l) ans = fold(ans, qry(l, r, unary, fold, init, nd->l, ns, nm));
        if(nd->r) ans = fold(ans, qry(l, r, unary, fold, init, nd->r, nm+1, ne));
        return ans;
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