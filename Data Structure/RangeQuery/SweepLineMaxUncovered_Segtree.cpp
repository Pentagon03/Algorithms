template<typename T>
struct SweepLineMaxUncovered{
    int n;
    struct Node{
        int cover;
        T len, mx, lmx, rmx;
        void init(bool covered){mx = lmx = rmx = (covered ? 0 : len);}
        friend Node operator +(Node a, Node b){
            return Node{
                0,
                a.len + b.len,
                max({a.mx, b.mx, a.rmx + b.lmx}),
                a.lmx != a.len ? a.lmx : a.len + b.lmx,
                b.rmx != b.len ? b.rmx : b.len + a.rmx,
            };
        }
    };
    static constexpr Node enode = Node{0, 0, 0, 0, 0};
    vector<Node> tree;
    // [0, n)
    SweepLineMaxUncovered(int n){
        vector<T> c(n+1); iota(begin(c), end(c), 0);
        *this = SweepLineMaxUncovered(c);
    }
    SweepLineMaxUncovered(const vector<T>& compressed){
        n = ssize(compressed) - 1;
        assert(n >= 1);
        int size  = bit_ceil((unsigned)n);
        tree.assign(size << 1, enode);
        build(compressed);
    }
    void build(const vector<T> & c, int nd = 1, int s = 0, int e = -1){
        if(e == -1) e = n;
        int len = c[e] - c[s];
        tree[nd] = {0, len, len, len, len};
        if(e - s > 1){
            int mid = midpoint(s, e);
            build(c, nd << 1, s, mid); build(c, nd << 1 | 1, mid, e);
        }
    }
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
        if(tree[nd].cover > 0) tree[nd].init(true);
        else{
            if(e - s > 1) tree[nd] = tree[nd << 1] + tree[nd << 1 | 1];
            else tree[nd].init(false);
        }
    }
    Node qry_all(){return tree[1];}
    // [l, r), [s, e)
    Node qry(int l, int r, int nd = 1, int s = 0, int e = -1){
        if(e == -1) e = n;
        if(e <= l or r <= s) return enode;
        if(l <= s and e <= r) return tree[nd];
        int mid = midpoint(s, e);
        Node ans = qry(l, r, nd << 1, s, mid) + qry(l, r, nd << 1 | 1, mid, e);
        if(tree[nd].cover > 0) ans.init(true);
        return ans;
    }
};