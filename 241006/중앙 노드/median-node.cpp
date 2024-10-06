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
            dfs(nxt, cur);
            sz[cur] += sz[nxt];
        }

        if(children > 1 || children == 0) middle = cur;
    };

    dfs(R, 0);

    function<void(int, int)> dfs2 = [&](int cur, int par){
        sz[cur] = 1;

        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            dfs(nxt, cur);
            sz[cur] += sz[nxt];
        }
    };

    dfs2(middle, 0);

    int mx = -1;
    int mn = -1;

    for(auto &nxt: E[middle]){
        if(mx == -1){
            mx = mn = sz[nxt];
        }else {
            mx = max(mx, sz[nxt]);
            mn = min(mn, sz[nxt]);
        }
    }

    cout << mx - mn << "\n";


    return 0;
}