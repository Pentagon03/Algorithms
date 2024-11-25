/**
 * Title: "Min" Persistent Leftist Heap
 * Repository: https://github.com/Pentagon03/Algorithms/blob/master/Data%20Structures/leftist_heap.cpp
 * Reference: nor( https://judge.yosupo.jp/submission/87297 )
 */
template <typename Key, typename Value>
struct LeftistHeap {
    using self_t = LeftistHeap<Key, Value>;
    int node_rank;
    Key key;
    Value value;
    self_t *left, *right;
    LeftistHeap(int rank_, Key key_, Value value_, self_t* left_,
                self_t* right_)
            : node_rank{rank_}, key{key_}, value{value_}, left{left_}, right{right_} {}
    // contains Leftistheap itself for each node. We use deque for non-reallocation such as vector. pointers don't get invalidated.
    inline static thread_local std::deque<LeftistHeap> alloc;
    friend self_t* heap_insert(LeftistHeap* a, const Key &k, const Value &v) {
        if (not a or not (a->key < k)) { // Important: k == a.key case should be considerd. if not, k will be repeatively inserted through the whole heap.
            alloc.emplace_back(1, k, v, a, nullptr);
            return &alloc.back();
        }
        auto l = a->left, r = heap_insert(a->right, k, v);
        // Gurantee => l valid and l->rank >= r->rank
        if (not l or l->node_rank < r->node_rank)
            std::swap(l, r);
        alloc.emplace_back(r ? r->node_rank + 1 : 0, a->key, a->value, l, r);
        return &alloc.back();
    }
};

/**
 * Title: K Shortest Walks using Eppstein98(https://ics.uci.edu/~eppstein/pubs/Epp-SJC-98.pdf)
 * You can get distances, and recover full path.
 * Prerequisite: Leftist Heap(https://github.com/Pentagon03/Algorithms/blob/master/Data%20Structures/leftist_heap.cpp)
 * Repository: https://github.com/Pentagon03/Algorithms/blob/master/Graphs/k_shortest_walks.cpp
 * Test: https://judge.yosupo.jp/submission/244972
 * Test: https://www.acmicpc.net/source/share/ff1b64260b894885b6ed1503fc11c8a7
 * Reference: nor( https://judge.yosupo.jp/submission/87297 )
 */

template <class Distance, class WeightedGraph>
struct kShortestWalksSolver{
private:
    const Distance MAX_DISTANCE, IDENTITY_DISTANCE;
    const WeightedGraph& g;
    int n;
    bool is_dag; // contains whether this graph is DAG or not.
    bool negative_edge; // contains whether this graph contains neagative edge weight

    template <typename T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
    std::vector<Distance> d; // d(x): shortest path from x to sink
    std::vector<int> best; // best(x): next node in the shortest path from x to sink 

    // LeftistHeap: for edge (u, v, w),  sidetrack(u,v,w) weight will be key, edge (u, v) will be value
    using heap_t = LeftistHeap<Distance, std::pair<int, int>>;
    std::vector<heap_t*> h; // contains heap pointer for each node

    std::vector<Distance> distances; // distance of K-shortest path

    // We will treat each sidetrack as 'nodes'
    std::vector<heap_t*> nodes; // sidetrack ptrs (change to pair<Distance, heap_t*> if you want to be clear...)
    std::vector<int> prev_node; // previous sidetrack for each sidetrack

    std::vector<int> path_last_node; // last sidetrack index of "nodes" in K-shortest path
public:
    /**
     * Graph g: vector<vector<pair<int,Distance>> or other similar structure.
     * g shoule be given as Reference, should be valid until we use K_Shortest_Paths_Solver.
     * is_dag: whether g is DAG or not.
     * MAX_DISTANCE: maximum value of Distance
     * IDENTITY_DISTANCE: Identity value of Distance
     */
    explicit kShortestWalksSolver(const WeightedGraph& g_, Distance MAX_DISTANCE_, Distance IDENTITY_DISTANCE_, bool is_dag_ = false, bool negative_edge_ = false)
            : g(g_), n(g_.size()), MAX_DISTANCE(MAX_DISTANCE_), IDENTITY_DISTANCE(IDENTITY_DISTANCE_), is_dag(is_dag_), negative_edge(negative_edge_) {}
    
