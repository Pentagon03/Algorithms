/** print function that can print any element or iterable
 * source: pentagon03, idea: swoon
 * set 'debug_ = 1' to change from cout to cerr
 * Note: ONLY printing (iterables of iterables) will print '\n' at the end
 * example
 * vector<vector<int>> v = {{1,2,3}, {3,4,5}, {5,6,7}};
 * int a = 3; double b = 3.14; string c = "asdf";
 * print("wow", v, a, b, c);
 */
constexpr bool debug_ = 0;

template<class T>
void print(T &&v) { (debug_?cerr:cout) << forward<T>(v); }

template <class T>
concept is_string = 
    is_same_v<remove_cvref_t<T>, string> ||
    is_same_v<decay_t<T>, char*> || 
    is_same_v<decay_t<T>, const char*>;

template <class T>
concept is_iterable = requires(T &&x) { begin(x); end(x); } && !is_string<T>;

template<is_iterable T>
void print(T &&container) {
    for (auto &&element : container) {
        using E = decltype(element);
        print(forward<E>(element));
        print(is_iterable<E> ? '\n': ' ');
    }
}

template<class T, class... Args>
void print(T &&v, Args &&...args) {
    print(forward<T>(v)); 
    print(' ');
    print(forward<Args>(args)...);
}