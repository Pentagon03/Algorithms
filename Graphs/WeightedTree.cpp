/**
 * Tree with Weighted Edges
 */
using W = int;
constexpr W INF_ = numeric_limits<W>::max() / 2; // INF + INF doesn't overflow
// call init before doing smth
struct WeightedTree{
    using Edge = tuple<int, int, W>;
    int n; // vertex from 0 to n-1
    vector<vector<pair<int, W>>> g;
    int pv;
    vector<int> in, out;
    vector<W> dep;
    const int lg;
    vector<vector<int>> up; // up[i][x] -> ith parent of x
    WeightedTree(int n_):n(n_), g(n), pv(0), in(n), out(n), dep(n), lg(__lg(n)), up(lg+1, vector<int>(n, -1)){}
    void add_edge(int a, int b, W w = 1){
        assert(a < n and b < n);
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }
    void add_edges(const vector<Edge>&edge_list){
        for(auto&[a, b, w]: edge_list)
            add_edge(a, b, w);
    }
    void add_edges(const vector<pair<int,int>>&edge_list){
        for(auto&[a, b]: edge_list)
            add_edge(a, b);
    }
    void init(int root){
        dfs(root, -1);
    }
    void dfs(int x,int p){
        in[x] = pv++;
        up[0][x] = p;
        for(int i=1;up[i-1][x] != -1;i++)
            up[i][x] = up[i-1][up[i-1][x]];
        for(auto[nx, w]: g[x])
            if(nx != p){
                dep[nx] = dep[x] + w;
                dfs(nx, x);
            }
        out[x] = pv;
    }
    int go_up(int x,int cnt){
        assert(cnt >= 0);
        if(cnt==0) return x;
        for(int i=lg;i>=0;i--)
            if((cnt>>i) & 1)
                x = up[i][x];
        return x;
    }
    bool is_ancestor(int u, int v){
        if(u == -1) return true;
        if(v == -1) return false;
        return in[u] <= in[v] and out[v] <= out[u];
    }
    int lca(int u,int v){
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        for(int i=lg;i>=0;i--)
            if(not is_ancestor(up[i][u], v))
                u = up[i][u];
        return up[0][u];
    }
    int tree_dist(int u,int v){
        int l = lca(u, v);
        return dep[u] + dep[v] - 2 * dep[l]; 
    }
    // is x on (u->p);
    bool on_ancestor_path(int u, int p, int x){
        assert(is_ancestor(p, u));
        return is_ancestor(x, u) and is_ancestor(p, x);
    }
    // is x on (u->v)
    bool on_path(int u,int v,int x){
        int l = lca(u, v);
        return on_ancestor_path(u, l, x) || on_ancestor_path(v, l, x);
    }
    // only when all w = 1
    int tree_mid(int u, int v){
        int d = tree_dist(u, v);
        if(d & 1) return -1;
        if(dep[u]<dep[v]) swap(u,v);
        return go_up(u, d/2);
    }
};