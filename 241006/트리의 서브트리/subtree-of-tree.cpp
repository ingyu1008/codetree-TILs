#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, R, Q;
    cin >> N >> R >> Q;

    vector<vector<int>> E(N+1);

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    vector<int> sz(N+1);
    
    function<int(int, int)> dfs = [&](int cur, int par){
        sz[cur] = 1;

        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            sz[cur] += dfs(nxt, cur);
        }

        return sz[cur];
    };

    dfs(R, 0);

    for(int i = 0; i < Q; i++){
        int u;
        cin >> u;

        cout << sz[u] << "\n";
    }

    return 0;
}