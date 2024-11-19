template<class Cap = int64_t>
class mf_graph {
public:
    // V = number of vertices
    mf_graph(int V) : G(V), d(V), last(V){ }
    // just add 2 directed edges for bidirectional. doesn't matter.
    void add_edge(int u, int v, Cap c) {
        G[u].push_back(E.size()); E.push_back({v, c});
        G[v].push_back(E.size()); E.push_back({u, 0});
    }
    Cap flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit){
        Cap flow{};
        while (flow < flow_limit) {
            if(bool res = bfs(s, t); not res) break;
            fill(last.begin(), last.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(s, t, flow_limit - flow);
                if(not f) break;
                flow += f;
            }
        }
        return flow;
    }
    // flow should be called first, vis[i] = true means i is visited from source
    vector<bool> min_cut(){
        vector<bool> vis(G.size());
        for (int i = 0; i < G.size(); i++)
            vis[i] = (d[i] != -1);
        return vis;
    }
    struct edge{
        int from, to; 
        Cap cap, flow;
    };
    edge get_edge(int i){
        i *= 2;
        assert(0 <= i and i < E.size());
        auto[to, cap] = E[i];
        auto[from, rcap] = E[i^1];
        return edge{from, to, cap + rcap, rcap};
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        i *= 2; 
        assert(0 <= i and i < E.size());
        assert(0 <= new_flow and new_flow <= new_cap);
        auto& e = E[i];
        auto& re = E[i^1];
        e.cap = new_cap - new_flow;
        re.cap = new_flow;
    }
private:
    struct _edge{ int to; Cap cap;};
    vector<_edge> E; vector<vector<int>> G;
    vector<int> d, last;
    bool bfs(int s, int t) {
        fill(d.begin(), d.end(), -1);
        queue<int> q({s}); d[s] = 0;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int idx : G[u]) {
                auto &[v, cap] = E[idx];
                if (d[v] == -1 and cap > 0) {
                    d[v] = d[u] + 1;
                    q.push(v);
                    if (v == t) return true;
                }
            }
        }
        return false;
    }
    Cap dfs(int u, int t, Cap f) {
        if (u == t) return f;
        for (int &i = last[u]; i < G[u].size(); ++i) {
            auto &[v, cap] = E[G[u][i]];
            if (d[v] == d[u] + 1 and cap > 0) {
                if (Cap pushed = dfs(v, t, min(f, cap))) {
                    cap -= pushed;
                    auto &rflow = E[G[u][i] ^ 1].cap;
                    rflow += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
};