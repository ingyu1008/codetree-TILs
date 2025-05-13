#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> coins(N+1);
    for(int i = 1; i <= N; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(M+1, 1e9));
    dp[0][0] = 0;

    for(int i = 1; i <= N; i++)
    {
        int val = coins[i];
        for(int j = 0; j <= M; j++){
            dp[i][j] = dp[i-1][j];
        }
        for(int j = val; j <= M; j++){
            dp[i][j] = min(dp[i][j], dp[i][j-val] + 1);
        }
    }

    if(dp[N][M] == 1e9)
        cout << -1 << '\n';
    else
        cout << dp[N][M] << '\n';

    return 0;
}