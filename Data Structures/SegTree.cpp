/*
Segment Tree Generalized
Usage: SegTree<int> st(n, less<int>(), INT_MAX); or lambda
Reference: https://codeforces.com/contest/1936/submission/249337780
*/
template<typename T, class Func = function<T(const T &, const T &)>>
struct SegTree{
    uint32_t n; vector<T> t;
    T identity;
    Func f;
    SegTree(uint32_t _n, const Func &g, T dval = T()):f(g), identity(dval){
        assert(_n >= 1);
        // n = 1;
        // while(n < _n) n <<= 1;
        n = bit_ceil(_n);
        t.assign(n*2, identity);
    }
    SegTree(const vector<T>&v, const Func &g, T dval = T()): SegTree(size(v), g, dval){
        for(int i=0;i<size(v);i++) t[i+n]=v[i];
        for(int i=n-1;i>=1;i--) t[i]=f(t[i<<1],t[i<<1|1]);
    }
    const T& get(int i) const{return t[i+n];}
    void upd(int i,T v){
        t[i+=n]=v;
        for(i>>=1;i>=1;i>>=1) t[i]=f(t[i<<1],t[i<<1|1]);
    }
    //[l, r]
    T qry(int l,int r) const{
        T resL, resR;
        resL = resR =  identity;
        for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
            if(l&1) resL = f(resL, t[l++]);
            if(~r&1) resR = f(t[r--], resR); 
        }
        return f(resL, resR);
    }
};