#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    int K;
    cin >> K;
    
    vector<vector<int>> adj(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> adj[i][j];
    }

    vector<vector<ll>> dp(1 << N, vector<ll>(N));

    function<ll(int, int, int)> solve = [&](int cur, int mask, int k) -> ll {
        if(K == k){
            return adj[cur][0] ? adj[cur][0] : 1e9;
        }

        if(dp[mask][cur] != 0)
            return dp[mask][cur];
        
        ll dist = 1e18;
        for(int i = 0; i < N; i++){
            if((mask & (1 << i)) == 0 && adj[cur][i]){
                dist = min(dist, solve(i, mask | (1 << i), k+1) + adj[cur][i]);
            }
        }

        return dp[mask][cur] = dist;
    };

    cout << solve(0, 1, 0) << '\n';

    return 0;
}