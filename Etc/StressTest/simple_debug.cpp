// use "g++ -D LOCAL" macro
string to_string(const string &x) {return '\"'+x+'\"';}
template <typename A>string to_string(A v) {
    bool f = true; string res = "{";
    for (const auto &x : v) {
        if (!f) res += ", ";
        f = false;
        res += to_string(x);
    }
    return res += "}";
}
void dbg_out(){cerr<<endl;}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << to_string(H);
    if(sizeof...(T))cerr<<" | ",dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr<<"["<<#__VA_ARGS__<<"]: ",dbg_out(__VA_ARGS__)
#else
#define dbg(...) 2024
#endif