#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> E(N+1);

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    vector<int> depth(N+1, -1);
    vector<int> leaves;

    function<void(int)> dfs = [&](int cur){
        bool isleaf = true;
        for(auto &nxt : E[cur]){
            if(depth[nxt] >= 0) continue;
            isleaf = false;
            depth[nxt] = depth[cur] + 1;
            dfs(nxt);
        }

        if(isleaf) leaves.push_back(cur);
    };

    depth[1] = 0;
    dfs(1);

    int ans = 0;
    for(auto &l : leaves){
        ans += depth[l];
    }

    cout << (ans&1) << "\n";

    return 0;
}