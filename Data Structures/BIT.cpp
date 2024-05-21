/*
Binary indexed Tree
set your operation function op
*/
template<typename T = int>
struct BIT{
    int n; vector<T> t;
    BIT(int _n=0):n(_n+4),t(_n+5){}
    void op(T &l,T r){l += r;}
    void upd(int p,T v){
        assert(p+2 <= n);
        for(p+=2;p<=n;p+=p&-p) op(t[p], v);
    }
    T qry(int p){
        assert(p+2 <= n);
        T res = 0;
        for(p+=2;p>0;p-=p&-p) op(res, t[p]);
        return res;
    }
};
