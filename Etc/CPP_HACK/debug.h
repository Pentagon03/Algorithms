/*
// shorter benq version
template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),decltype(end(declval<T>()))>> : true_type {};
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v) {
    cout << "["; 
    for (auto it = v.begin(); it != v.end();) {
        cout << *it;
        if (++it != v.end()) cout << ", ";
    }
    return cout << "]";
}
*/
// Edited, Source = https://codeforces.com/blog/entry/125435
#ifndef DEBUG_TEMPLATE_CPP

#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
// #define cerr cout
namespace __DEBUG_UTIL__
{
    using namespace std;
    template <class T>
    concept is_string =
        is_same_v<remove_cvref_t<T>, string> ||
        is_same_v<decay_t<T>, char*> ||
        is_same_v<decay_t<T>, const char*>;
    template <class T>
    concept is_iterable = requires(T &&x) { begin(x); end(x); } && !is_string<T>;
    inline void print(const char *x) { cerr << x; }
    inline void print(char x) { cerr << "\'" << x << "\'"; }
    inline void print(bool x) { cerr << (x ? "T" : "F"); }
    inline void print(string x) { cerr << "\"" << x << "\""; }
    inline void print(vector<bool> &v)
    { /* Overloaded this because stl optimizes vector<bool> by using
         _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    template <typename T>
    concept Integral128 = std::is_same_v<decay_t<T>, __int128_t> || std::is_same_v<decay_t<T>, __uint128_t>;

    template <Integral128 T>
    inline void print(T ans){
        bool is_minimum = (ans<0) && ((ans<<1) == 0); // check whether this is the minimum of data type
        string res;
        bool neg_flag = false;
        if(ans<0){
            neg_flag = true;
            if(is_minimum) ans = ~ans;
            else ans *= -1;
        }
        do res.push_back(ans % 10 + '0'), ans/=10; while(ans>0);
        if(is_minimum) ++res[0]; // we assume this is not 9, in-fact, c++ integer type {min}'s last digit is always '8'
        if(neg_flag) res.push_back('-');
        reverse(begin(res), end(res));
        cerr << res;
    }

    template <typename T> requires (!Integral128<T>)
    inline void print(T && x)
    {
        if constexpr (is_iterable<T>)
            if (size(x) && is_iterable<decltype(*(begin(x)))>)
            { /* Iterable inside Iterable */
                int f = 0;
                cerr << "\n~~~~~\n";
                for (auto &&i : x)
                {
                    cerr << setw(2) << left << f++, print(i), cerr << "\n";
                }
                cerr << "~~~~~\n";
            }
            else
            { /* Normal Iterable */
                int f = 0;
                cerr << "{";
                for (auto &&i : x)
                    cerr << (f++ ? "," : ""), print(i);
                cerr << "}";
            }
        else if constexpr (requires { x.pop(); }) /* Stacks, Priority Queues, Queues */
        {
            auto temp = x;
            int f = 0;
            cerr << "{";
            if constexpr (requires { x.top(); })
                while (!temp.empty())
                    cerr << (f++ ? "," : ""), print(temp.top()), temp.pop();
            else
                while (!temp.empty())
                    cerr << (f++ ? "," : ""), print(temp.front()), temp.pop();
            cerr << "}";
        }
        else if constexpr (requires { x.first; x.second; }) /* Pair */
        {
            cerr << '(', print(x.first), cerr << ',', print(x.second), cerr << ')';
        }
        else if constexpr (requires { get<0>(x); }) /* Tuple */
        {
            int f = 0;
            cerr << '(', apply([&f](auto... args)
                               { ((cerr << (f++ ? "," : ""), print(args)), ...); },
                               x);
            cerr << ')';
        }
        else
            cerr << x;
    }
    template <typename T, typename... V>
    inline void printer(const char *names, T &&head, V &&...tail)
    {
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(forward<T>(head));
        if constexpr (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    template <typename T, typename... V>
    inline void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t i = 0;
        for (; names[i] and names[i] != ','; i++)
            cerr << names[i];
        for (i++; names[i] and names[i] != ','; i++)
            ;
        cerr << " = {";
        for (size_t ind = 0; ind < N; ind++)
            cerr << (ind ? "," : ""), print(arr[ind]);
        cerr << "}";
        if constexpr (sizeof...(tail))
            cerr << " ||", printerArr(names + i + 1, tail...);
        else
            cerr << "]\n";
    }

}


#ifdef _DEBUG
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#ifdef Pentagon03
#define dbg(...) std::cerr<<"tc"<<cur_tc<<" > "; debug(__VA_ARGS__)
#define dbg_n(...) std::cerr<<"tc"<<cur_tc<<" > "; debugArr(__VA_ARGS__)
#else
#define dbg(...) debug(__VA_ARGS__)
#define dbg_n(...) debugArr(__VA_ARGS__)
#endif


#endif