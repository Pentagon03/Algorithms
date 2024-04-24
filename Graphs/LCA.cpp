/*
provides bunch of good functions for LCA
*/
namespace LCA{
    const int MXH = 18;
    int par[MXH][N], dep[N];
    vector<int> g[N];
    void reset(int n){
        for(int i=0;i<=n;i++){
            dep[i] = 0;
            g[i].clear();
        }
        for(int b=0;(1<<b)<n;b++)
            for(int j=0;j<=n;j++)
                par[b][j] = 0;
    }
    void dfs_lca(int x,int p=0,int d=0){
        dep[x] = d;
        par[0][x] = p;
        for(int i=1;par[i-1][x];i++)
            par[i][x] = par[i-1][par[i-1][x]];
        for(auto nxt: g[x])
            if(nxt != p)
                dfs_lca(nxt, x, d+1);
    }
    int up(int x,int d){
        for(int i=MXH-1;i>=0;i--)
            if((d>>i) & 1)
                x = par[i][x];
        return x;
    }
    int lca(int x,int y){
        if(dep[x]<dep[y]) swap(x,y);
        x = up(x, dep[x]-dep[y]);
        if(x==y) return x;
        for(int i=MXH-1;i>=0;i--){
            if(par[i][x] != par[i][y]){
                x = par[i][x];
                y = par[i][y];
            }
        }
        return par[0][x];
    }
    bool on_ancestor_path(int s, int e, int m){
        // e is some ancestor of s
        // assert(lca(s, e) == e);
        return (dep[s] >= dep[m] && dep[m] >= dep[e]) && lca(s, m) == m;
    }
    bool on_path(int s,int e,int m){
        int se = lca(s, e);
        return on_ancestor_path(s, se, m) || on_ancestor_path(e, se, m);
    }
    int tree_dist(int x,int y){
        int l = lca(x, y);
        return dep[x] + dep[y] - 2 * dep[l]; 
    }
    int tree_mid(int x, int y){
        int d = tree_dist(x, y);
        if(d & 1) return -1;
        if(dep[x]<dep[y]) swap(x,y);
        return up(x, d/2);
    }
} using namespace LCA;
