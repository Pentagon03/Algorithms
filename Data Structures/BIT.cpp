/*
Binary indexed Tree
set your operation function op
*/
template<typename T = int>
struct BIT{
    int n; vector<T> t;
    BIT(int _n=0):n(_n+4),t(n+1){}
    inline void op(T &l,T r){l += r;}
    inline void upd(int p,T v){
        assert(1 <= p+2 && p+2 <= n);
        for(p+=2;p<=n;p+=p&-p) op(t[p],v);
    }
    inline T qry(int p){
        assert(1 <= p+2 && p+2 <= n);
        T res=0;
        for(p+=2;p>0;p-=p&-p) op(res,t[p]);
        return res;
    }
};