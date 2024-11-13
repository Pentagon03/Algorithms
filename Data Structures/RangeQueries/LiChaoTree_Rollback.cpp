// source: benedict0724 https://www.acmicpc.net/source/65475052
struct Line{
    ll m, y;
    Line() {}
    Line(ll _m, ll _y) {
        m = _m;
        y = _y;
    }
    ll get(ll x) {
        return m * x + y;
    }
};

struct Node{
    int l, r;
    ll s, e;
    Line line;
};

vector<vector<pair<int, Line>>> rollback;

struct Li_Chao{
    vector<Node> tree;
    void init(ll s, ll e) {
        tree.push_back({-1, -1, s, e, Line(0, inf)});
    }
    
    void update(int node, Line v, int now) {
        
        ll s = tree[node].s, e = tree[node].e;
        ll m = s + e >> 1;
        
        rollback[now].push_back({node, tree[node].line});
        
        Line low = tree[node].line, high = v;
        if(low.get(s) > high.get(s)) swap(low, high);
        
        if(low.get(e) <= high.get(e)) {
            tree[node].line = low; return;
        }
        
        if(low.get(m) < high.get(m)){
            tree[node].line = low;
            if(tree[node].r == -1) {
                tree[node].r = tree.size();
                tree.push_back({-1, -1, m+1, e, {0, inf}});
            }
            update(tree[node].r, high, now);
        }
        else {
            tree[node].line = high;
            if(tree[node].l == -1) {
                tree[node].l = tree.size();
                tree.push_back({-1, -1, s, m, {0, inf}});
            }
            update(tree[node].l, low, now);
        }
    }
    
    ll query(int node, ll x){
        if(node == -1) return inf;
        ll s = tree[node].s, e = tree[node].e;
        ll m = s + e >> 1;
        if(x <= m) return min(tree[node].line.get(x), query(tree[node].l, x));
        else return min(tree[node].line.get(x), query(tree[node].r, x));
    }
    
    void rb(int now) {
        for(auto u : rollback[now]) {
            int node = u.first;
            Line line = u.second;
            tree[node].line = line;
        }
    }
} seg;
