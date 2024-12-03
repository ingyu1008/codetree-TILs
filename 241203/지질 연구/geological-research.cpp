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
    vector<pair<int, int>> dp(N+1, {-1, 0});

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
            dp[i] = {1, 0};
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : E[u]) {
            if(dp[v].first == dp[u].first) {
                dp[v] = {dp[v].first, dp[v].second + 1};
            } else if(dp[v].first < dp[u].first) {
                dp[v] = {dp[u].first, 1};
            } else {
                dp[v] = {dp[v].first, dp[v].second};
            }
            in[v]--;
            if (in[v] == 0) {
                if(dp[v].second > 1) dp[v] = {dp[v].first + 1, 0};
                else dp[v] = {dp[v].first, 0};
                q.push(v);
            }
        }
    }

    ll mx = 0;
    
    for(int i = 1; i <= N; i++) {
        mx = max(mx, (ll)dp[i].first);
    }

    cout << mx << endl;

    return 0;
}