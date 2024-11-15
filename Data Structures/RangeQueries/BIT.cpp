/*
- Binary indexed Tree
- set your operation function op
- You may make off-by-one error, so it prevents it
*/
template<typename T>
struct BIT{
    int n; vector<T> t;
    BIT(int _n=0):n(_n+4),t(n+1){}
    inline void op(T &l,T r) const{l += r;}
    inline void upd(int p,T v){
        assert(1 <= p+2 && p+2 <= n);
        for(p+=2;p<=n;p+=p&-p) op(t[p],v);
    }
    inline T qry(int p) const{
        assert(1 <= p+2 && p+2 <= n);
        T res=0;
        for(p+=2;p>0;p-=p&-p) op(res,t[p]);
        return res;
    }
    // min lb>=1 s.t. sum[lb] >= x
    inline int lower_bound(T x){
        int p = 0; T sum = 0;
        for(int i = __lg(n); i >= 0; i--){
            if((p|1<<i) <= n and sum + t[p | (1<<i)] < x){
                p |= (1<<i);
                op(sum, t[p]);
            }
        }
        ++p; // so that sum >= x
        return p-2;
    }
};