#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<ll> P(N);

    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    vector<vector<ll>> dp(N, vector<ll>(N, 1e18));
    dp[0][0] = 1e18;
    dp[0][1] = 0;
    dp[1][0] = 0;

    auto dist = [&](int a, int b)
    {
        return abs(P[a] - P[b]);
    };
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            int k = max(i, j) + 1;

            if(k >= N) continue;

            dp[k][j] = min(dp[k][j], dp[i][j] + dist(i, k));
            dp[i][k] = min(dp[i][k], dp[i][j] + dist(j, k));
        }
    }
    ll ans = 1e18;

    for (int i = 0; i < N-1; i++)
    {
        ans = min(ans, dp[i][N - 1]);
    }

    cout << ans << '\n';

    return 0;
}