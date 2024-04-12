/*
Find Stronly Connected Components
Kosaraju's algorithm
O(V+E)
*/
namespace SCC{
    vector<int> g[N], gR[N], S;
    vector<bool> vis;
    int scc[N], scnt;
    void add_edge(int a,int b){
        g[a].push_back(b);
        gR[b].push_back(a);
    }
    void dfs(int v, bool rev = false){
        vis[v] = true;
        auto&G = !rev ? g: gR;
        if(rev) scc[v] = scnt;
        for(auto nxt:G[v]) if(!vis[nxt]) dfs(nxt, rev);
        if(!rev) S.push_back(v);
    }
    vector<vector<int>> SCCs;
    void get_SCC(int n){
        vis.assign(n+1, false);
        for(int i=1;i<=n;i++) if(!vis[i]) dfs(i, false);
        vis.assign(n+1, false);
        reverse(all(S));
        for(int x: S) if(!vis[x]) ++scnt, dfs(x, true);
        SCCs.resize(scnt + 1);
        for(int i=1;i<=n;i++) SCCs[scc[i]].push_back(i);
    }
} using namespace SCC;
