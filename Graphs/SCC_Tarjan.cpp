/*
Find Stronly Connected Components
Tarjan's algorithm
O(V+E)
*/
namespace SCC{
    vector<int> g[N];
    int dfn[N], low[N], pv;
    void add_edge(int a,int b){
        g[a].push_back(b);
    }
    bool in_stk[N];
    stack<int> stk; int scc[N], scnt;
    void dfs(int x){
        dfn[x] = low[x] = ++pv;
        stk.push(x); in_stk[x] = true;
        for(int nx:g[x]){
            if(!dfn[nx]){
                dfs(nx);
                low[x] = min(low[x], low[nx]);
            }else if(in_stk[nx]){
                // dfs(nx) didnt end, so dfn[nx] == low[nx]
                low[x] = min(low[x], dfn[nx]);
            }
        }
        if(low[x] == dfn[x]){
            ++scnt;
            int y; do{
                y = stk.top(); stk.pop();
                in_stk[y] = false;
                scc[y] = scnt;
            }while(y != x);
        }
    }
    vector<vector<int>> SCCs;
    void get_SCC(int n){
        for(int i=1;i<=n;i++)if(!dfn[i]) dfs(i);
        SCCs.resize(scnt + 1);
        for(int i=1;i<=n;i++) SCCs[scc[i]].push_back(i);
    }
} using namespace SCC;