    // returns {distance vector, prev vertex vector}
    std::pair<std::vector<Distance>, std::vector<int>> dijkstra(const WeightedGraph& g_, int src) {
        std::vector<Distance> d_(g_.size(), MAX_DISTANCE);
        std::vector<int> prv(g_.size(), -1);
        min_heap<std::pair<Distance, int>> heap;
        heap.emplace(d_[src] = IDENTITY_DISTANCE, src);
        while (!heap.empty()) {
            auto [dv, v] = heap.top();
            heap.pop();
            if (dv != d_[v]) continue;
            for (auto &[to, w] : g_[v]) {
                if (d_[to] > dv + w) {
                    d_[to] = dv + w;
                    heap.emplace(d_[to], to);
                    prv[to] = v;
                }
            }
        }
        return std::make_pair(std::move(d_), std::move(prv));
    }

    // returns {empty vector, cycle} if there is a negative cycle
    // returns {distance vector, prev vertex vector}
    std::pair<std::vector<Distance>, std::vector<int>> bellman_ford(const WeightedGraph& g_, int src){
        std::vector<Distance> dis(n, MAX_DISTANCE);
        std::vector<int> prv(n, -1);
        auto detect_cycle = [&](int x)->vector<int>{
            vector<bool> vis(n);
            vector<int> t;
            while(true){
                t.push_back(x);
                if(vis[x]) break;
                vis[x] = true;
                x = prv[x];
            }
            int last = t.back();
            reverse(t.begin(), t.end());
            while(t.back() != last) t.pop_back();
            return move(t);
        };

        std::queue<std::pair<Distance, int>> q({{dis[src] = IDENTITY_DISTANCE, src}}); // SPFA
        for(int i = 1; i <= n and not q.empty(); i++){
            int sz = q.size();
            for(int j = 0; j < sz; j++){
                auto [cur_dis, x] = q.front(); q.pop();
                if(cur_dis > dis[x]) continue;
                for(auto[nx, w]: g_[x]){
                    if(dis[nx] > dis[x] + w){
                        dis[nx] = dis[x] + w;
                        prv[nx] = x;
                        if(i == n){
                            assert(0 and "Negative Cycle Occured");
                            return std::make_pair(std::vector<Distance>(), detect_cycle(nx));
                        }
                        q.emplace(dis[nx], nx);
                    }
                }
            }
        }
        return std::make_pair(std::move(dis), std::move(prv));
    }

    // O(|E| + |V|)
    std::vector<int> topology_sort(const WeightedGraph& g_){
        const int n_ = g_.size();
        std::vector<int> in_deg(n_, 0);
        for(int u = 0; u < n_; u++)
            for(auto &[v, w]: g_[u])
                in_deg[v]++;
        std::queue<int> q;
        for(int u = 0; u < n_; u++)
            if(not in_deg[u])
                q.push(u);
        std::vector<int> order(n_);
        for(auto &u : order){
            if(q.empty()) {
                assert(0 && "Cycle occured in DAG");
                return order;
            }
            u = q.front();
            q.pop();
            for(auto &[v, w]: g_[u])
                if(--in_deg[v] == 0)
                    q.push(v);
        }
        return move(order);
    }

    // O(|E| + |V|), Solves DAG shortest path problem
    // returns pair{vector of shortest paths, vector of previous node}
    std::pair<vector<Distance>, vector<int>> shortest_path_dag(const WeightedGraph& g_, int s){
        std::vector<Distance> d_(g_.size(), MAX_DISTANCE);
        std::vector<int> prv(g_.size(), -1);
        d_[s] = IDENTITY_DISTANCE;
        auto order = topology_sort(g_);
        for(auto v: order){
            if(d_[v] == MAX_DISTANCE) continue;
            for(auto &[to, w] : g_[v]){
                if(d_[to] > d_[v] + w){
                    d_[to] = d_[v] + w;
                    prv[to] = v;
                }
            }
        }
        return std::make_pair(move(d_), move(prv));
    }

