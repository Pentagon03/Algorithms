/*
# Min Cost Flow (zkw MCMF, faster on )
- mcf_graph<cap, cost> fg(V);
- R: struct{Cap, Cost};
- R fg.flow(source, sink, flow_limit, cost_limit, paths_limit)
- vector<R> fg.slope(source, sink, flow_limit, cost_limit, paths_limit)
- finds flow until flow <= flow_limit.
- find only paths such that cost per flow <= cost_limit.
- finds Augmenting path less or equal to 'paths_limit' times.
- reference: hijkl2e, https://www.acmicpc.net/source/62155473
## Time Complexity
- O(EV + F(E+V))
- reference: hijkl2e
*/
// using Cap = int32_t; using Cost = int64_t;
template<typename Cap, typename Cost>
struct mcf_graph {
// private:
	struct _edge{int to; Cap cap; Cost cost;};
	vector<_edge> E;
	vector<vector<int>> G;
	vector<Cost> d; vector<bool> inq, vis;
	vector<int> last;
	bool spfa(int s, int t, Cost cost_limit) {
		fill(d.begin(), d.end(), cost_inf);
		fill(inq.begin(), inq.end(), false);
		queue<int> q({s}); d[s] = 0; inq[s] = true;
		while(q.size()) {
			int u = q.front(); q.pop();
			inq[u] = false;
			for(int idx : G[u]) {
				auto &[v, cap, cost] = E[idx];
				if(d[v] > d[u] + cost && cap > 0) {
					d[v] = d[u] + cost;
					if(not inq[v]) {
						inq[v] = true;
						q.push(v);
					}
				}
			}
		}
		return d[t] <= cost_limit;
	}
	bool update(int s, int t, Cost cost_limit){
		Cost mn = cost_inf;
		for(int i=0;i<ssize(G);i++){
			if(not vis[i]) continue;
			// vis[i] means 'i' has been the augmenting path
			for(int idx: G[i]){
				auto &[j, cap, cost] = E[idx];
				if(cap > 0 and not vis[j]) mn = min(mn, d[i] + cost - d[j]);
			}
		}
		if(mn >= cost_inf) return 0;
		for(int i=0;i<ssize(G);i++)
			if(not vis[i])
				d[i] += mn;
		return d[t] <= cost_limit;
	}
	Cap dfs(int u, int t, Cap f) {
		vis[u] = true;
		if (u == t) return f;
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, cost] = E[G[u][i]];
			if (not vis[v] and d[v] == d[u] + cost && cap > 0) {
				if (Cap pushed = dfs(v, t, min(f, cap)); pushed > 0) {
					cap -= pushed;
					auto &rcap = E[G[u][i] ^ 1].cap;
					rcap += pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
// public:
	static constexpr Cap flow_inf = numeric_limits<Cap>::max();
	static constexpr Cost cost_inf = numeric_limits<Cost>::max() / 2;
	static constexpr int paths_inf = numeric_limits<int>::max();
	mcf_graph(int V) : G(V), d(V), last(V), vis(V), inq(V){}
	void add_edge(int u, int v, Cap cap, Cost cost) {
		assert(0 <= u and u < ssize(G) and 0 <= v and v < ssize(G));
		G[u].push_back(E.size());
		E.push_back({v, cap, cost});
		G[v].push_back(E.size());
		E.push_back({u, 0, -cost});
	}
	struct R{Cap cap; Cost cost;};
	// returns a Convex down (x = Cap, y = cost) piecewise segments
	vector<R> slope(int s, int t, Cap flow_limit = flow_inf, Cost cost_limit = cost_inf - 1, int paths_limit = paths_inf){
		assert(s != t);
		Cap flow{}; Cost cost{};
		vector<R> ans({R{flow, cost}});
		int path_count = 0;
		if (not spfa(s, t, cost_limit)) return ans;
		while (flow < flow_limit and path_count < paths_limit){
			if (not update(s, t, cost_limit)) break;
			fill(last.begin(), last.end(), 0);
			while (flow < flow_limit and path_count < paths_limit){
				fill(vis.begin(), vis.end(), false);
				Cap f = dfs(s, t, flow_limit - flow);
				if (not (f > 0)) break;
				flow += f;
				cost += f * d[t];
				ans.push_back(R{flow, cost});
				++path_count;
			}
		}
		return ans;
	}
	R flow(int s, int t, Cap flow_limit = flow_inf, Cost cost_limit = cost_inf - 1, int paths_limit = paths_inf) {
		assert(s != t);
		return slope(s, t, flow_limit, cost_limit, paths_limit).back();
	}
	// flow should be called first
	vector<bool> min_cut(){
		vector<bool> ans(ssize(G));
		for (int i=0;i<ssize(G);i++){
			ans[i] = d[i] != cost_inf;
		}
		return ans;
	}
	struct edge{
		int from, to;
		Cap cap, flow;
		Cost cost;
	};
	edge get_edge(int i){
		i *= 2;
		assert(0 <= i and i < E.size());
		auto[to, cap, cost] = E[i];
		auto[from, rcap, rcost] = E[i^1];
		return edge{from, to, cap + rcap, rcap, cost};
	}
	vector<edge> edges(){
		int m = ssize(E) / 2;
		vector<edge> es(m);
		for (int i=0;i<m;i++) es[i] = get_edge(i);
		return move(es);
	}
	void change_edge(int i, Cap new_cap, Cap new_flow, Cost new_cost) {
		i *= 2;
		assert(0 <= i and i < E.size());
		assert(0 <= new_flow and new_flow <= new_cap);
		auto& e = E[i];
		auto& re = E[i^1];
		e.cap = new_cap - new_flow; e.cost = new_cost;
		re.cap = new_flow; re.cost = -new_cost;
	}
	void reset(){
		for (int i=0;i<E.size();i+=2){
			auto& e = E[i];
			auto& re = E[i^1];
			e.cap += re.cap;
			re.cap = 0;
		}
	}
};