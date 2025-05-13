#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(M, -1e9));
    
    dp[0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int ni = i+1; ni < N; ni++){
                for(int nj = j+1; nj < M; nj++){
                    if(grid[ni][nj] > grid[i][j]){
                        dp[ni][nj] = max(dp[ni][nj], dp[i][j] + 1);
                    }
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans+1 << endl;

    return 0;
}