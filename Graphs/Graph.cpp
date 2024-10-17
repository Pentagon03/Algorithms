/**
 * Graph with Weighted Edges
 * Bellman Ford Validation: https://www.acmicpc.net/source/share/066ba979355348c5aefde66f11aa2dae
 */
using W = int;
constexpr W INF_ = numeric_limits<W>::max() / 2; // INF + INF doesn't overflow
struct Graph{
    using Edge = tuple<int, int, W>;
    int n; // vertex from 0 to n-1
    vector<vector<pair<int, W>>> g;
    Graph(int n_):n(n_), g(n){}
    void add_edge(int a, int b, W w = 1, bool directed = true){
        assert(a < n and b < n);
        g[a].emplace_back(b, w);
        if(not directed) g[b].emplace_back(a, w);
    }
    void add_edges(const vector<Edge>&edge_list, bool directed = true){
        for(auto&[a, b, w]: edge_list)
            add_edge(a, b, w, directed);
    }
    void add_edges(const vector<pair<int,int>>&edge_list, bool directed = true){
        for(auto&[a, b]: edge_list)
            add_edge(a, b, 1, directed);
    }
    void shuffle(){
        static mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        for(int i=0;i<n;i++){
            if(g[i].size()){
                std::shuffle(g[i].begin(), g[i].end(), rng);
            }
        }
    }
    vector<vector<int>> connected_components_undirected(){
        vector<vector<int>> ans;
        vector<bool> vis(n);
        vector<int> t;
        auto dfs = [&](auto&self, int x)->void{
            vis[x] = true; t.push_back(x); 
            for(auto[nx, w]: g[x]) if(not vis[nx]) self(self, nx);
        };
        for(int i=0;i<n;i++){
            if(not vis[i]){
                t.clear();
                dfs(dfs, i);
                ans.push_back(move(t));
            }
        }
        return move(ans);
    }
    template<typename T>
    using min_heap = priority_queue<T, vector<T>, greater<T>>;
    // INF + INF shouldn't overflow
    pair<vector<W>, vector<int>> dijkstra(int src, int max_step = -1, W INF = INF_){
        vector<W> dis(n, INF);
        vector<int> d(n, -1);
        min_heap<pair<W,int>> pq;
        pq.emplace(dis[src] = 0, src);
        if(max_step == -1) max_step = n;
        for(int i = 0; i < max_step and not pq.empty();){
            auto [cur_dis, x] = pq.top(); pq.pop();
            if(cur_dis > dis[x]) continue;
            i++; // ith permanent node
            for(auto[nx, w]: g[x]){
                int val = cur_dis + w;
                if(dis[nx] > val){
                    dis[nx] = val;
                    d[nx] = x;
                    pq.emplace(val, nx);
                }
            }
        }
        return {move(dis), move(d)};
    }
    // returns {empty vector, cycle} if there is a negative cycle
    pair<vector<W>, vector<int>> bellman_ford(int src, bool &neg_cycle, int max_step = -1, W INF = INF_){
        vector<W> dis(n, INF);
        vector<int> d(n, -1);
        queue<pair<W, int>> q({{dis[src] = 0, src}}); // SPFA
        auto detect_cycle = [&](int x)->vector<int>{
            vector<bool> vis(n);
            vector<int> t;
            while(true){
                t.push_back(x);
                if(vis[x]) break;
                vis[x] = true;
                x = d[x];
            }
            int last = t.back();
            reverse(t.begin(), t.end());
            while(t.back() != last) t.pop_back();
            return move(t);
        };
        if(max_step == -1) max_step = n;
        for(int i = 1; i <= max_step and not q.empty(); i++){
            int sz = q.size();
            for(int j = 0; j < sz; j++){
                auto [cur_dis, x] = q.front(); q.pop();
                if(cur_dis > dis[x]) continue;
                for(auto[nx, w]: g[x]){
                    if(dis[nx] > dis[x] + w){
                        dis[nx] = dis[x] + w;
                        d[nx] = x;
                        if(i == n){
                            neg_cycle = true;
                            return {{}, detect_cycle(nx)};
                        }
                        q.emplace(dis[nx], nx);
                    }
                }
            }
        }
        neg_cycle = false;
        return {move(dis), move(d)};
    }
    vector<int> topological_sort(){
        vector<bool> vis(n);
        vector<int> ans;
        auto dfs = [&](auto&self, int x)->void{
            vis[x] = true;
            for(auto[nx, w]: g[x]) if(not vis[nx]) self(self, nx);
            ans.push_back(x);
        };
        for(int i=0;i<n;i++) if(not vis[i]) dfs(dfs, i);
        reverse(ans.begin(), ans.end());
        return move(ans);
    }
    pair<vector<W>, vector<int>> dag_shortest_path(int src, W INF = INF_){
        vector<W> dis(n, INF);
        vector<int> d(n, -1);
        vector<int> vtx = topological_sort();
        dis[src] = 0;
        for(int x: vtx){
            if(dis[x] == INF) continue;
            for(auto[nx, w]: g[x]){
                int val = dis[x] + w;
                if(dis[nx] > val){
                    dis[nx] = val;
                    d[nx] = x;
                }
            }
        }
        return {move(dis), move(d)};
    }
    // we assume there is path. returns series of edges
    vector<Edge> find_path(int src, int dest, const vector<int>& dis, const vector<int>& d){
        vector<Edge> ans;
        int cur = dest;
        while(cur != src){
            int prv = d[cur];
            ans.emplace_back(prv, cur, dis[cur] - dis[prv]);
            cur = prv;
        }
        assert(cur == src);
        reverse(ans.begin(), ans.end());
        return move(ans);
    }
    pair<vector<vector<W>>, vector<vector<int>>> floyd_warshall(bool &neg_cycle, int max_node = -1, W INF = INF_){
        vector<vector<W>> dis(n, vector<int>(n, INF)); 
        vector<vector<int>> d(n, vector<int>(n, -1));
        for(int x=0;x<n;x++)
            for(auto[nx, w]: g[x])
                if(dis[x][nx] > w){
                    dis[x][nx] = w;
                    d[x][nx] = x;
                    if(x == nx and w < 0){
                        neg_cycle =  true;
                        return {{}, {{x, x}}};
                    }
                }
        for(int i=0;i<n;i++) dis[i][i] = 0, d[i][i] = -1;
        auto detect_cycle = [&](int x)->vector<int>{
            vector<int> t;
            int from = x, to = x, cur = x;
            t.push_back(cur);
            cur = d[from][cur];
            while(true){
                t.push_back(cur);
                if(cur == from) break;
                cur = d[from][cur];
            }
            reverse(t.begin(), t.end());
            return move(t);
        };
        if(max_node == -1) max_node = n - 1;
        for(int m=0; m<=max_node; m++)
            for(int s=0; s<n; s++)
                for(int e=0; e<n; e++){
                    if(dis[s][m] == INF or dis[m][e] == INF) continue;
                    int val = dis[s][m] + dis[m][e];
                    if(dis[s][e] > val){
                        dis[s][e] = val;
                        d[s][e] = d[m][e];
                        if(s == e and val < 0){
                            neg_cycle = true;
                            return {{}, {detect_cycle(s)}};
                        }
                    }
                }
        neg_cycle = false;
        return {move(dis), move(d)};
    }
    // we assume there is path. returns series of edges
    vector<int> find_path_floyd_warshall(int from, int to, const vector<vector<int>>& d){
        vector<int> t;
        int cur = to;
        while(true){
            t.push_back(cur);
            if(cur == from) break;
            cur = d[from][cur];
        }
        reverse(t.begin(), t.end());
        return move(t);
    }
};