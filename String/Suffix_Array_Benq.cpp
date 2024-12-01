/**
 * Suffix Array & LCP Array
 * sa[i]: index of ith shortest suffix
 * sa[0]: sz(s) (because empty string is lexicographically first)
 * isa[i]: s[i:] is isa[i]th fastest suffix, inverse of sa (isa[sa[i]]=i), 
 * lcp[i]: longest common prefix between sa[i], sa[i+1]
 *  **CONSIDER DELETING _chk IF WRONG ANSWER** (surface_03)
 * reference: https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/strings%20(14)/Light/SuffixArray%20(14.4).h
 */
template<class str>
struct SuffixArray {
	str S;
	int N;
	vector<int> sa, isa, lcp;
    SuffixArray(){}
	SuffixArray(const str& _S) { N = size(S = _S)+1; genSa(); genLcp(); }
	void genSa() { // sa has size size(S)+1
		sa = isa = vector<int>(N);
		sa[0] = N-1;
		iota(1+all(sa),0);
		sort(1+all(sa),[&](int a, int b) { return S[a] < S[b]; });
		for(int i=1;i<N;++i) {
			int a = sa[i-1], b = sa[i];
			isa[b] = i > 1 && S[a] == S[b] ? isa[a] : i; 
		}
		for (int len = 1; len < N; len *= 2) { // currently sorted
			// by first len chars
			vector<int> s(sa), is(isa), pos(N); iota(all(pos),0);
			for(auto &t: s) {
				int T=t-len;
				if (T>=0) sa[pos[isa[T]]++] = T;
			}
			bool _chk = false;
			for(int i=1;i<N;++i) {
				int a = sa[i-1], b = sa[i]; /// verify that nothing goes out of bounds
				isa[b] = is[a]==is[b]&&is[a+len]==is[b+len]?isa[a]:i;
				if(isa[b]!=i) _chk=true;
			}
			if(not _chk) break;
		}
	}
	void genLcp() { // Kasai's Algo
		lcp = vector<int>(N-1);
		int h = 0;
		for(int b=0;b<N-1;++b) {
			int a = sa[isa[b]-1];
			while (a+h < size(S) && S[a+h] == S[b+h]) ++h;
			lcp[isa[b]-1] = h;
			if (h) h--;
		}
	}
};