// hijkl2e, https://www.acmicpc.net/source/59744372

using ll = long long;

const ll INF = 4e18;

class MF {
public:
	MF(int V) : G(V), cap(V, vector<ll>(V)), flow(V, vector<ll>(V)), d(V), last(V) { }
	void add_edge(int u, int v, ll c, bool d = true) {
		G[u].push_back(v);
		G[v].push_back(u);
		cap[u][v] = c;
		cap[v][u] = d ? 0 : c;
	}
	ll dinic(int s, int t) {
		ll mf{};
		while (bfs(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (ll f = dfs(s, t)) {
				mf += f;
			}
		}
		return mf;
	}
	vector<int> d;
private:
	bool bfs(int s, int t) {
		fill(d.begin(), d.end(), -1);
		queue<int> q;
		d[s] = 0;
		q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int v : G[u]) {
				if (d[v] == -1 && flow[u][v] < cap[u][v]) {
					d[v] = d[u] + 1;
					q.push(v);
					if (v == t) {
						return true;
					}
				}
			}
		}
		return false;
	}
	ll dfs(int u, int t, ll f = INF) {
		if (u == t) {
			return f;
		}
		for (int &i = last[u]; i < G[u].size(); ++i) {
			int v = G[u][i];
			if (d[v] == d[u] + 1 && flow[u][v] < cap[u][v]) {
				if (ll pushed = dfs(v, t, min(f, cap[u][v] - flow[u][v]))) {
					flow[u][v] += pushed;
					flow[v][u] -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	vector<vector<int>> G;
	vector<vector<ll>> cap, flow;
	vector<int> last;
};



// hijkl2e, https://www.acmicpc.net/source/62155473
template<typename Cap, typename Cost>
class mcf_graph {
public:
	using edge = tuple<int, Cap, int, Cost>;
    Cost mxcost{};
	mcf_graph(int V) : G(V), d(V), last(V), vst(V){ }
	void add_edge(int u, int v, int cap, int cost, bool directed = true) {
		G[u].push_back(E.size());
		E.push_back({v, cap, 0, cost});
		G[v].push_back(E.size());
		E.push_back({u, 0, 0, -cost});
		if (!directed) add_edge(v, u, cap, cost);
	}
    using pr = pair<Cap, Cost>;
    vector<pr> slope(int s, int t, Cost max_cost){
        mxcost = max_cost;
        Cap mf{};
        vector<pr> ans({pr{mf, tcost}});
		while (spfa(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (int f = dfs(s, t)) {
				mf += f;
                ans.push_back({mf, tcost});
			}
		}
		return ans;
    }
	pr flow(int s, int t, Cost max_cost) {
        return slope(s, t, max_cost).back();
	}
private:
	bool spfa(int s, int t) {
		fill(d.begin(), d.end(), mxcost);
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
	Cap dfs(int u, int t, int f = inf) {
		if (u == t) {
			return f;
		}
		vst[u] = true;
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, flow, cost] = E[G[u][i]];
			if (!vst[v] && d[v] == d[u] + cost && flow < cap) {
				if (Cap pushed = dfs(v, t, min(f, cap - flow))) {
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
	vector<edge> E;
	vector<vector<int>> G;
	vector<Cost> d;
	vector<int> last;
	vector<bool> vst;
	Cost tcost{};
};
