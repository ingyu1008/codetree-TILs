#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N, M;
    cin >> N >> M;

    ll MOD = 1e9 + 7;

    vector<vector<int>> E(N+1);
    vector<int> in(N+1, 0);
    vector<int> dp(N+1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        in[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (in[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : E[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << dp[N] << '\n';

    return 0;
}