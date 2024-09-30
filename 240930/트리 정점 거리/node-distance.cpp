#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    
    ll N, M;
    cin >> N >> M;

    vector<vector<pair<ll, ll>>> E(N+1);

    for(int i = 1; i < N; i++){
        ll u, v, w;
        cin >> u >> v >> w;

        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }

    vector<ll> dist(N+1, -1);
    vector<ll> par(N+1, -1);
    dist[1] = 0;
    par[1] = 1;

    function<void(ll)> dfs = [&](ll cur){
        for(auto [nxt, weight] : E[cur]){
            if(dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + weight;
            par[nxt] = cur;
            dfs(nxt);
        }
    };

    dfs(1);

    function<int(ll, ll)> lca = [&](ll u, ll v){
        if(dist[u] < dist[v]) swap(u, v);
        while(dist[u] != dist[v]){
            u = par[u];
            if(dist[u] < dist[v]) swap(u, v);
        }
        
        while(u != v){
            u = par[u];
            v = par[v];
        }

        return u;
    };

    for(int i = 0; i < M; i++){
        ll u, v;
        cin >> u >> v;
        cout << dist[u] + dist[v] - 2*dist[lca(u, v)] << "\n";
    }

    return 0;
}