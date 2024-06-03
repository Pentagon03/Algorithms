/*
Convex Hull Trick Container
for doubles, change all (ll -> double), (div(a,b) = a/b)
concave (max value)이면 k 오름차순 삽입 강제되어야 함.
convex (min value)이면 k 내림차순 삽입 강제되어야 함.
typename P: point의 자료형임.
만약에 모든 쿼리가 ll로 들어오면 P = ll, INF = (ll)1e18 이렇게 두면 됨.
struct Line에서 div를 floored division으로 교체해주자.
double 쿼리가 들어오는 경우 그대로 쓰면 됨.
*/
// #define MIN_VALUE
static constexpr double INF = numeric_limits<double>::max(); // change it for int
template<typename P = double>
struct Line{
    ll k, m; // kx + m
    // int idx; // additional info
    P p{INF};
    #ifdef MIN_VALUE
    bool operator<(const Line& o) const{return k!=o.k?k>o.k:m>o.m;}
    #else
    bool operator<(const Line& o) const{return k!=o.k?k<o.k:m<o.m;}
    #endif
    friend inline P inter(const Line&l, const Line&r){
        assert(l.k != r.k);
        auto div = [&](P l, P r)->P{
            // return l / r - (l % r < 0); // int: floored division
            return l / r;
        };
        return div(l.m-r.m, r.k-l.k);
    }
    template<typename T> T f(T x){return k * x + m;}
};
template<typename P = double>
struct CHT{
    using L = Line<P>;
    vector<L> stk;
    int n, p; // 직선의 개수, 마지막으로 살펴본 직선의 위치
    CHT():stk(1),n(0),p(0){}
    bool add(const L& t){
        if(n>=1 && stk[n-1].k == t.k){
            if(!(stk[n-1] < t)) return false;
            --n;
        }
        for(P x; n>=2 && !(stk[n-2].p < (x = inter(stk[n-1], t))); n--){
            // do smth with stk[n-2] and x
        }
        if(n == stk.size()) stk.resize(stk.size() * 2); // double it
        if(n>=1) stk[n-1].p = inter(stk[n-1], t);
        stk[n++] = t;
        return true;
    }
    // x가 증가하는 순서로 들어올 때, amortized O(1)
    L qry(P x){
        assert(n > 0 && "n should be positive");
        p = min(n-1,p);
        while(p<n-1 && stk[p].p < x) p++;
        return stk[p];
    }
    // returns idx ; x의 순서를 모름, 이분탐색, O(log N)
    L qry_bs(P x){
        assert(n > 0 && "n should be positive");
        int lo = -1, hi = n-1;
        while(lo+1<hi){
            int mid = (lo+hi) / 2;
            if(stk[mid].p < x) lo = mid;
            else hi = mid;
        }
        return stk[hi];
    }
};
