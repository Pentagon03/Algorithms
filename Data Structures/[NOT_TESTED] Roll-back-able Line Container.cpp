/*
Rollback-able Line container for dynamic CHT that can be Rollbacked.
y = kx + m
qry: gives minimum value for given x, Lower hull
find bool operator< (const Line& o) to change minimum / maximum properties.
for minimum: k > o.k, x->m > y->m
for maximum: k < o.k, x->m < y->m
for doubles, change all (ll -> double), (inf -> 1/.0), (div(a,b) = a/b)
reference: https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h
*/
struct Line{
    mutable ll k, m, p;
    bool operator<(const Line& o) const{return k!=o.k?k>o.k:m>o.m;} // chg here
    bool operator<(ll x) const {return p < x;}
};
struct LineContainer : multiset<Line, less<>> {
    void print_it(iterator it){fprintf(stderr, "%dth %lld %lld %lld\n",(int)distance(begin(),it), it->k, it->m, it->p);}
    void print(){
        fprintf(stderr, "size: %d\n", size());
        for(auto it = begin(); it != end(); it++)
            print_it(it);
    }
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b){ // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool apply(iterator x, iterator y){
        assert(x != end() && next(x) == y);
        if(y == end()){
            x->p = inf;
            return false;
        }
        if(x->k == y->k) x->p = (*y<*x?inf:-inf);
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    vector<int> info; vector<Line> S;
    bool add(ll k, ll m){
        Line t{k, m, -inf};
        auto z = insert(t), y = z++, x = y; 
        if(z!=end() && k == z->k){erase(y); info.push_back(0); return false;}
        vector<Line> v; 
        while(apply(y, z)) v.push_back(*z), z = erase(z);
        if(x != begin() && apply(--x, y)){
            apply(x, y = erase(y)); 
            info.push_back(0); return false;
        }
        reverse(v.begin(), v.end());
        while((y=x) != begin() && (--x)->p >= y->p) v.push_back(*y), apply(x, erase(y));
        v.push_back(t);
        S.insert(S.end(), v.begin(), v.end()); info.push_back(v.size());
        return true;
    }
    void rollback(){
        assert(!info.empty());
        auto c = info.back(); info.pop_back();
        if(c == 0) return;
        assert(c <= S.size());
        auto l = S.back(); S.pop_back(); --c;
        auto it = lower_bound(l); 
        assert(it != end() && it->k == l.k && it->m == l.m);
        it = erase(it);
        if(c==0){
            if(size() > 0 && it != begin()) apply(prev(it), it);
            return;
        }
        bool flag = it != begin(); if(flag) --it;
        auto y = it;
        if(flag) y = insert(y, S.back()), apply(it, y);
        else y = insert(S.back());
        for(int i=2;i<=c;i++) y = insert(y, S[S.size()-i]), apply(prev(y), y);
        assert(y != end()); 
        apply(y, next(y));
        S.resize(S.size()-c);
    }
    ll qry(ll x){
        assert(!empty());
        auto l = lower_bound(x); 
        assert(l != end());
        return l->k * x + l->m;
    }
};
