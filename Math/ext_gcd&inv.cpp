/*
ext gcd
returns {g, x, y} that a * x + b * y = g = gcd(a,b)
*/
// using ll = __int128_t;
struct tll{ll g, x, y;};
tll ext_gcd(ll a, ll b) {
    // assert(a>=0 && b>=0); // it actually works when a<0 or b<0
    if(!b) return tll{1, 0, a};
    auto[g,x,y] = ext_gcd(b, a%b);
    return tll{y, x-a/b*y, g};
}
// return x that a * x = 1 mod m
ll inv(ll a, ll m){
    auto [g,x,y] = ext_gcd(a, m);
    if(g != 1) return -1;
    return (x%m + m) % m;
}