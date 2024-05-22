/*
Basic Merge Sort Tree
*/
struct MergeSortTree{
    int n; 
    vector<vector<int>> tree;
    MergeSortTree(int k = 0){
        n = k;
        int st = 1; while(st < n) st <<= 1;
        tree.resize(st<<1);
    }
    MergeSortTree(const vector<int>&v){
        *this = MergeSortTree(v.size());
        init(v, 1, 0, n-1);
    }
    void init(const vector<int>&v,int nd,int s,int e){
        if(e==s){
            tree[nd].push_back(v[s]);
            return;
        }
        int m = s + e >> 1;
        init(v,nd<<1,s,m); init(v,nd<<1|1,m+1,e);
        merge(all(tree[nd<<1]),all(tree[nd<<1|1]),back_inserter(tree[nd]));
    }
    // [a,b] in nd
    inline int count(int nd, int a, int b){
        return upper_bound(all(tree[nd]),b) - lower_bound(all(tree[nd]),a);
    }
    int query(int k,int a,int b){return query(k,a,b,1,0,n-1);}
    int query(int k,int a,int b,int nd,int s,int e){
        if(e==s) return s;
        int cnt = count(nd<<1, a, b);
        int m = s + e >> 1;
        if(cnt >= k) return query(k,a,b,nd<<1,s,m);
        else return query(k-cnt,a,b,nd<<1|1,m+1,e);
    }
};