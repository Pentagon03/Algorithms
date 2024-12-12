const int N = 1e5 + 3;
vector<int> g[N];
int par[N], sz[N], dep[N], h[N];
int in[N], out[N], cntr = 0, top[N];
void dfs_init(int x){
    sz[x] = 1;
    erase(g[x], par[x]);
    for(auto &y: g[x]){
        par[y] = x; 
        dep[y] = dep[x] + 1;
        dfs_init(y);
        if(sz[y] > sz[g[x][0]]) swap(y, g[x][0]);
        sz[x] += sz[y]; h[x] = max(h[x], h[y] + 1);
    }
}
void dfs_hld(int x){
    in[x] = cntr++;
    for(auto &y: g[x]){
        top[y] = (y == g[x][0] ? top[x] : y);
        dfs_hld(y);
    }
    out[x] = cntr;
}
int lca(int x,int y){
    if(x == y) return x;
    while(top[x] != top[y]){
        if(dep[top[x]] > dep[top[y]]) swap(x, y);
        int ctop = top[y];
        // y ~ ctop
        y = par[ctop];
    }
    if(dep[x] > dep[y]) swap(x, y);
    // y ~ x
    return x;
}
auto qry_path = [&](int x,int y,int op){
    ll ans = 0;
    if(x == y) return ans;
    auto upd = [&](int a, int b){
        // do_smth
    };
    while(top[x] != top[y]){
        if(dep[top[x]] > dep[top[y]]) swap(x, y);
        int ctop = top[y];
        upd(in[ctop], in[y]);
        y = par[ctop];
    }
    if(dep[x] > dep[y]) swap(x, y);
    if(x != y) upd(in[x] + 1, in[y]);
    return ans;
};