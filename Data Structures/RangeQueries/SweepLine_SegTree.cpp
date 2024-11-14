// reference: https://www.acmicpc.net/source/31632142
template<class T>
struct SweepLine{
    const vector<T>& c;
    unsigned n;
    struct Node{
        int cover;
        T sum;
    };
    vector<Node> tree;
    SweepLine(const vector<T>& compressed): c(compressed), n(size(c)-1), tree(bit_ceil(n)<<1){}
    // [l, r), [s, e)
    void upd(int l, int r, int x, int nd = 1, int s = 0, int e = -1){
        if(e == -1) e = n;
        if(e <= l or r <= s) return;
        if(l <= s and e <= r){
            tree[nd].cover += x;
        }else{
            int mid = midpoint(s, e);
            upd(l, r, x, nd << 1, s, mid);
            upd(l, r, x, nd << 1 | 1, mid, e);
        }
        if(tree[nd].cover > 0) tree[nd].sum = c[e] - c[s];
        else tree[nd].sum = e - s > 1 ? tree[nd<<1].sum + tree[nd<<1|1].sum : 0;
    }
    int qry_all(){return tree[1].sum;}
    // [l, r), [s, e)
    int qry(int l, int r, int nd = 1, int s = 0, int e = -1){
        if(e == -1) e = n;
        if(e <= l or r <= s) return 0;
        if(l <= s and e <= r) return tree[nd].sum;
        if(tree[nd].cover > 0){
            int lo = max(l, s), hi = min(r, e);
            return c[hi] - c[lo];
        }
        int mid = midpoint(s, e);
        return qry(l, r, nd << 1, s, mid) + qry(l, r, nd << 1 | 1, mid, e);
    }
};