/*
Find Stronly Connected Components
Tarjan's algorithm
O(V+E)
test: https://atcoder.jp/contests/practice2/submissions/53205875
latest version: https://github.com/Pentagon03/Algorithms/blob/master/Graphs/SCC_Tarjan.cpp
*/
struct scc_graph{
    using vi = vector<int>;
    int n, time, scnt;
    bool called;
    vector<vi> g, groups;
    vi dfsn, low, stk, id;
    vector<bool> in_stk;
    scc_graph(int _n=0):n(_n), time(0), scnt(0), called(false), g(n), groups(n), dfsn(n), low(n), stk(0), id(n), in_stk(n){}
    scc_graph(const vector<vi>&_g){*this = scc_graph(_g.size()); g = _g;}
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
                id[y] = scnt;
            }while(y != x);
            scnt++;
        }
    }
    void _get_scc(){
        called = true;
        for(int i=0;i<n;i++) if(!dfsn[i]) dfs(i);
        for(int&k: id) k = (scnt-1) - k;
    }
    vi scc_id(){
        if(!called) _get_scc();
        return id;
    }
    vector<vi> scc(){
        if(!called) _get_scc();
        groups.resize(scnt);
        vi counts(scnt);
        for(int k: id) ++counts[k];
        for(int i=0;i<scnt;i++) groups[i].reserve(counts[i]);
        for(int i=0;i<n;i++) groups[id[i]].push_back(i);
        return groups;
    }
};
/*
two_sat
there should be scc_graph struct on top: https://github.com/Pentagon03/Algorithms/blob/master/Graphs/SCC_Tarjan.cpp
test: https://atcoder.jp/contests/practice2/submissions/53205929
*/
struct two_sat{
    using vi = vector<int>;
    int n;
    vector<bool> ans;
    vector<vi> g;
    two_sat(int _n=0):n(_n),g(2*n){}
    void add_edge(int a,int b){
        g[a].push_back(b);
    }
    // 2x + 0: false
    // 2x + 1: true
    inline int to_idx(int i, bool a){return 2*i+a;}
    // (x OR y)
    void add_clause(int x,int y){
        assert(0 <= x < 2 * n && "x in range");
        assert(0 <= y < 2 * n && "y in range");
        add_edge(x^1, y);
        add_edge(y^1, x);
    }
    void is_equal(int x,int y){
        add_clause(x, y^1);
        add_clause(x^1, y);
    }
    // (i = a OR j = b)
    void add_clause(int i, bool a, int j, bool b){
        assert(0 <= i && i < n && "i in range");
        assert(0 <= j && j < n && "j in range");
        add_clause(to_idx(i, a), to_idx(j, b));
    }
    int addVar(){
        g.emplace_back(); g.emplace_back();
        return n++;
    }
    void atMostOne(const vi& v){
        if(v.size() <= 1) return;
        int cur = v[0];
        for(int i=1;i<v.size();i++){
            int next = addVar();
            add_edge(cur, v[i]^1); // yi-1 -> ~xi
            add_edge(cur, next); // yi-1 -> yi
            add_edge(v[i], next); // xi -> yi
            next = cur;
        }
    }
    bool satisfiable() {
        scc_graph scc(g);
        auto id = scc.scc_id();
        ans.resize(n);
        for(int i = 0; i < n; i++){
            if(id[2*i] == id[2*i+1]) return false;
            ans[i] = id[2*i+1] > id[2*i];
        }
        return true;
    }
    vector<bool> answer(){
        if(ans.size() == 0) satisfiable();
        return ans;
    }
};
