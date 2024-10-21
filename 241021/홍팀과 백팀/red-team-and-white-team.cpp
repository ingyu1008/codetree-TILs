#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> par;
    vector<int> sz;
    vector<int> rank;

    UF(int N): par(N+1), sz(N+1, 1), rank(N+1, 1){
        iota(par.begin(), par.end(), 0);
    }

    int find(int u){
        if(u >= par.size()) return u;
        if(u == par[u]) return u;

        return par[u] = find(par[u]);
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;

        if(rank[u] > rank[v]) swap(u, v);

        par[u] = v;
        sz[v] += sz[u];
        if(rank[u] == rank[v]) rank[v]++;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    
    UF uf(N);

    vector<array<int, 2>> E;
    vector<vector<int>> E2(N+1);

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;

        if(uf.find(u) == uf.find(v)){
            E.push_back({u, v});
            continue;
        }

        uf.unite(u, v);
        E2[u].push_back(v);
        E2[v].push_back(u);
    }

    vector<int> depth(N+1);

    function<void(int, int)> dfs = [&](int cur, int par){
        for(auto &nxt: E2[cur]){
            if(nxt == par) continue;
            depth[nxt] = depth[cur] + 1;
            dfs(nxt, cur);
        }
    };

    for(int i = 1; i <= N; i++){
        if(depth[i] == 0) dfs(i, 0);
    }

    int ans = 1;

    for(auto &[u, v]: E){
        if(uf.find(u) != uf.find(v))continue;
        if((depth[u]&1) != (depth[v]&1)) continue;
        ans = 0;
    }

    cout << ans << "\n";


    return 0;
}