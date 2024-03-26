/*
Fast Discrete Logarithm using Phollig-hellman
find dlog s.t pow(base, dlog) mod p == val
use dlog(base, val, p) for prime p
use phollig_hellman(base, val, m) for every modulo m (possibly not prime)
Reference: https://rkm0959.tistory.com/187
*/
namespace DiscreteLog{
    // using pii = pair<int,int>;
    int get_random_int(int l,int r) {
        static random_device rd;
        return uniform_int_distribution<int>(l,r)(rd);
    }
    
    inline int powmod(int x,int n,int mod=inf){
        int ans=1;
        for(;n;n>>=1){
            if(n&1) ans=1LL*ans*x%mod;
            x=1LL*x*x%mod;
        }
        return ans;
    }
    
    vector<pii> get_divisor(int n){
        vector<pii> div;
        for(int i=2;i*i<=n;i++){
            int cnt = 0;
            while(n % i == 0){
                n /= i;
                ++cnt;
            }
            if(cnt>0) div.emplace_back(i,cnt);
        }
        if(n>1) div.emplace_back(n,1);  
        return div;
    }
    
    int get_order(int g,int p){
        if(gcd(g,p) != 1) return -1;
        if(g==1) return 1;
        int pm = p-1;
        vector<pii> div = get_divisor(pm);
        int ans = pm;
        for(auto[pi,cnt]: div){
            for(int i=0;i<cnt && powmod(g, ans / pi, p) == 1; i++)
                ans /= pi;
        }
        return ans;
    }
    
    bool is_primitive(int g, int p){
        // return get_order(g,p) == p-1;
        int pm = p-1;
        vector<pii> div = get_divisor(pm);
        for(auto[pi,cnt]:div)
            if(powmod(g, pm / pi, p) == 1)
                return false;
        return true;
    }
    
    int get_primitive(int p){
        // p is a prime, so it has a primitive root of course
        int pm = p-1;
        
        if(p<300){
            for(int g=2;g<=pm;g++)
                if(is_primitive(g, p))
                    return g;
        }
        else{
            while(true){
                int g = get_random_int(2,pm);
                if(is_primitive(g,p))
                    return g;
            }
        }
    
        //never reaches here.
        return -1;
    }
    
    int dlog(int base, int val, int p,int ord = -1){
        base %= p; val %= p;
        if(val == 1) return 0;
        if(base == val) return 1;
        // const int B = sqrt(get_order(base,p)) + 1;
        if(ord == -1) ord = get_order(base, p);
        const int B = sqrt(ord) + 2;
        vector<pii> s;
        int x = 1;
        for(int v=0;v<B;v++){
            if(x==val) return v;
            s.emplace_back(x,v);
            x = 1LL * x * base % p;
        }
        sort(begin(s), end(s));
        x = val;
        int t = powmod(base, p-1-B, p);
        for(int u=0;u<B;u++){
            auto it = lower_bound(all(s), pii(x,0));
            if(it != s.end() && it->first == x)
                return u * B + it->second;
            x = 1LL * x * t % p;
        }
        return -1;
    }
    
    ll ext_gcd(ll a, ll b, ll& x, ll& y) {
        assert(a>=0 && b>=0); // it actually works when a<0 or b<0
        ll g = a;
        x = 1; y = 0;
        // note that x and y are swapped
        if(b != 0) g = ext_gcd(b, a%b, y, x), y -= a/b*x; 
        return g;
    }
    
    ll inv(ll a, ll m){
        // return x that a * x = 1 mod m
        ll x, y; 
        ll g = ext_gcd(a, m, x, y);
        if(g != 1) return -1;
        return (x%m + m) % m;
    }
    
    int pohlig_hellman(int base,int val,int p){
        base %= p; val %= p;
        if(val == 1) return 0;
        if(base == val) return 1;
        if(base == 0) return -1;
        vector<pii> div;
        int pm = get_order(base, p);
        div = get_divisor(pm);
        int ans = 0, m = 1;
        for(auto[pi, ei]: div){
            int nbase = powmod(base, pm / pi, p);
            int npm = pm;
            int pipow = 1;
            int r = 0;
            for(int e=1;e<=ei;e++){
                // find x mod pi^e such that (g^(pm/(pi^e)))^x = h^(pm/(pi^e))
                // x = pi^e-1 * k + r
                npm /= pi;
                int k = dlog(nbase, 1LL * powmod(val, npm, p) * powmod(base, 1LL * npm * (p-1-r) % (p-1), p) % p, p, pi);
                if(k==-1) return -1;
                assert(k < pi);
                r = pipow * k + r; 
                pipow *= pi;
                r %= pipow;
            }
            // r mod pi^ei
            if(m==1){
                ans = r;
                m = pipow;
            }else{
                ll x, y;
                int nxtm = m * pipow;
                ext_gcd(m, pipow, x, y); // mx + pipow y = 1;
                x %= nxtm; y %= nxtm; 
                ans = (1LL*ans* pipow %nxtm *y %nxtm + 1LL* r * m %nxtm * x %nxtm)%nxtm;
                if(ans<0) ans += nxtm;
                m = nxtm;
            }
        }
        return ans;
    }
}
