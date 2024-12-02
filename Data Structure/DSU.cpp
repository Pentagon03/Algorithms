struct disjoint_set{
	vector<int> par;
    vector<array<int, 3>> S; // rollback stack
	disjoint_set(int n = 0) : par(n, -1) {}
	int find(int u) {
		return par[u] < 0 ? u : par[u] = find(par[u]);
	}
	bool merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		// sz[u] <= sz[v]
		if (par[u] < par[v]) swap(u, v); 
        // S.push_back({u, v, par[u]});
		par[v] += par[u];
		par[u] = v;
		return true;
	}
    void rollback(int n = 1){
        for(int i=0;i<n;i++){
			assert(not empty(S));
			auto [u,v,psz] = S.back(); S.pop_back();
			par[v] -= psz; par[u] = psz;
		}
    }
};