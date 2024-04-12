namespace VertexDisjointBCC{
    int dfn[N], low[N], pv;
    vector<int> g[N];
    void add_edge(int a,int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }
    void dfs(int x,int p){
        dfn[x] = low[x] = ++pv;
        for(auto nx: g[x]) if(nx != p){
            if(dfn[nx]) low[x] = min(low[x], dfn[nx]);
            else{
                dfs(nx, x);
                low[x] = min(low[x], low[nx]);
            }
        }
    }
    int bcnt = 1, bcc[N];
    vector<pii> bridges;
    void color(int x,int col){
        bcc[x] = col;
        for(int nx:g[x]) if(!bcc[nx]){
            if(low[nx] <= dfn[x]) color(nx, col); 
            else{
                bridges.emplace_back(min(x, nx), max(x, nx));
                color(nx, ++bcnt);
            }
        }
    }
    void get_bcc(int n){
        for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i, 0);
        for(int i=1;i<=n;i++) if(!bcc[i]) color(i, 1);
    }
} using namespace VertexDisjointBCC;
