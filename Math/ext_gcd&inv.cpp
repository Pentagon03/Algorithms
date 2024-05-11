// return g, assigns x, y that a * x + b * y = g
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    assert(a>=0 && b>=0); // it actually works when a<0 or b<0
    ll g = a;
    x = 1; y = 0;
    // note that x and y are swapped
    if(b != 0) g = ext_gcd(b, a%b, y, x), y -= a/b*x; 
    return g;
}
// return x that a * x = 1 mod m
ll inv(ll a, ll m){
    ll x, y; 
    ll g = ext_gcd(a, m, x, y);
    if(g != 1) return -1;
    return (x%m + m) % m;
}
