#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<vector<pair<ll, ll>>> E(N+1);
    vector<array<ll, 3>> edges;

    for(int i = 1; i < N; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    auto getDiameter = [&](int u, int v, int start, int end){
        array<ll, 4> ret;
        vector<ll> dist(N, -1);

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

        int mxidx = 0;
        for(int i = 0; i < N; i++){
            if(dist[mxidx] <= dist[i]) mxidx = i;
        }
        ret[0] = mxidx;

        fill(dist.begin(), dist.end(), -1);
        dist[mxidx] = 0;
        dfs(mxidx);

        for(int i = 0; i < N; i++){
            if(dist[mxidx] <= dist[i]) mxidx = i;
        }
        ret[1] = mxidx;
        ret[2] = dist[mxidx];
        ret[3] = false;
        if(dist[end] >= 0) ret[3] = true;

        return ret;
    };

    auto diameter = getDiameter(-1, -1, 0, 0);

    ll ans = 0;

    for(auto &[u, v, w]: edges){
        auto d1 = getDiameter(u, v, diameter[0], diameter[1]);
        auto d2 = getDiameter(u, v, diameter[1], diameter[0]);

        if(d1[3] && d2[3]) continue;
        ans = max(ans, d1[2] + d2[2] + w);
    }

    cout << ans << "\n";

    return 0;
}