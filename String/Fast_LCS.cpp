/*
Get LCS(Longest Common Subsequence) of string A, B in O(|A|(|B|/|W|)), where |W| is word size, 64
We use bitset opt and Hirschberg's Algorithm for recovering
used unsigned long long arrays for bitset implementation
IMPORTANT:  set base variables below before using
MXN: max size of string B
MX_ALP: number of possible alphabets
BASE_ALP: the minimum ascii value among all alphabets
reference: https://github.com/infossm/infossm.github.io/blob/master/_posts/2019-09-13-lcs-with-bitset.md
test: https://www.acmicpc.net/problem/18440
*/
namespace FAST_LCS{
    const int MXN = 5e4 + 10;
    const int MX_ALP = 26;
    const char BASE_ALP = 'A';

    using ull = unsigned long long;
    ull dt[(MXN>>6)+1], S[MX_ALP][(MXN>>6)+1];
    inline bool _test(ull arr[],int x){
        return (bool)(arr[x>>6] & (1ULL << (x&63)));
    }
    inline void _set(ull arr[],int x){
        arr[x>>6] |= 1ULL << (x&63);
    }

    #include<immintrin.h>
    vector<int> getLCSdp(const string &A,const string &B){
        int n=A.size(),m=B.size(),ans=0;
        int siz = (m>>6)+1;

        // Init
        for(int i=0;i<siz;i++) dt[i] = 0;
        for(int i=0;i<MX_ALP;i++) for(int j=0;j<siz;j++) S[i][j] = 0;
        
        for(int i=0;i<m;i++) S[B[i]-BASE_ALP][i>>6]|=1ULL<<(i&63);
        for(int i=0;i<n;i++){
            for(int j=0, c=1, mc=0; j<siz;j++){
                ull x = dt[j] | S[A[i]-BASE_ALP][j], y;
                mc = _subborrow_u64(mc, x, (dt[j]<<1)|c, &y);
                c = dt[j] >> 63;
                dt[j] = x & (x^y);
            }
        }
        vector<int> v(m+1);
        for(int i=0;i<m;i++) v[i+1] = v[i] + !!(dt[i>>6] & (1ULL<<(i&63)));
        return v;
    }
    std::string getLCS(const string &A,const string &B){ // recover actual LCS of A and B using Hirschberg's Algorithm
        int n = A.size(), m = B.size();
        string ans = "";
        if(!m) return ans;
        if(n==1){
            for(int i=0;i<m;i++)
                if(B[i]==A[0]){
                    ans = string(1,A[0]);
                    break;
                }
        }else if(m==1){
            for(int i=0;i<n;i++)
                if(A[i]==B[0]){
                    ans = string(1,B[0]);
                    break;
                }
        }else{ // n>1 && m>1
            int mid = n/2;
            string A1 = A.substr(0,mid);
            string A2 = A.substr(mid,n-mid);
            reverse(all(A2));
            string B1, B2 = B;
            reverse(all(B2));
            vector<int>&&dp1 = getLCSdp(A1,B);
            vector<int>&&dp2 = getLCSdp(A2,B2);
            int best = 0;
            for(int i=0;i<=m;i++)
                if(dp1[i]+dp2[m-i] > dp1[best]+dp2[m-best])
                    best = i;
            B1 = B.substr(0,best);
            B2 = B.substr(best,m-best);
            reverse(all(A2));
            ans = getLCS(A1,B1) + getLCS(A2,B2);
        }
        return ans;
    }
}
