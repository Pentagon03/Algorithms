// z[i]: length of the longest common prefix of s[i:] and s (최대 공통 접두사)
vi Z(const string& S) {
        int n = sz(S);
	vi z(n); z[0] = n;
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
vi zmatch(const string& s, const string& pat) {
	vi p = Z(pat + '\0' + s);
	return vi(p.begin() + sz(p) - sz(s), p.end());
}