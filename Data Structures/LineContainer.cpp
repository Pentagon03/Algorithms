/*
Line container for dynamic CHT
y = kx + m
qry: gives maximum value for given x
reference: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
test: http://boj.kr/a211ad15a535458d99b36fea79fccfc7
*/
struct Line{
    mutable ll k, m, p; // p is for intersection point
    bool operator<(const Line& o) const{return k<o.k;}
    bool operator<(ll x) const {return p < x;}
};
struct LineContainer: multiset<Line,less<>>{
    // for doubles, use inf = 1/.0, div(a,b) = a/b
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b){ // floored division
        return a/b - ((a^b)<0&&a%b);
    }
    bool inter(iterator x, iterator y){
        if(y == end()) return x->p=inf, 0;
        if(x->k == y->k) x->p = (x->m > y->m ? inf: -inf);
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m){
        auto z = insert({k, m, 0}), y = z++, x = y;
        while(inter(y,z)) z = erase(z);
        if(x != begin() && inter(--x, y)) inter(x, y = erase(y));
        while((y=x) != begin() && (--x)->p >= y->p)
            inter(x, erase(y));
    }
    ll qry(ll x){
        // assert(!empty());
        if(empty()) return -inf;
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};
