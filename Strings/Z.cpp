// source: kactl
// z[i]: length of the longest common prefix of s[i:] and s (최대 공통 접두사)
vector<int> Z(const auto& S) {
    int n = sz(S);
	vector<int> z(n); z[0] = n;
	int l = -1, r = -1;
	for(int i=1;i<n;i++){
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < n && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}
// max. pat's prefix = s's prefix
vector<int> zmatch(const auto& s, const auto& pat) {
	auto z = Z(pat + char(0) + s);
	return vector<int>(z.begin() + sz(p) - sz(s), z.end());
}