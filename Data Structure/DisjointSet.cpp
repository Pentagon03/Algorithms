struct DisjointSet{
    int n;
    vector<int> par; // negative: size of set, otherwise: parent
    // additional info here
    DisjointSet(int _n = 0) : n(_n), par(_n, -1) {}
    void make_leader(int u){par[u] = -1;}
    int leader(int u) {
        assert(0 <= u and u < n);
        // return par[u] < 0 : u : leader(par[u]); // no path compression
        return par[u] < 0 ? u : par[u] = leader(par[u]);
    }
    bool merge(int u, int v) {
        u = leader(u); v = leader(v);
        if (u == v) return false;
        if ((-par[u]) < (-par[v])) swap(u, v); // make sz[u] >= sz[v]
        // S.push_back({u, v, par[v]}); // rollback info
        par[u] += par[v];
        par[v] = u;
        // do smth here
        return true;
    }
    bool same(int u, int v) {
        return leader(u) == leader(v);
    }
    int size(int u){
        return -par[leader(u)];
    }
    // don't do this with make_leader, or it will be bugged.
    vector<vector<int>> groups(){
        vector res(n, vector<int>());
        for(int i=0;i<n;i++)
            if(par[i] < 0)
                res[i].reserve(-par[i]);
        for(int i=0;i<n;i++)
            res[leader(i)].push_back(i);
        erase_if(res, [](vector<int>&v){return empty(v);});
        return res;
    }

    // vector<array<int, 3>> S; // rollback stack
    // void rollback(int cnt = 1){
    //     for(int i=0;i<cnt;i++){
    //         assert(not empty(S));
    //         auto [u,v,psz] = S.back(); S.pop_back();
    //         par[u] -= psz; par[v] = psz;
    //     }
    // }
};