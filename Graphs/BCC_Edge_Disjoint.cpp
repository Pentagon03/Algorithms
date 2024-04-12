/*
Edge Disjoint BCC
We are dividing BCC into set of edges.
Each BCC doesn't have any articulation point.
*/
namespace EdgeDisjointBCC{
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
    bool vis[N];
    int bcnt;
    vector<int> bcc[N];
    void color(int x,int col){
        vis[x] = true;
        if(col) bcc[x].push_back(col);
        for(int nx:g[x]) if(!vis[nx]){
            if(low[nx] < dfn[x]) color(nx, col); 
            else{
                bcc[x].push_back(++bcnt);
                color(nx, bcnt);
            }
        }
    }
    vector<int> cutVertices;
    void get_bcc(int n){
        for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i, 0);
        for(int i=1;i<=n;i++) if(!vis[i]) color(i, 0);
        for(int i=1;i<=n;i++) if(size(bcc[i])>1) cutVertices.push_back(i);
    }
} using namespace EdgeDisjointBCC;
