/*
# Dynamic Lazy Segment Tree
- same convention with LazySeg
- Lazy Seg Tutorial: https://github.com/Pentagon03/Algorithms/blob/master/Data%20Structures/RangeQueries/LazySeg_Tutorial.md
- Beats is possible as always
- if you need index information, modify 'make` function to put info.
- Given Example is F: Range add, S: Range Sum.
- Dynamic seg(0, 1e9) for example.
*/

using Range = int;
// Example
// https://www.acmicpc.net/problem/20212
// Range: int, S: range sum, F: range add
struct S{
    ll sum;
    int len;
};
constexpr S e(){return {0, 0};}
S op(S a, S b){return {
    a.sum + b.sum,
    a.len + b.len,
};};
using F = ll; // add
constexpr F id(){return 0;}
// x = f(x)
void mapping(F f, S&x){x.sum += x.len * f;}
// g(x) = f(g(x))
void composition(F f, F&g){g += f;}


// template<   class Range, 
//             class S, S (*e)(),
//             S (*op)(S, S),
//             class F, F(*id)(),
//             void (*mapping)(F, S&),
//             void (*composition)(F, F&)>
struct DynamicLazySeg{
    public:
    struct Node{
        Range ns, ne;
        S value;
        F lz;
        Node *l, *r;
        Node(Range l, Range r): ns(l), ne(r), value(e()), lz(id()), l(NULL), r(NULL){}
    };
    inline Node* make(Range l, Range r){
        alloc.emplace_back(l, r);
        // example (range add, sum)
        alloc.back().value.len = r - l + 1;
        return &alloc.back();
    }
    // Node Range: ex) -inf, inf
    DynamicLazySeg(Range l, Range r){
        root = make(l, r);
    }

    // i \in [l, r], A[i] => f(A[i])
    void upd(int l, int r, F f, Node *nd = NULL){
        if(nd == NULL) nd = root;
        if(r < nd->ns or nd->ne < l) return;
        if(l <= nd->ns and nd->ne <= r){
            apply(nd, f);
            return;
        }
        push(nd);
        assert(nd -> l and nd -> r);
        upd(l, r, f, nd->l); upd(l, r, f, nd->r);
        pull(nd);
    }

    S qry(int l, int r, Node *nd = NULL){
        if(nd == NULL) nd = root;
        if(r < nd->ns or nd->ne < l) return e();
        if(l <= nd->ns and nd->ne <= r) return nd->value;
        push(nd);
        return op(qry(l, r, nd->l), qry(l, r, nd->r));
    }

    S qry_all(){ return root->value; }

    private:
    Node *root;
    deque<Node> alloc;
    void pull(Node*nd){
        // if we pushed appropriate
        assert(nd -> l and nd -> r);
        nd->value = op(nd->l->value, nd->r->value);
    }
    void apply(Node*nd, F f){
        if(f == id()) return;
        mapping(f, nd->value);
        if(nd->ns < nd->ne){
            composition(f, nd->lz);
            // if(nd->value.fail) push(nd), pull(nd); // SegTree Beats, add mapping fail info to 'S' (necessary)
        }
    }
    void push(Node*nd){
        // if(nd -> lz == id()) return;
        if(not nd->l) nd->l = make(nd->ns, midpoint(nd->ns, nd->ne));
        apply(nd->l, nd->lz);
        if(not nd->r) nd->r = make(midpoint(nd->ns, nd->ne) + 1, nd->ne);
        apply(nd->r, nd->lz);
        nd->lz = id();
    }
};