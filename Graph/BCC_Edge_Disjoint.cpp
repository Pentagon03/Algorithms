/*
Edge Disjoint BCC
We are dividing BCC into set of edges.
Each BCC doesn't have any articulation point.
Use init(n) at the very first, if needed
test: https://www.acmicpc.net/problem/11266, https://www.acmicpc.net/problem/4222
*/
namespace EdgeDisjointBCC{
    vector<int> g[N];
    void add_edge(int a,int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int dfn[N], low[N], pv;
    void dfs(int x,int p = 0){
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
    void color(int x,int col = 0){
        vis[x] = true;
        if(col) bcc[x].push_back(col); // when col = 0, this is root
        for(int nx:g[x]) if(!vis[nx]){
            if(low[nx] < dfn[x]) color(nx, col); 
            else{
                bcc[x].push_back(++bcnt);
                color(nx, bcnt);
            }
        }
    }
    vector<int> cutVertices;
    void init(int n){
        pv = bcnt = 0;
        for(int i=1;i<=n;i++){
            g[i].clear();
            dfn[i] = low[i] = vis[i] = 0;
            bcc[i].clear();
        }
        cutVertices.clear(); 
    }
    void get_bcc(int n){
        for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i, 0);
        for(int i=1;i<=n;i++) if(!vis[i]) color(i, 0);
        for(int i=1;i<=n;i++) if(size(bcc[i])>1) cutVertices.push_back(i);
    }
} using namespace EdgeDisjointBCC;
