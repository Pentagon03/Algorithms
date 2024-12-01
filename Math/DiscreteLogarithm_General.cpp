// source: https://judge.yosupo.jp/submission/51240
tuple<ll, ll, ll> extendedGcd(ll a, ll b){
	if(b == 0){
		if(a > 0) return {a, 1, 0};
		else return {-a, -1, 0};
	}else{
		auto[d, x, y] = extendedGcd(b, a%b);
		return {d, y, x - y*(a/b)};
	}
}
ll power(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1) ans = ans * a;
		b >>= 1;
		a = a * a;
	}
	return ans;
}
ll powerMod(ll a, ll b, ll mod){
	ll ans = 1;
	while(b){
		if(b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}
auto fact(ll n){
	vector<pair<ll, int>> f;
	for(ll p = 2; p*p <= n; ++p){
		int e = 0;
		while(n % p == 0){
			n /= p;
			e++;
		}
		if(e) f.emplace_back(p, e);
	}
	if(n > 1) f.emplace_back(n, 1);
	return f;
}
ll phi(ll n){
	ll ans = n;
	for(auto[p, a]: fact(n)){
		ans -= ans/p;
	}
	return ans;
}
ll multiplicativeOrder(ll a, ll m){
	assert(__gcd(a, m) == 1);
	ll ord = phi(m), ans = ord;
	for(auto[p, e] : fact(ord)){
		ll pe = power(p, e);
		ans /= pe;
		while(powerMod(a, ans, m) != 1){
			ans *= p;
		}
	}
	return ans;
}
pair<ll, ll> discreteLogarithm(ll a, ll b, ll m){
	if(m == 1) return {0, 1};
	if(a == 0){
		if(b == 0) return {1, 1};
		else if(b == 1) return {0, 0};
		else return {-1, 0};
	}
	ll m1 = m, pw = 1, div, nonRep = 0;
	for(; (div = __gcd(a, m1)) > 1; ++nonRep, m1 /= div, pw = pw * a % m){
		if(pw == b) return {nonRep, 0}; //aperiodic solution found
	}
	auto[d, x, y] = extendedGcd(pw, m);
	if(b % d > 0) return {-1, 0}; //solution not found
	b = x * (b / d) % m;
	if(b < 0) b += m;
	ll order = multiplicativeOrder(a, m1);
	ll n = sqrt(order) + 1;
	ll a_n = powerMod(a, n, m1);
	unordered_map<ll, ll> firstHalf;
	pw = a_n;
	for(ll p = 1; p <= n; ++p, pw = pw * a_n % m1){
		firstHalf[pw] = p;
	}
	pw = b % m1;
	for(ll q = 0; q <= n; ++q, pw = pw * a % m1){
		if(firstHalf.count(pw)) return {nonRep + (n * firstHalf[pw] - q) % order, order}; //periodic solution found
	}
	return {-1, 0}; //solution not found
}