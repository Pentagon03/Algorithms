void dnc(){
    auto C = [&](int i, int j){
        // some monge array.
    };
    vector<int> pre(n+1, -1), cur(n+1);
    pre[0] = 0;
    // we get dp(k, l ~ r), we see dp(k-1, optl ~ optr).
    auto dnc = [&](auto&self, int l, int r, int optl, int optr){
        if(l > r) return;
        int m = l + r >> 1;
        cur[m] = -1;
        int opt = 0;
        int il = optl, ir = min(m-1, optr);
        for(int i=il;i<=ir;i++){
            if(pre[i] == -1) continue;
            int v = pre[i] + C(i+1, m);
            if(cur[m] < v){
                cur[m] = v;
                opt = i;
            }
        }
        self(self, l, m-1, optl, opt);
        self(self, m+1, r, opt, optr);
    };
    for(int i=1;i<=n;i++){
        dnc(dnc, 1, n, 0, n);
        cur[0] = -1;
        cout << cur[n] << '\n';
        pre.swap(cur);
    }
}
