#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<pair<int, int>> P(N);

    for (int i = 0; i < N; i++)
    {
        cin >> P[i].first >> P[i].second;
    }

    sort(P.begin(), P.end());

    vector<vector<int>> dp(N, vector<int>(N, 1e9));
    dp[0][0] = 0;

    auto dist = [&](int a, int b)
    {
        return (P[a].first - P[b].first) * (P[a].first - P[b].first) + (P[a].second - P[b].second) * (P[a].second - P[b].second);
    };
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int k = max(i, j) + 1;

            if(k >= N) continue;

            dp[k][j] = min(dp[k][j], dp[i][j] + dist(i, k));
            dp[i][k] = min(dp[i][k], dp[i][j] + dist(j, k));
        }
    }
    int ans = 1e9;

    for (int i = 0; i < N-1; i++)
    {
        ans = min(ans, dp[i][N - 1] + dist(N - 1, i));
    }

    cout << ans << '\n';

    return 0;
}