/**
 * cur[i] = min(pre[j] + C(j,i)) 
 * if Opt(i) is monotone, we can apply Dnc opt.
 * Usually C(j, i) is a monge array
*/
auto dnc = [&](int steps, int n){
    const ll infl = numeric_limits<ll>::max()/2; 
    auto C = [&](int j, int i){
        // You should carefully handle j > i case
        if(j > i) return infl;
        return ;
    };
    vector<ll> pre(n+1), cur(n+1);
    for(int i=0;i<=n;i++) pre[i] = C(i, 0);
    auto dnc = [&](auto&self, int l, int r, int optl, int optr){
        if(l > r) return;
        int m = l + r >> 1;
        pair<ll, int> best({infl, m});
        for(int i=optl;i<=min(m, optr);i++){
            if(pre[i] >= infl) continue;
            best = min(best, {pre[i] + C(i, m), i});
        }
        int opt; tie(cur[m], opt) = best;
        self(self, l, m-1, optl, opt);
        self(self, m+1, r, opt, optr);
    };
    for(int i=1;i<=steps;i++){
        dnc(dnc, 0, n, 0, n);
        pre.swap(cur);
    }
    return pre;
};