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

    auto getDiameter = [&](int u, int v, int start, int end){
        array<int, 4> ret;
        vector<int> dist(N+1, -1);

        function<void(int)> dfs = [&](int cur){
            for(auto &[nxt, cost] : E[cur]){
                if(cur == u && nxt == v) continue;
                if(cur == v && nxt == u) continue;
                if(dist[nxt] >= 0) continue;
                dist[nxt] = dist[cur] + cost;
                dfs(nxt);
            }
        };

        dist[start] = 0;
        dfs(start);

        int mxidx = 1;
        for(int i = 1; i <= N; i++){
            if(dist[mxidx] <= dist[i]) mxidx = i;
        }
        ret[0] = mxidx;

        fill(dist.begin(), dist.end(), -1);
        dist[mxidx] = 0;
        dfs(mxidx);

        for(int i = 1; i <= N; i++){
            if(dist[mxidx] <= dist[i]) mxidx = i;
        }
        ret[1] = mxidx;
        ret[2] = dist[mxidx];
        ret[3] = false;
        if(dist[end] >= 0) ret[3] = true;

        return ret;
    };

    cout << getDiameter(-1, -1, 1, N)[2]  <<"\n";

    return 0;
}