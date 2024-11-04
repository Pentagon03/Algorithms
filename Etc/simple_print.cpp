/** print function that can print any element or iterable
 * source: swoon. edited by pentagon03
 * set 'debug_ = 1' to change from cout to cerr
 * ex)
 * vector<vector<int>> v = {{1,2,3}, {3,4,5}, {5,6,7}};
 * int a = 3; double b = 3.14; string c = "asdf";
 * print(v, a, b, c);
 */
constexpr bool debug_ = 0;
template<class T>
void print(T &&v) { (debug_?cerr:cout) << forward<T>(v); }

template <class T>
concept is_iterable = requires(T &&x) { begin(x); end(x); } &&
                      !is_same_v<remove_cvref_t<T>, string>;

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
    if(not is_iterable<T>) print(' ');
    print(forward<Args>(args)...);
}