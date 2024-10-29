/*
Bipartite matching
이분매칭 - 이분 그래프에서 간선을 선택할건데, 각 정점은 최대 한번만 선택 가능. 선택 가능한 최대 간선 수.
최소버텍스커버 - 모든 간선의 최소 한 끝점이 선택되기 위한 최소 정점 집합
최대독립집합 - 어떤 정점도 인접하지 않은 최대 정점 집합
max_matching for matching value
get_max_matching for actual matchings (vector<pii>)
get_min_vertex_cover: [groupA/B, vertex]
get_max_independent_set: [groupA/B, vertex], complement of min_vertex_cover.
*/
struct BipartiteMatching{
    vector<int> vis, A, B;
    vector<vector<int>> g;
    int pv;
    BipartiteMatching(int n,int m): vis(m, 0), A(n,-1), B(m,-1), g(n), pv(0) {};
    void add_edge(int a,int b){
        g[a].push_back(b);
    }
    bool dfs(int x){
        for(int nx:g[x]){
            if(vis[nx]!=pv && B[nx]==-1){
                vis[nx] = pv;
                A[x] = nx;
                B[nx] = x;
                return true;
            }
        }
        for(int nx:g[x]){
            if(vis[nx]!=pv){
                vis[nx] = pv;
                if(dfs(B[nx])){
                    A[x] = nx;
                    B[nx] = x;
                    return true;
                }
            }
        }
        return false;
    }
    int max_matching(){
        pv = 0;
        int ans = 0;
        for(int i=0;i<size(g);i++){
            ++pv;
            if(dfs(i)) ++ans;
        }
        return ans;
    }
    vector<pii> get_max_matching(){
        if(pv == 0) max_matching();
        vector<pii> ans;
        for(int i=0;i<size(A);i++){
            if(A[i]!=-1){
                ans.emplace_back(i, A[i]);
            }
        }
        return ans;
    }
    vector<pii> get_min_vertex_cover(){
        if(pv == 0) max_matching();
        vector<vector<int>> g2(size(B));
        for(int i=0;i<size(A);i++){
            for(int x:g[i]){
                g2[x].push_back(i);
            }
        }
        vector<bool> chkA(size(A)), chkB(size(B));
        function<void(int,int)> dfs2 = [&](int x,int team){
            auto&chk = team?chkB:chkA;
            if(chk[x]) return;
            chk[x] = true;
            auto&rg = team?g2:g;
            for(int nx: rg[x])
                if((team == 0 && A[x] != nx) || (team == 1 && B[x] == nx))
                    dfs2(nx, !team);
        };
        for(int i=0;i<size(A);i++)
            if(A[i] == -1)
                dfs2(i, 0);
        vector<pii> ans;
        for(int i=0;i<size(A);i++)
            if(!chkA[i])
                ans.emplace_back(0, i);
        for(int i=0;i<size(B);i++)
            if(chkB[i])
                ans.emplace_back(1, i);
        return ans;
    }
    vector<pii> get_max_independent_set(){
        auto mvc = get_min_vertex_cover();
        vector<bool> chkA(size(A)), chkB(size(B));
        for(auto[c,x]: mvc)
            (c?chkB:chkA)[x] = true;
        vector<pii> ans;
        for(int i=0;i<size(A);i++)
            if(!chkA[i])
                ans.emplace_back(0, i);
        for(int i=0;i<size(B);i++)
            if(!chkB[i])
                ans.emplace_back(1, i);
        return ans;
    }
};
