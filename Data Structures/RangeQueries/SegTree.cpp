/* Segtree with point update
S: monoid for tree
S op(S a, S b): monoid action
S e() : identity of S
*/

// Example: S : Range add
using S = int;
S op(S a, S b){return a + b;}
S e(){return 0;}

// template<class S, S (*op)(S, S), S (*e)()>
struct Seg{
    public:
    Seg(int n = 0): Seg(vector (n, e())){}
    Seg(const vector<S>&v){
        // n = bit_ceil(size(v));
        n = size(v);
        tree = vector (n<<1, e());
        ranges::copy(v, begin(tree)+n);
        for(int i=n-1;i>=1;i--) pull(i);
    }
    const S& get(int i) const{return tree[i+n];}
    void set(int i, S val){
        tree[i+=n] = val;
        for(i>>=1;i>=1;i>>=1) pull(i);
    }
    S qry_all(){return tree[1];}
    //[l, r]
    S qry(int l,int r) const{
        S resL, resR;
        resL = resR = e();
        for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
            if(l&1) resL = op(resL, tree[l++]);
            if(~r&1) resR = op(tree[r--], resR); 
        }
        return op(resL, resR);
    }
    private:
    int n;
    vector<S> tree;
    void pull(int i){
        tree[i] = op(tree[i<<1], tree[i<<1|1]);
    }
};