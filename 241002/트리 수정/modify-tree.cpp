#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> E(N+1);
    vector<array<int, 3>> edges;

    for(int i = 1; i < N; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    auto getDiameter = [&](int u, int v, int start){
        array<int, 3> ret;
        vector<int> dist(N, -1);
        dist[start] = 0;

        function<void(int)> dfs = [&](int cur){
            for(auto [nxt, cost]: E[cur]){
                if(cur == u && nxt == v) continue;
                if(cur == v && nxt == u) continue;
                if(dist[nxt] >= 0) continue;
                dist[nxt] = dist[cur] + cost;
                dfs(nxt);
            }
        };

        dfs(start);
        for(int i = 0; i < N; i++){
            if(dist[start] <= dist[i]) start = i;
        }

        fill(dist.begin(), dist.end(), -1);
        dist[start] = 0;
        ret[0] = start;

        dfs(start);
        for(int i = 0; i < N; i++){
            if(dist[start] <= dist[i]) start = i;
        }

        ret[1] = start;
        ret[2] = dist[start];

        return ret;
    };

    auto diameter = getDiameter(-1, -1, 0);

    int ans = 0;

    for(auto &[u, v, w]: edges){
        auto d1 = getDiameter(u, v, diameter[0]);
        auto d2 = getDiameter(u, v, diameter[1]);
        
        if(max(d1[2], d2[2]) == diameter[2]){
            ans = max(ans, diameter[2] + w);
        } else {
            ans = max(ans, d1[2] + d2[2] + w);
        }
    }

    cout << ans << "\n";

    return 0;
}