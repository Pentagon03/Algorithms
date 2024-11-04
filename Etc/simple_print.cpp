// source: swoon, pentagon03
template<class T>
void prt(T &&v) { cout << forward<T>(v); }

template <class T>
concept is_iterable = requires(T &&x) { begin(x); end(x); } &&
                      !is_same_v<remove_cvref_t<T>, string>;

template<is_iterable T>
void prt(T &&container) {
    for (auto &&element : container) {
        using E = decltype(element);
        prt(forward<E>(element));  // 각 원소를 prt에 넘김
        cout << (is_iterable<E> ? '\n': ' ');
    }
}

template<class T, class... Args>
void prt(T &&v, Args &&...args) {
    prt(forward<T>(v)); 
    if(not is_iterable<T>) prt(' ');
    prt(forward<Args>(args)...);
}