/*
Modified Line container for dynamic CHT
y = kx + m
qry: gives minimum value for given x, upper hull
find bool operator< (const Line& o) to change minimum / maximum properties.
for minimum: k > o.k, x->m > y->m
for maximum: k < o.k, x->m < y->m
for doubles, change all (ll -> double), (inf -> 1/.0), (div(a,b) = a/b)
reference: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
*/
#define MIN_VALUE
struct Line{
    mutable ll k, m, p;
    // int cnt; // additional info
    #ifdef MIN_VALUE
    bool operator<(const Line& o) const{return k!=o.k?k>o.k:m>o.m;}
    #else
    bool operator<(const Line& o) const{return k!=o.k?k<o.k:m<o.m;}
    #endif
    bool operator<(ll x) const {return p < x;}
    ll f(ll x) const{return k * x + m;}
};
struct LC : multiset<Line, less<>> {
    void print_it(iterator it){fprintf(stderr, "[%d] %lld %lld %lld\n",(int)distance(begin(),it), it->k, it->m, it->p);}
    void print(){
        fprintf(stderr, "size: %d\n", (int)size());
        for(auto it = begin(); it != end(); it++)
            print_it(it);
    }
    static const ll inf = numeric_limits<ll>::max();
    inline ll div(ll a, ll b){ // floored division
        return a / b - ((a^b)<0 && a%b);
    }
    bool apply(iterator x, iterator y){
        assert(x != end() && next(x) == y);
        if(y == end()) return x->p = inf, false;
        if(x->k == y->k) x->p = (*y<*x?inf:-inf);
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    bool add(const Line &t){
        auto y = insert(t), z = next(y), x = y; 
        if(z!=end() && y->k == z->k) return erase(y), false;
        while(apply(y, z)) z = erase(z);
        if(x != begin() && apply(--x, y)) return apply(x, y = erase(y)), false;
        while((y=x) != begin() && (--x)->p >= y->p) apply(x, erase(y));
        return true;
    }
    Line qry(ll x){
        assert(!empty());
        auto l = lower_bound(x); assert(l != end());
        return *l;
    }
};
