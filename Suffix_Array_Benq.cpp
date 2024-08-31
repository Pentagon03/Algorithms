https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/strings%20(14)/Light/SuffixArray%20(14.4).h
/**
 * Description: Sort suffixes. First element of \texttt{sa} is \texttt{sz(S)},
 	* \texttt{isa} is the inverse of \texttt{sa}, and \texttt{lcp} stores
 	* the longest common prefix between every two consecutive elements of \texttt{sa}.
 * Time: O(N\log N)
 * Source: SuprDewd, KACTL, majk, ekzhang (http://ekzlib.herokuapp.com)
 * Verification: 
	* https://open.kattis.com/problems/suffixsorting
	* https://judge.yosupo.jp/problem/suffixarray
 */

#include "RMQ.h"

struct SuffixArray {
	str S; int N; vi sa, isa, lcp;
	void init(str _S) { N = sz(S = _S)+1; genSa(); genLcp(); }
	void genSa() { // sa has size sz(S)+1, starts with sz(S)
		sa = isa = vi(N); sa[0] = N-1; iota(1+all(sa),0);
		sort(1+all(sa),[&](int a, int b) { return S[a] < S[b]; });
		FOR(i,1,N) { int a = sa[i-1], b = sa[i];
			isa[b] = i > 1 && S[a] == S[b] ? isa[a] : i; }
		for (int len = 1; len < N; len *= 2) { // currently sorted
			// by first len chars
			vi s(sa), is(isa), pos(N); iota(all(pos),0); 
			each(t,s) {int T=t-len;if (T>=0) sa[pos[isa[T]]++] = T;}
			FOR(i,1,N) { int a = sa[i-1], b = sa[i]; /// verify that nothing goes out of bounds
				isa[b] = is[a]==is[b]&&is[a+len]==is[b+len]?isa[a]:i; }
		}
	}
	void genLcp() { // Kasai's Algo
		lcp = vi(N-1); int h = 0;
		F0R(b,N-1) { int a = sa[isa[b]-1];
			while (a+h < sz(S) && S[a+h] == S[b+h]) ++h;
			lcp[isa[b]-1] = h; if (h) h--; }
		R.init(lcp); /// if we cut off first chars of two strings
		/// with lcp h then remaining portions still have lcp h-1 
	}
	RMQ<int> R; 
	int getLCP(int a, int b) { // lcp of suffixes starting at a,b
		if (a == b) return sz(S)-a;
		int l = isa[a], r = isa[b]; if (l > r) swap(l,r);
		return R.query(l,r-1);
	}
};



OR 

#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
struct SA{
    string s; int n; vector<int> sa, isa, lcp;
    void init(string _s){
        s = _s;
        n = s.size() + 1;
        makeSA(); makeLCP();
    }
    void makeSA(){
        sa = isa = vector<int>(n);
        sa[0] = n-1; isa[n-1] = 0; 
        iota(1+all(sa), 0);
        sort(1 + all(sa), [&](int a,int b){
            return s[a] < s[b];
        });
        for(int i=1;i<=n;i++){
            int a = sa[i-1], b = sa[i];
            isa[b] = i>1 and s[a] == s[b] ? isa[a] : i;
        }
        for(int len = 1; len < n; len *= 2){
            vector<int> sa2(sa), isa2(isa), pos(n);
            iota(all(pos), 0);
            for(int t: sa2){
                int T = t - len;
                if(T >= 0) sa[pos[isa[T]]++] = T;
            }
            for(int i=1;i<=n;i++){
                int a = sa[i-1], b = sa[i];
                isa[b] = isa2[a] == isa2[b] and isa2[a+len] == isa2[b+len] ? isa[a] : i;
            }
        }
    }
    void makeLCP(){
        lcp = vector<int>(n-1); int h = 0;
        for(int b=0;b<n-1;b++){
            int a = sa[isa[b] - 1];
            while(a+h < s.size() and s[a+h] == s[b+h]) ++h;
            lcp[isa[b] - 1] = h;
            if(h) h--;
        }
        // make sparse table
    }
    int rmq(vector<int> lcp, int l, int r){
        int ans;
        // get rmq
        return ans;
    }
    int getLCP(int a,int b){
        if(a == b) return s.size() - a;
        int l = isa[a], r = isa[b];
        return rmq(lcp, l, r-1);
    }
};

