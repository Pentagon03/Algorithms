/*
Line container for dynamic CHT
y = kx + m
qry: gives minimum value for given x
reference: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
find 2 of (//chg here) to change minimum / maximum properties.
*/
struct Line{
    mutable ll k, m, p;
    // we know that there will be only 'integer' queries
    bool operator<(const Line& o) const{return k > o.k;} // chg here
    // only for integer coordinates
    bool operator<(ll x) const {return p < x;}
};
struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b){ // floored division
        return a / b - (a ^ b < 0 && a % b);
    }
    bool apply(iterator x, iterator y){
        if(y == end()){
            x->p = inf;
            return false;
        }
        if(x->k == y->k) x->p = (x->m < y->m?inf:-inf); // chg here
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m){
        auto z = insert({k, m, 0}), y = z++, x = y;
        while(apply(y, z)) z = erase(z);
        if(x != begin() && apply(--x, y)) apply(x, y = erase(y));
        while((y=x) != begin() && (--x)->p >= y->p)
            apply(x, erase(y));
    }
    ll qry(ll x){
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
