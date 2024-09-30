#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> E(N+1);

    for(int i = 1; i < N; i++){
        int u, v, w;
        cin >> u >> v >> w;

        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }

    vector<int> dist(N+1, -1);
    vector<int> par(N+1, -1);
    dist[1] = 0;
    par[1] = 1;

    function<void(int)> dfs = [&](int cur){
        for(auto [nxt, weight] : E[cur]){
            if(dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + weight;
            par[nxt] = cur;
            dfs(nxt);
        }
    };

    dfs(1);

    function<int(int, int)> lca = [&](int u, int v){
        while(dist[u] != dist[v]){
            if(dist[u] > dist[v]) u = par[u];
            else if(dist[u] < dist[v]) v= par[v];
        }
        
        while(u != v){
            u = par[u];
            v = par[v];
        }

        return u;
    };

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        cout << dist[u] + dist[v] - 2*dist[lca(u, v)] << "\n";
    }

    return 0;
}