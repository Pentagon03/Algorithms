template<typename T, typename Graph>
vector<T> dijkstra(int src, T INF, const Graph& g){
    struct S{
        int x; T dis;
        bool operator <(const S &rht) const{
            return dis > rht.dis;
        }
    };
    int n = size(g);
    vector d(n, INF);
    priority_queue<S> pq;
    pq.push(S{src, d[src] = T()}); 
    while(not empty(pq)){
        auto[x, dis] = pq.top(); pq.pop();
        if(dis > d[x]) continue;
        for(auto[nx, w]: g[x]){
            int ndis = dis + w;
            if(ndis < d[nx]){
                pq.push(S{nx, d[nx] = ndis});
            }
        }
    }
    return d;
}