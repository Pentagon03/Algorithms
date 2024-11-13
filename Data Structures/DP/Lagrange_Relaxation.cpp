void Lagrange(){
    // dp(i) = dp(j) + C(j,i)
    // f(x): using at most x index. If f(x) is convex or concave... f(x) - \lambda x is always concave..
    auto f = [&](ll lambda){
        // solve
        return pair<ll,ll>{dpval,cnt};
    };
    ll lo = 0, hi = 1LL * m * m + 1;
    // lo: k 초과
    // hi: k 이하
    // 반정수하는게 나중에 역추적할 때 깔끔하긴 하나, 답만 구할거라면 필요없음.
    while(lo + 1 < hi){
        auto mid = (lo+hi)/2;
        auto [x, c] = f(mid);
        if(c <= k) hi = mid;
        else lo = mid;
    }
    ll ans = max(f(lo).first - lo * k, f(hi).first - hi * k);
    return ans;
}
