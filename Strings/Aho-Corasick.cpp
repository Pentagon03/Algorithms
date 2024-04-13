/*
Aho Corasick Algorithm
Manage multiple pattern strings at once
O(sum(|s|) + p) instead of O(n * p) 
use map instead of arrays if u need O(m log K) transition and memory  
add_string() to add patterns
(note that we do not have to manage all patterns at once in some situations like chk_included)
- Find all strings from a given set in a text
- Finding the lexicographically smallest string of a given length that doesn't match any given strings
- Finding the shortest string containing all given strings
- Finding the lexicographically smallest string of length $L$ containing $k$ strings
reference: https://cp-algorithms.com/string/aho_corasick.html
tests:
https://www.acmicpc.net/source/share/8fa21bc44dc747f6822e77791c39838f
https://www.acmicpc.net/source/share/62e0f44ed32d4ee2a64230380f91b0e0
*/
const int K = 26;
struct Aho_Corasick{
    inline int to_int(char const&c){
        int res = c - 'a';
        assert(0 <= res && res < K);
        return res;
    }
    struct Vertex {
        int next[K];
        bool output = false;
        int output_len = 0;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        int out_cnt = -1;
        int pre_out = 0;
        int max_out_len = 0;
        Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };
    vector<Vertex> t;
    Aho_Corasick(){
        t = vector<Vertex>(1);
    }
    void add_string(string const& s) {
        int v = 0;
        for (char ch : s) {
            int c = to_int(ch);
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].output = true;
        t[v].output_len = s.length();
    }
    int get_link(int v) {
        int &link = t[v].link;
        if (link == -1) {
            if (v == 0 || t[v].p == 0) link = 0;
            else link = go(get_link(t[v].p), t[v].pch);
        }
        return link;
    }
    int go(int v, char ch) {
        int c = to_int(ch);
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
        }
        return t[v].go[c];
    }

    int get_all_out(int v){
        int &out_cnt = t[v].out_cnt;
        if(out_cnt == -1){
            out_cnt = (int)t[v].output; // do this first
            int link = get_link(v);
            out_cnt += get_all_out(link);
            if(t[link].output) t[v].pre_out = link;
            else t[v].pre_out = t[link].pre_out;
            t[v].max_out_len = max(t[v].output_len, t[link].max_out_len);
        }
        return out_cnt;
    }
    // O(|s|)
    ll count_occurence(string const&s){
        int v = 0;
        ll ans = 0;
        for(char c: s){
            v = go(v, c);
            ans += get_all_out(v);
        }
        return ans;
    }
    // O(|s|)
    void chk_included(string const&s, vector<int>&chkv){
        assert(chkv.size() == s.length() + 1);
        int v = 0;
        for(int i=0;i<s.length();i++){
            v = go(v, s[i]);
            if(get_all_out(v) > 0){
                const int mxlen = t[v].max_out_len;
                assert(mxlen > 0);
                // i - mxlen + 1 ~ i까지 사용됨
                chkv[i-mxlen+1] ++;
                chkv[i+1] --;
            }
        }
    }
};
