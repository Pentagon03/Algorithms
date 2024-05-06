/*
Find Stronly Connected Components
Kosaraju's algorithm
O(V+E)
test: https://atcoder.jp/contests/practice2/submissions/53194190
*/
struct scc_graph{
    using vi = vector<int>;
    int n, scnt;
    bool called;
    vector<vi> g, gR, groups;
    vector<bool> vis;
    vi S, scc_id;
    scc_graph(int _n=0):n(_n), scnt(0), called(false), g(_n), gR(_n), scc_id(_n), vis(_n){}
    void add_edge(int a,int b){
        g[a].push_back(b);
        gR[b].push_back(a);
    }
    void dfs(int v, bool rev = false){
        vis[v] = true;
        auto&G = !rev ? g: gR;
        if(rev) scc_id[v] = scnt;
        for(auto nxt:G[v])
            if(!vis[nxt])
                dfs(nxt, rev);
        if(!rev) S.push_back(v);
    }
    vector<vi> scc(){
        assert(!called && "This should be called once");
        called = true;
        for(int i=0;i<n;i++) if(!vis[i]) dfs(i, false);
        vis.assign(n, false);
        reverse(S.begin(), S.end());
        // S in topological order
        for(int x: S) if(!vis[x]) dfs(x, true), scnt++;
        vi counts(scnt);
        for(int i=0;i<n;i++) counts[scc_id[i]]++;
        groups.resize(scnt);
        for(int i=0;i<scnt;i++) groups[i].reserve(counts[i]);
        for(int i=0;i<n;i++) groups[scc_id[i]].push_back(i);
        return groups;
    }
};
