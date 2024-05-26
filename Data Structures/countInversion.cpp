/*
countInversion: number of swap operations to make nums from original
O(n log n)
*/
// put BIT(fenwick tree) struct here
ll countInversion(const vector<int>&original,const vector<int>&nums){
    assert(original.size() == nums.size());
    int n = nums.size();
    vector<int> t(original);
    sort(all(t)); t.erase(unique(all(t)), t.end());
    int nn = t.size();
    vector<vector<int>> v(nn);
    for(int i=0;i<n;i++)
        v[lower_bound(all(t), original[i]) - t.begin()].push_back(i);
    BIT f(n+1);
    ll ans = 0;
    for(int i=n-1;i>=0;i--){
        int x = lower_bound(all(t), nums[i]) - t.begin();
        int idx = v[x].back(); v[x].pop_back();
        ++idx; // 1-base
        ans += f.qry(idx - 1);
        f.upd(idx, 1);
    }
    return ans;
}