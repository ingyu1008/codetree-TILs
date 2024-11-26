#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N, M;
    cin >> N >> M;

    vector<ll> P(N+1);

    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
    }

    set<int> S;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        S.insert(a);
    }

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 1e18));
    dp[0][0] = 0;

    auto dist = [&](int a, int b)
    {
        if(a == 0 || b == 0) return 0LL;
        return abs(P[a] - P[b]);
    };
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            int k = max(i, j) + 1;

            if(k > N) continue;

            dp[k][j] = min(dp[k][j], dp[i][j] + dist(i, k));

            if(S.find(k) == S.end()) dp[i][k] = min(dp[i][k], dp[i][j] + dist(j, k));
        }
    }
    ll ans = 1e18;

    for (int i = 0; i < N; i++)
    {
        ans = min(ans, dp[i][N]);
    }

    cout << ans << '\n';

    return 0;
}