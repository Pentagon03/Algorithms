// reference: https://sotanishy.github.io/cp-library-cpp/misc/compress.hpp.html
template<class T>
struct Compresser{
    vector<T> t;
    Compresser() = default;
    Compresser(const vector<T> &v): t(v){}
    void add(const auto&... x){ ((t.push_back(x)), ...); }
    void compress(){
        ranges::sort(t);
        t.erase(begin(ranges::unique(t)), end(t));
    }
    int compress(const T& x) const {
        return ranges::distance(begin(t), ranges::lower_bound(t, x));
    }
    void compress(vector<T> &v) const {
        ranges::transform(v, begin(v), [&](T x){return compress(x);});
    }
    const T& val(int i) const { return t[i]; }
    int size() const{ return t.size(); }
};