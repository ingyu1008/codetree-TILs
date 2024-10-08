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

    vector<int> A(N+1);

    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    vector<int> x(N+1), y(N+1);

    function<void(int, int)> dfs = [&](int cur, int par){
        vector<int> z;

        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            dfs(nxt, cur);
            z.push_back(x[nxt]);
        }

        if(z.size() == 0){
            x[cur] = y[cur] = A[cur];
            return;
        }
        
        z.push_back(0);
        z.push_back(0);
        sort(z.rbegin(), z.rend());

        x[cur] = z[0] + A[cur];
        y[cur] = z[0] + z[1] + A[cur];
    };

    dfs(1, 0);

    int ans = -1e9;

    for(int i = 1; i <= N; i++){
        ans = max(ans, x[i]);
        ans = max(ans, y[i]);
    }

    cout << ans << "\n";

    return 0;
}