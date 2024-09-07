// hijkl2e
class mf_graph {
public:
	using edge = tuple<int, ll, ll>;
	vector<edge> E;
	vector<vector<int>> G;
	vector<int> d, last;
    const ll inf;
	mf_graph(int V) : G(V), d(V), last(V), inf(numeric_limits<ll>::max() / 4) { }
	void add_edge(int u, int v, ll c, bool d = true) {
		G[u].push_back(E.size());
		E.push_back({v, c, 0});
		G[v].push_back(E.size());
		E.push_back({u, d ? 0 : c, 0});
	}
	ll max_flow(int s, int t) {
		ll mf{};
		while (bfs(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (ll f = dfs(s, t, inf)) {
				mf += f;
			}
		}
		return mf;
	}
    // flow should be called first
    vector<bool> min_cut(){
        vector<bool> ret(G.size());
        for (int i = 0; i < G.size(); i++)
            ret[i] = (d[i] != -1);  
        return ret;
    }
private:
	bool bfs(int s, int t) {
		fill(d.begin(), d.end(), -1);
		queue<int> q({s}); d[s] = 0;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int idx : G[u]) {
				auto &[v, cap, flow] = E[idx];
				if (d[v] == -1 && flow < cap) {
					d[v] = d[u] + 1;
					q.push(v);
					if (v == t) return true;
				}
			}
		}
		return false;
	}
	ll dfs(int u, int t, ll f) {
		if (u == t) return f;
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, flow] = E[G[u][i]];
			if (d[v] == d[u] + 1 && flow < cap) {
				if (ll pushed = dfs(v, t, min(f, cap - flow))) {
					flow += pushed;
					auto &rflow = get<2>(E[G[u][i] ^ 1]);
					rflow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
};
