/*
Find Stronly Connected Components
Tarjan's algorithm
O(V+E)
test: https://atcoder.jp/contests/practice2/submissions/53201907
*/
struct scc_graph{
    using vi = vector<int>;
    int n, time, scnt;
    bool called;
    vector<vi> g, groups;
    vi dfsn, low, stk, scc_id;
    vector<bool> in_stk;
    scc_graph(int _n=0):n(_n), time(0), scnt(0), called(false), g(n), groups(n), dfsn(n), low(n), stk(0), scc_id(n), in_stk(n){}
    scc_graph(vector<vi>&_g){*this = scc_graph(_g.size()); g = _g;}
    void add_edge(int a,int b){
        g[a].push_back(b);
    }
    void dfs(int x){
        dfsn[x] = low[x] = ++time;
        stk.push_back(x); in_stk[x] = true;
        for(int nx:g[x]){
            if(!dfsn[nx]){
                dfs(nx);
                low[x] = min(low[x], low[nx]);
            }else if(in_stk[nx]){
                // dfs(nx) didnt end, so dfn[nx] == low[nx]
                low[x] = min(low[x], dfsn[nx]);
            }
        }
        if(low[x] == dfsn[x]){
            int y; do{
                y = stk.back(); stk.pop_back();
                in_stk[y] = false;
                scc_id[y] = scnt;
            }while(y != x);
            scnt++;
        }
    }
    vector<vi> scc(){
        assert(!called && "This should be called once");
        called = true;
        for(int i=0;i<n;i++)if(!dfsn[i]) dfs(i);
        groups.resize(scnt);
        vi counts(scnt);
        for(int i=0;i<n;i++){
            scc_id[i] = (scnt-1) - scc_id[i];
            counts[scc_id[i]]++;
        }
        for(int i=0;i<scnt;i++) groups[i].reserve(counts[i]);
        for(int i=0;i<n;i++) groups[scc_id[i]].push_back(i);
        return groups;
    }
};
