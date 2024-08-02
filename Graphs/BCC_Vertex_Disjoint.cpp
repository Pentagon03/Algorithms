/*
Vertex Disjoint BCC
We are dividing BCC into set of vertices.
Each BCC doesn't have any articulation edge(bridge).
Use init(n) at the very first, if needed
test: https://www.acmicpc.net/problem/11400
*/
namespace VertexDisjointBCC{
    vector<int> g[N];
    void add_edge(int a,int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int dfn[N], low[N], pv;
    void dfs(int x,int p=0){
        dfn[x] = low[x] = ++pv;
        for(auto nx: g[x]) if(nx != p){
            if(dfn[nx]) low[x] = min(low[x], dfn[nx]);
            else{
                dfs(nx, x);
                low[x] = min(low[x], low[nx]);
            }
        }
    }
    int bcnt, bcc[N];
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
    void init(int n){
        pv = bcnt = 0;
        for(int i=1;i<=n;i++){
            g[i].clear();
            dfn[i] = low[i] = bcc[i] = 0;
        }
        bridges.clear();
    }
    void get_bcc(int n){
        for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i, 0);
        for(int i=1;i<=n;i++) if(!bcc[i]) color(i, ++bcnt);
    }
} using namespace VertexDisjointBCC;
