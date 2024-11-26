// pi[i]: longest common prefix-suffix(excluding itself) of s[:i+1]
vector<int> pi(const auto& s) {
	vector<int> p(size(s));
	for(int i=1;i<size(s);i++){
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}
// max. pat's prefix = s's suffix
vector<int> match(const auto& s, const auto& pat) {
	auto p = pi(pat + '\0' + s);
    return vi(p.begin() + size(p) - size(s), p.end());
}