// Lichao Tree
// edited, source: psb0623, https://www.acmicpc.net/source/85126114
const ll INF_ = 1e18;
struct Line{
    ll a = 0, b = -INF_;
    ll operator()(ll x) {return a*x+b;}
};
// using Line = function<ll(ll)>;
struct LCT {
	ll s, e;
	Line line;
	LCT *l=0, *r=0;
	LCT(ll S, ll E):s(S),e(E){}
    inline static thread_local deque<LCT> alloc;
    static LCT* make(ll S, ll E){
        alloc.emplace_back(S, E);
        return &alloc.back();
    }
	void insert(Line f) {
		auto hi = line; auto& lo = f; ll m = s + (e-s)/2;
		if(hi(s) < lo(s)) swap(hi, lo);
		if(hi(e) >= lo(e)) { line = hi; return; }
		if(hi(m) > lo(m)) { line = hi; if(!r) r = make(m+1, e); r->insert(lo); }
		else { line = lo; if(!l) l = make(s, m); l->insert(hi); }
	}
	ll get(ll x) {
		if(s<=x&&x<=e) return max(line(x), max(l ? l->get(x) : -INF_, r ? r->get(x) : -INF_));
		else return -INF_;
	}
};
LCT* lct = LCT::make(-1e12, 1e12);
