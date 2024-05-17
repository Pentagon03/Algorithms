/*
ext gcd
returns {g, x, y} that a * x + b * y = g = gcd(a,b)
*/
// using lll = __int128_t;
struct tll{ll g, x, y;};
tll ext_gcd(ll a, ll b) {
    // assert(a>=0 && b>=0); // it actually works when a<0 or b<0
    if(!b) return tll{1, 0, a};
    auto[g,x,y] = ext_gcd(b, a%b);
    return tll{y, x-a/b*y, g};
}

// ADDITIONAL //

// return x that a * x = 1 mod m
ll inv(ll a, ll m){
    auto [g,x,y] = ext_gcd(a, m);
    if(g != 1) return -1;
    return (x%m + m) % m;
}

// do_smth for x,y that ax + by = s, x >= 0 && y >= 0
bool do_smth(ll a, ll b, ll s){
    auto [g,x,y] = ext_gcd(a, b);
    if(s % g != 0) return false;
    a /= g; b /= g; s /= g;
    x *= s; y *= s;
    assert(a!=0 && b!=0 && "a and b should be non-zero");
    lll t1 = x / b, t2 = y / a;
    x -= b * t1; y += a * t1;
    for(ll i = -t1; i<=t2; x += b, y -= a, i++){
        if(x>=0 && y>=0){
            // do smth
        }
    }
    return true
}