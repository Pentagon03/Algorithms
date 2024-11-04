// source: https://codeforces.com/blog/entry/91347?#comment-798799
#ifndef ONLINE_JUDGE
#define gg(...) [](const auto&...x){ \
char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl;\
}(__VA_ARGS__);
#else
#define gg(...)
#endif

// source: swoon
template<class T>
void prt(T &&v) { cout << forward<T>(v) << '\n'; }
template<class T, class... Args>
void prt(T &&v, Args &&...args) {
    cout << forward<T>(v) << ' ';
    prt(forward<Args>(args)...);
};

#include<Pentagon03/debug.h>
