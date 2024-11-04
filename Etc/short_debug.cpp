// source: https://codeforces.com/blog/entry/91347?#comment-798799
#ifndef ONLINE_JUDGE
#define gg(...) [](const auto&...x){ \
char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl;\
}(__VA_ARGS__);
#else
#define gg(...)
#endif