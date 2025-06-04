#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> weight(N), value(N);
    for (int i = 0; i < N; i++)
    {
        cin >> value[i] >> weight[i];
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(10101, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 10101; j++)
        {
            dp[i][j] = dp[i - 1][j]; // Not taking the i-th item
            if (j >= weight[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]); // Taking the i-th item
            }
        }
    }

    int ans = 10101;

    for(int j = 0; j <= 10100; j++)
    {
        if (dp[N][j] >= M)
        {
            ans = min(ans, j);
        }
    }

    if (ans == 10101)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    

    return 0;
}
