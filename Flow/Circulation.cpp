/*
# Circulation
- prerequisite: Max Flow (mf_graph<Cap>)
- Circulation(int V, int src, int sink)
- add_edge(u, v, lower cap, upper cap)
- is_feasible(Cap flow_limit, bool first_call, bool exact_flow)
    - sets flow_limit such that atmost flow_limit can go from src to sink
    - first_call: only set this true for first_call
    - exact_call: only set this true when you want exact flow to be src -> sink
*/
template<class Cap>
struct Circulation{
    int n;
    mf_graph<Cap> fg;
    static constexpr Cap cap_inf = mf_graph<Cap>::cap_inf;
    vector<Cap> demand, L;
    Cap fsum;
    int s, t, gs, gt;
    Circulation(int V, int src, int sink): n(V), s(src), t(sink), gs(n), gt(n+1), fg(n+2), demand(n){}
    void add_edge(int u, int v, Cap lower, Cap upper){
        assert(0 <= lower and lower <= upper);
        assert(0 <= u and u < n and 0 <= v and v < n);
        demand[u] += lower; // outflow가 증가할 것이므로 demand 0을 유지하기 위해서
        demand[v] -= lower; // inflow가 증가할 것이므로 demand 0을 유지하기 위해
        L.push_back(lower);
        fg.add_edge(u, v, upper - lower);
    }
    // src -> sink flow_limit.
    bool is_feasible(Cap flow_limit = cap_inf, bool first_call = true, bool exact_flow = false){
        assert(reduce(begin(demand), end(demand)) == 0); 
        if(first_call){
            fsum = Cap{};
            add_edge(t, s, exact_flow ? flow_limit : 0, flow_limit);
            for(int i=0;i<n;i++){
                if(demand[i] < 0){ // needs inflow
                    fg.add_edge(gs, i, -demand[i]);
                }
                if(demand[i] > 0){ // needs outflow
                    fg.add_edge(i, gt, demand[i]);
                    fsum += demand[i];
                }
            }
        }else{
            fg.reset();
            fg.change_edge(L.size()-1, flow_limit, 0);
        }
        auto f = fg.flow(gs, gt);
        return f == fsum;
    }
    Cap max_flow(){
        bool ok = is_feasible();
        if(not ok) return -1;
        int last = L.size() - 1;
        int cur_flow = fg.get_edge(last).flow + L[last];
        cur_flow += fg.flow(s, t);
        return cur_flow;
    }
    Cap min_flow(){
        bool ok = is_feasible();
        if(not ok) return -1;
        int last = L.size() - 1;
        int cur_flow = fg.get_edge(last).flow + L[last];
        Cap lo = 0, hi = cur_flow, mid;
        while(lo < hi) is_feasible(mid = midpoint(lo, hi), false) ? hi = mid : lo = mid + 1;
        ok = is_feasible(hi, false, true);
        assert(ok);
        return hi;
    }
    struct edge{
        int from, to;
        Cap flow;
    };
    // call this after desired flow status
    vector<edge> edges(){
        auto edges = fg.edges();
        int m = L.size() - 1; assert(m < edges.size());
        vector<edge> ans(m);
        for(int i=0;i<m;i++){
            auto&[from, to, cap, flow] = edges[i];
            assert(0 <= from and from < n and 0 <= to and to < n);
            auto&lower = L[i];
            ans[i] = {from, to, lower + flow};
        }
        return ans;
    }
};