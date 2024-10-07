#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S, D;
    cin >> N >> S >> D;

    vector<vector<int>> E(N+1);
    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    vector<int> depth(N+1);

    function<void(int, int)> dfs = [&](int cur, int par){
        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            dfs(nxt, cur);
            depth[cur] = max(depth[cur], depth[nxt]);
        }
        depth[cur]++;
    };

    int ans = 0;

    function<bool(int, int)> dfs2 = [&](int cur, int par){
        if(depth[cur] <= D){
            return false;
        }
        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            if(dfs2(nxt, cur)) ans++;
        }

        ans++;
        return true;
    };

    dfs(S, 0);
    dfs2(S, 0);

    cout << ans - 1 <<"\n";


    
    return 0;
}