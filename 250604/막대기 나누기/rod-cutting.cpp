#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;
    int M = N;

    vector<int> weights(N), value(N);
    for (int i = 0; i < N; i++)
    {
        cin >> value[i];
        weights[i] = i + 1; 
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            dp[i][j] = dp[i - 1][j]; // Not taking the item
            if (j >= weights[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i][j - weights[i - 1]] + value[i - 1]); // Taking the item
            }
        }
    }

    ll max_value = 0;
    for (int j = 0; j <= M; j++)
    {
        max_value = max(max_value, dp[N][j]);
    }
    cout << max_value << endl;

    return 0;
}
