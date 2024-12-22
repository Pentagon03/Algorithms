template<typename T = int, typename cmp = less<T>>
int lis(const vector<T> &v){
    vector<T> t;
    for(auto &i:v){
        auto it = lower_bound(all(t), i, cmp());
        if(it == t.end()) t.push_back(i);
        else *it = i;
    }
    return t.size();
}
template<typename T = int, typename cmp = less<T>>
vector<int> lis_recover(const vector<T> &v){
    int n = v.size();
    vector<T> t(n);
    vector<int> idx(n), before(n);
    int ans = 0;
    for(int i=0;i<n;i++){
        int loc = lower_bound(begin(t), begin(t) + ans, v[i], cmp()) - t.begin();
        if(loc == ans) ++ans;
        t[loc] = v[i]; idx[loc] = i;
        before[i] = loc ? idx[loc - 1] : -1;
    }
    vector<int> res;
    int cur = idx[ans - 1];
    while(cur != -1){
        res.push_back(v[cur]);
        cur = before[cur];
    }
    reverse(all(res));
    return res;
}