    // O(|E| log |V| + |K|)
    // returns vector of distances
    std::vector<Distance> k_shortest_paths(int source, int sink, int k) {
        WeightedGraph g_rev(n);
        for (int u = 0; u < n; ++u)
            for (auto &[v, w] : g[u])
                g_rev[v].push_back({u, w});
        if(is_dag) std::tie(d, best) = shortest_path_dag(g_rev, sink);
        else if(not negative_edge) std::tie(d, best) = dijkstra(g_rev, sink);
        else std::tie(d, best) = bellman_ford(g_rev, sink);
        
        if (d[source] == MAX_DISTANCE)
            return move(std::vector<Distance>{});

        std::vector<std::basic_string<int>> tree(n);
        for (int u = 0; u < n; ++u)
            if (best[u] != -1)
                tree[best[u]].push_back(u); // u will adopt best[u]'s heap
        
        h = std::vector<heap_t*>(n, nullptr);
        {
            std::queue<int> q({sink});
            while (!q.empty()) {
                auto u = q.front();
                q.pop();
                bool seen_p = false;
                for (auto [v, w] : g[u]) {
                    if (d[v] == MAX_DISTANCE)
                        continue;
                    auto c = w + d[v] - d[u];
                    if (not seen_p and v == best[u] and c == IDENTITY_DISTANCE) {
                        seen_p = true; // we can only skip once.
                        continue;
                    }
                    h[u] = heap_insert(h[u], c, {u, v});
                }
                for (auto p : tree[u]) h[p] = h[u], q.push(p); // This works fast since this is basically a pointer
            }
        }

        distances = std::vector<Distance>{d[source]};
        distances.reserve(k);
        path_last_node = std::vector<int>{-1};
        path_last_node.reserve(k);

        nodes = std::vector<heap_t*>{};
        nodes.reserve(3 * k);
        prev_node = std::vector<int>{};
        prev_node.reserve(3 * k);

        if (not h[source])
            return move(distances);

        {
            min_heap<std::tuple<Distance, heap_t*, int>> q;
            auto emplace = [&](const Distance& d_, heap_t* h_, int pre = -1){
                int cur = nodes.size();
                q.emplace(d_, h_, cur);
                nodes.push_back(h_);
                prev_node.push_back(pre);
            };

            emplace(d[source] + h[source]->key, h[source], -1);
            while (!q.empty() and (int) distances.size() < k) {
                auto [cd, ch, cur] = q.top();
                q.pop();
                distances.push_back(cd);
                path_last_node.push_back(cur);
                if (h[ch->value.second]) emplace(cd + h[ch->value.second]->key, h[ch->value.second], cur); // add value
                if (ch->left) emplace(cd + ch->left->key - ch->key, ch->left, prev_node[cur]); // same heap, add difference
                if (ch->right) emplace(cd + ch->right->key - ch->key, ch->right, prev_node[cur]); // same heap, add difference
            }
        }
        return move(distances);
    }

    // returns list of edges: {node a, node b, Distance w}
    std::vector<std::tuple<int, int, Distance>> kth_shortest_full_path(int source, int sink, int k, bool call_k_paths = false) {
        if (call_k_paths)
            k_shortest_paths(source, sink, k + 1);
        std::vector<std::tuple<int, int, Distance>> path{};
        if (k < 0 or k >= path_last_node.size())
            return path;
        std::vector<std::tuple<int, int, Distance>> sidetracks{};
        {
            int cur = path_last_node[k];
            while (cur != -1) {
                auto nd = nodes[cur];
                auto [u, v] = nd->value;
                // sidetrack = d[v] + w - d[u] => w = sidetrack + d[u] - d[v];
                auto w = nd->key + d[u] - d[v];
                sidetracks.emplace_back(u, v, w);
                cur = prev_node[cur];
            }
            std::reverse(sidetracks.begin(), sidetracks.end());
        }
        {
            int idx = 0;
            int cur = source;
            using std::get;
            while (cur != sink or idx < (int) sidetracks.size()){
                if(idx < (int) sidetracks.size() and cur == get<0>(sidetracks[idx])){
                    path.push_back(sidetracks[idx]);
                    cur = get<1>(sidetracks[idx]);
                    idx++;
                }else{
                    int nxt = best[cur];
                    path.emplace_back(cur, nxt, d[cur] - d[nxt]);
                    cur = nxt;
                }
            }
        }
        return move(path);
    }
};