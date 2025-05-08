#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<vector<int>> grid(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = INT_MAX;
    vector<int> dr = {0, 1};
    vector<int> dc = {1, 0};
    
    vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = max(dp[i-1][0], grid[i][0]);
    }

    for (int j = 1; j < N; j++)
    {
        dp[0][j] = max(dp[0][j-1], grid[0][j]);
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            dp[i][j] = min(max(dp[i-1][j], grid[i][j]), max(dp[i][j-1], grid[i][j]));
        }
    }

    ans = dp[N-1][N-1];

    cout << ans << endl;

    return 0;
}