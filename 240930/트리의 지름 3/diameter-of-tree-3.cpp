#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> E(N+1);

    for(int i = 1; i < N; i++){
        int u, v, w;
        cin >> u >> v >> w;

        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }

    vector<int> dist(N+1, -1);

    function<void(int)> dfs = [&](int cur){
        for(auto &[nxt, cost] : E[cur]){
            if(dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + cost;
            dfs(nxt);
        }
    };

    dist[1] = 0;
    dfs(1);

    int mxidx = 1;
    for(int i = 1; i <= N; i++){
        if(dist[mxidx] <= dist[i]) mxidx = i;
    }

    int X = mxidx;

    fill(dist.begin(), dist.end(), -1);
    dist[mxidx] = 0;
    dfs(mxidx);

    for(int i = 1; i <= N; i++){
        if(dist[mxidx] <= dist[i]) mxidx = i;
    }
    
    int Y = mxidx;
    mxidx = X;

    for(int i = 1; i <= N; i++){
        if(dist[mxidx] <= dist[i] && i != Y) mxidx = i;
    }

    int cand = dist[mxidx];

    fill(dist.begin(), dist.end(), -1);
    dist[Y] = 0;
    dfs(Y);

    mxidx = Y;
    for(int i = 1; i <= N; i++){
        if(dist[mxidx] <= dist[i] && i != X) mxidx = i;
    }

    cand = max(cand, dist[mxidx]);

    cout << cand << "\n";
    
    

    return 0;
}