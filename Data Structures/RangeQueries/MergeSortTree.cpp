template<typename T = int>
struct MergeSortTree{
    using Vec = vector<T>;
    int n, base;
    vector<Vec> tree;
    MergeSortTree(){}
    MergeSortTree(const Vec& v){
        n = v.size();
        base = 1 << __lg(n-1) + 1;
        tree.resize(base<<1);
        for(int i=0;i<n;i++)
            tree[base+i] = {v[i]};
        for(int i=base-1;i>=1;i--)
            merge(all(tree[i<<1]),all(tree[i<<1|1]),back_inserter(tree[i]));
    }
    int elem(int k){
        assert(0 <= k and k < n);
        return tree[base+k][0];
    }
    /* op is an operation to a vector
    ex) cnt_qry(0, n-1, [&](const vec& v){return f.less(v, x);})
    */
    // O(log n * T(op))
    int cnt_qry(int l,int r,const function<int(const Vec&)>& op){
        int ans = 0;
        l+=base; r+=base;
        while(l<=r){
            if(l&1) ans += op(tree[l++]);
            if(~r&1) ans += op(tree[r--]);
            l>>=1; r>>=1;
        }
        return ans;
    }   
    // max t that op([l, t]) <= k.  O(log^2 n * T(op))
    int rightmost(int l, int k, const function<int(const Vec&)>& op){
        if(k < 0) return l - 1;
        int lo = l, hi = n, mid;
        while(lo+1<hi) cnt_qry(l, mid = lo + hi >> 1, op) <= k ? lo = mid : hi = mid; 
        return lo;
    }
    // min t that op([t, r], x) <= k. O(log^2 n * T(op))
    int leftmost(int r, int k, const function<int(const Vec&)>& op){
        if(k < 0) return r+1;
        int lo = -1, hi = r, mid;
        while(lo+1<hi) cnt_qry(mid = lo + hi >> 1, r, op) <= k ? hi = mid : lo = mid;
        return hi;
    }
    static inline int greater(const Vec&v, int x){
        return v.end() - upper_bound(all(v), x);
    }
    static inline int less(const Vec&v, int x){
        return lower_bound(all(v), x) - v.begin();
    }
    static inline int greater_equal(const Vec&v, int x){
        return v.size() - less(v, x); 
    }
    static inline int less_equal(const Vec&v,  int x){
        return v.size() - greater(v, x);
    }
    static inline int in_range(const Vec&v,  int x, int y){
        if(x > y) return 0;
        return upper_bound(all(v), y) - lower_bound(all(v), x);
    }
    static inline int equal(const Vec&v, int x){
        return in_range(v, x, x);
    }
};