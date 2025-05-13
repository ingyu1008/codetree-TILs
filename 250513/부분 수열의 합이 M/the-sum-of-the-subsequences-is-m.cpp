#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    vector<int> A(N+1);

    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(M+1, 1e9)); // dp[i][j] = i번째 수 까지 봤을 때 합이 j인 최소 길이
    dp[0][0] = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= M; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (j - A[i] >= 0)
            {
                dp[i][j] = min(dp[i][j], dp[i-1][j - A[i]] + 1);
            }
        }
    }

    if (dp[N][M] == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << dp[N][M];
    }

    return 0;
}