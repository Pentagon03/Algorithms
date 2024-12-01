/*
Suffix array and LCP construction
SA: suffix들을 사전 순으로 정렬해놓은 배열
LCP: Longest Common Prefix의 길이, 다만 인접한 것들만 봄
이제 LCP(i) Suffix array에서 i번째와 i+1번째 최대 긴 Prefix의 길이.
AWARE: string shouldn't character same as additional char for cyclic shift. -> char(1) in our case
if you want to make longer ones to latter, make it char(255) rather than char(1) and erase prev(end()) rather than begin() (think of it..)
string s; cin>>s;
auto sfa = suffix_array_construction(s);
auto lcp = lcp_construction(s, sfa);
sfa[i]: ith lexicographically small suffix
lcp[i]: longest common prefix between sfa[i-1] and sfa[i]
(lcp[0] == 0)
reference: https://cp-algorithms.com/string/suffix-array.html
*/
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        if(cn[p[n-1]] == n-1) break; // we found every distinct suffixes
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += char(1);
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}


vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n, 0); // segfault issue
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i] + 1] = k;
        if (k) k--;
    }
    return lcp;
}

vector<int> lcp_construction(string const& s){
    return lcp_construction(s, suffix_array_construction(s));
}