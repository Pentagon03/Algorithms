template<typename T = int, typename cmp = less<T>>
int lis(vector<T> &v){
    vector<T> t;
    for(auto &i:v){
        auto it = lower_bound(all(t), i, cmp());
        if(it == t.end()) t.push_back(i);
        else *it = i;
    }
    return t.size();
}