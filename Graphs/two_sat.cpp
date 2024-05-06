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
    inline void add_edge(int a,int b){g[a].push_back(b);}
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
reference1: https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/2sat.h
reference2: https://atcoder.github.io/ac-library/production/document_en/twosat.html
test: https://atcoder.jp/contests/practice2/submissions/53206694
*/
struct two_sat{
    using vi = vector<int>;
    int n;
    vector<bool> ans;
    vector<vi> g;
    two_sat(int _n=0):n(_n),g(2*n){}
    inline void add_edge(int a,int b){
        assert(a < 2*n && b < 2*n && 2*n == g.size() && "graph size");
        g[a].push_back(b);
    }
    // 2x + 0: false, 2x + 1: true
    inline int idx(int i, bool a){return 2*i+a;}
    // (i = a OR j = b)
    void add_clause(int x,int y){
        assert(0 <= x && x < 2*n && "x in range");
        assert(0 <= y && y < 2*n && "y in range");
        add_edge(x^1, y); add_edge(y^1, x);
    }
    void add_clause(int i, bool a, int j, bool b){
        assert(0 <= i && i < n && "i in range");
        assert(0 <= j && j < n && "j in range");
        i = idx(i, a); j = idx(j, b);
        add_edge(i^1, j); add_edge(j^1, i);
    }
    void is_equal(int i, bool a, int j, bool b){
        add_clause(i, a, j, !b);
        add_clause(i, !a, j, b);
    }
    int addVar(){
        g.emplace_back(); g.emplace_back();
        return n++;
    }
    void atMostOneNaive(const vector<pair<int,bool>>& v){
        if(v.size() <= 1) return;
        for(int i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++)
                add_clause(v[i].first, !v[i].second, v[j].first, !v[j].second);
    }
    void atMostOne(const vector<pair<int,bool>>& v){
        if(v.size() <= 1) return;
        if(v.size() <= 4){
            atMostOneNaive(v);
            return;
        }
        auto [cur, a] = v[0]; cur = idx(cur, !a);
        for(int i=2;i<v.size();i++){
            int next = addVar();  next = idx(next, true);
            auto [x, b] = v[i]; x = idx(x, b);
            add_clause(cur, x^1);
            add_clause(cur, next);
            add_clause(x^1, next);
            cur = next^1;
        }
        auto [nxt, b] = v[1]; nxt = idx(nxt, b);
        add_clause(cur, nxt ^ 1);
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
