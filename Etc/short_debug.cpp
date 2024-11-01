// https://codeforces.com/blog/entry/91347?#comment-798799
#define gg(...) [](const auto&...x){ \
char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl;\
}(__VA_ARGS__);