#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<pair<ll, ll>> P(N);

    for (int i = 0; i < N; i++)
    {
        cin >> P[i].first >> P[i].second;
    }

    sort(P.begin(), P.end());

    vector<vector<ll>> dp(N, vector<ll>(N, 1e18));
    dp[0][0] = 0;

    auto dist = [&](int a, int b)
    {
        return (P[a].first - P[b].first) * (P[a].first - P[b].first) + (P[a].second - P[b].second) * (P[a].second - P[b].second);
    };

    for (int cur = 1; cur < N; cur++)
    {
        for (int other = 0; other < cur; other++)
        {
            dp[cur][other] = min(dp[cur][other], dp[cur - 1][other] + dist(cur, cur - 1));
            dp[cur - 1][cur] = min(dp[cur - 1][cur], dp[cur - 1][other] + dist(cur, other));
        
            dp[other][cur] = min(dp[other][cur], dp[other][cur - 1] + dist(cur, cur - 1));
            dp[cur][cur - 1] = min(dp[cur][cur - 1], dp[other][cur - 1] + dist(cur, other));
        }
    }
    
    ll ans = 1e18;

    for (int i = 0; i < N; i++)
    {
        ans = min(ans, dp[N - 1][i] + dist(N - 1, i));
    }

    cout << ans << '\n';

    return 0;
}