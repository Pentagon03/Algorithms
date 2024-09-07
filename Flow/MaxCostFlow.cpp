// Edited, source: hijkl2e, https://www.acmicpc.net/source/62155473
// O(VEf) but average O(Ef)
// Test: https://www.acmicpc.net/source/83574185
template<typename Cost = int>
class mcf_graph {
public:
	using edge = tuple<int, int, int, Cost>;
	vector<edge> E;
	vector<vector<int>> G;
	vector<int> last;
	vector<bool> vst;
	vector<Cost> d;
	Cost tcost{}, mxcost{}, inf{};
	mcf_graph(int V) : G(V), d(V), last(V), vst(V), inf(numeric_limits<Cost>::max()/4){ }
	void add_edge(int u, int v, int cap, Cost cost, bool d = true) {
		G[u].push_back(E.size());
		E.push_back({v, cap, 0, cost});
		G[v].push_back(E.size());
		E.push_back({u, 0, 0, -cost});
		if (!d) add_edge(v, u, cap, cost);
	}
	// put inf for no constrains for _mxcost
	pair<int, Cost> flow(int s, int t, Cost _mxcost) {
		mxcost = _mxcost;
		int mf{};
		while (spfa(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (int f = dfs(s, t, inf)) {
				mf += f;
			}
		}
		return {mf, tcost};
	}
private:
	bool spfa(int s, int t) {
		fill(d.begin(), d.end(), inf);
		queue<int> q;
		d[s] = 0, vst[s] = true;
		q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			vst[u] = false;
			for (int idx : G[u]) {
				auto &[v, cap, flow, cost] = E[idx];
				if (d[v] > d[u] + cost && flow < cap) {
					d[v] = d[u] + cost;
					if (!vst[v]) {
						vst[v] = true;
						q.push(v);
					}
				}
			}
		}
		return d[t] < mxcost;
	}
	int dfs(int u, int t, int f) {
		if (u == t) {
			return f;
		}
		vst[u] = true;
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, flow, cost] = E[G[u][i]];
			if (!vst[v] && d[v] == d[u] + cost && flow < cap) {
				if (int pushed = dfs(v, t, min(f, cap - flow))) {
					tcost += pushed * cost;
					flow += pushed;
					auto &rflow = get<2>(E[G[u][i] ^ 1]);
					rflow -= pushed;
					vst[u] = false;
					return pushed;
				}
			}
		}
		vst[u] = false;
		return 0;
	}
};
