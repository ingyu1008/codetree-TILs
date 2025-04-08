#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> E(N + 1);

    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    vector<int> dist(N + 1, 1e9);
    dist[1] = 0;

    function<void(int, int)> dfs = [&](int cur, int par){
        for(int nxt : E[cur])
        {
            if(nxt == par) continue;
            if(dist[nxt] <= dist[cur] + 1) continue;
            dist[nxt] = min(dist[nxt], dist[cur] + 1);
            dfs(nxt, cur);
        }
    };

    dfs(1, 0);

    int ans = 0;
    for(int i = 2; i <= N; i++)
    {
        if(dist[i] == 1e9) continue;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}