struct disjoint_set {
	vector<int> par;
    stack<tuple<int,int,int>> S;
	disjoint_set(int n=N) : par(n+1, -1) {}
	void init(int n=N) {
		fill(par.begin(), par.begin()+n+1, -1);
	}
	int find(int u) {
		return par[u] < 0 ? u : par[u] = find(par[u]);
	}
	bool merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (par[u] < par[v]) swap(u, v); //then sz[u] <= sz[v]
        S.push({u, v, par[u]});
		par[v] += par[u];
		par[u] = v;
		return true;
	}
    void rollback(){
        if(S.empty()) return;
        auto [u,v,sz] = S.top();
        par[v] -= sz;
        par[u] = sz;
        S.pop();
    }
};