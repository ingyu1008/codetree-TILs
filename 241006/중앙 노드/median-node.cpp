#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, R;
    cin >> N >> R;

    vector<vector<int>> E(N+1);

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int middle = R;

    vector<int> sz(N+1, 1);

    function<void(int, int)> dfs = [&](int cur, int par){
        sz[cur] = 1;

        int children = 0;

        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            children++;
            if(children > 1 && middle == par) middle = cur;
            dfs(nxt, cur);
            sz[cur] += sz[nxt];
        }
    };

    dfs(R, 0);

    // cout << middle << "\n";

    int mx = -1e9;
    int mn = 1e9;

    for(auto &nxt: E[middle]){
        if(sz[nxt] > sz[middle]) continue;
        mx = max(mx, sz[nxt]);
        mn = min(mn, sz[nxt]);
    }


    cout << mx - mn << "\n";


    return 0;
}