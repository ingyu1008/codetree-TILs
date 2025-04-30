#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            } else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1] << "\n";

    return 0;
}