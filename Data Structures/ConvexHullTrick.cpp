/*
Convex Hull Trick Container
for doubles, change all (ll -> double), (div(a,b) = a/b)
concave (max value)이면 k 오름차순 삽입 강제되어야 함.
convex (min value)이면 k 내림차순 삽입 강제되어야 함.
*/
struct Line{
    ll k,m,p;
    int cnt = 0; // additional info
    ll f(ll x){return k*x+m;}
};
Line st[N]; // Maybe you can make it as a vector.. if u want
struct CHT{
    int n=0, p=0; //n은 현재 직선의 개수, p는 마지막으로 살펴본 직선의 위치
    inline ll div(ll a, ll b){ // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    inline ll inter(const Line &a, const Line &b){
        return div(b.m-a.m,a.k-b.k);
    }
    bool add(const Line& t){
        if(n>=1 && st[n-1].k == t.k){
            if(t.m >= st[n-1].m) return false; // convex, min value
            // if(t.m <= st[n-1].m) return false; // concave, max value
            --n;
        }
        while(n>=2 && !(st[n-2].p < inter(st[n-1], t))) --n;
        if(n>0) st[n-1].p = inter(st[n-1], t);
        st[n++] = t;
        return true;
    }
    // x가 증가하는 순서로 들어올 때, amortized O(1)
    Line qry(ll x){
        assert(n > 0 && "n should be positive");
        p=min(n-1,p);
        while(p<n-1 && st[p].p < x) p++;
        return st[p];
    }
    // x의 순서를 모름 -> 이분탐색, O(log N)
    Line qry_bs(ll x){
        assert(n > 0 && "n should be positive");
        int lo = -1, hi = n-1;
        while(lo+1<hi){
            auto mid = (lo+hi) / 2;
            if(x < st[mid].p) hi = mid;
            else lo = mid;
        }
        return st[hi];
    }
};
