// Disjoint Set here.

template<typename T, typename E = tuple<int, int, T>>
vector<E> MST(int n, const vector<E>& edges){
    DisjointSet dsu(n);
    vector<E> mst;
    auto _edges = edges;
    ranges::sort(_edges);
    for(auto&[a, b, w]: _edges){
        if(dsu.merge(a, b)){
            mst.push_back({a, b, w});
        }
    }
    return mst;
}