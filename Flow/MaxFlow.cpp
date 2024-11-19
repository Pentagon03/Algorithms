/*
# Max Flow
- mf_graph<int> fg(V = number of vertices)
- fg.add_edge(u, v, cap)
- fg.flow(source, sink, flow_limit = inf) 
- fg.min_cut() // flow should be called once, returns vector<bool>, true means in source
- fg.get_edge(i) // returns ith edge added, can see how much flow it 
- fg.edges() // returns all edge
- reference: hijkl2e
*/
// using Cap = int;
template<class Cap>
class mf_graph {
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
public:
	static constexpr Cap flow_inf = numeric_limits<Cap>::max();
    // V = number of vertices
    mf_graph(int V = 0) : G(V), d(V), last(V){ }
    // just add 2 directed edges for bidirectional. doesn't matter.
    void add_edge(int u, int v, Cap c) {
		assert(0 <= u and u < ssize(G) and 0 <= v and v < ssize(G) and c >= 0);
        G[u].push_back(E.size()); E.push_back({v, c});
        G[v].push_back(E.size()); E.push_back({u, 0});
    }
    Cap flow(int s, int t, Cap flow_limit = flow_inf){
		assert(s != t);
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
	vector<edge> edges(){
		int m = ssize(E) / 2;
		vector<edge> es(m);
		for(int i=0;i<m;i++) es[i] = get_edge(i);
		return move(es);
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
};