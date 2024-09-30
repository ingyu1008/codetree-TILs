#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> E(N+1);

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;

        E[u].push_back({v, 1});
        E[v].push_back({u, 1});
    }

    vector<int> dist(N+1, -1);
    vector<int> par(N+1, -1);

    function<void(int)> dfs = [&](int cur){
        for(auto &[nxt, cost] : E[cur]){
            if(dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + cost;
            par[nxt] = cur;
            dfs(nxt);
        }
    };

    dist[1] = 0;
    dfs(1);

    int mxidx = 1;
    for(int i = 1; i <= N; i++){
        if(dist[mxidx] <= dist[i]) mxidx = i;
    }

    fill(dist.begin(), dist.end(), -1);
    dist[mxidx] = 0;
    dfs(mxidx);

    for(int i = 1; i <= N; i++){
        if(dist[mxidx] <= dist[i]) mxidx = i;
    }
    
    int ansidx = 1;
    for(int i = 1; i <= N; i++){
        int mx = max(dist[mxidx] - dist[i], dist[i]);
        int curmx = max(dist[mxidx] - dist[ansidx], dist[ansidx]);
        if(mx < curmx) ansidx = i;
    }

    cout << max(dist[mxidx] - dist[ansidx], dist[ansidx]) << "\n";

    return 0;
}