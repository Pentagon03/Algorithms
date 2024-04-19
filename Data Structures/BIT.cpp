template<typename T = int>
struct BIT{
    int n; vector<T> t;
    BIT(int _n=0):n(_n),t(_n+1){}
    void op(T &l,T r){l += r;}
    void upd(int p,T v){
        for(;p<=n;p+=p&-p)
            op(t[p], v);
    }
    T qry(int p){
        T res = 0;
        for(;p>0;p-=p&-p)
            op(res, t[p]);
        return res;
    }
};
