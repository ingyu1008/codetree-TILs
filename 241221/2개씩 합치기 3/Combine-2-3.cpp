#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int K;
    cin >> K;
    vector<int> pSum(505);
    vector<vector<int>> dp(505, vector<int>(505));

    for (int i = 1; i <= K; i++)
    {
        cin >> pSum[i];
        pSum[i] += pSum[i - 1];
    }

    for (int i = 1; i < K; i++)
    {
        for (int s = 1; s <= K - i; s++)
        {
            int e = s + i;
            for (int j = s; j < e; j++)
            {
                int temp = dp[s][j] + dp[j + 1][e] + pSum[e] - pSum[s - 1];
                if (dp[s][e] == 0 || dp[s][e] > temp)
                {
                    dp[s][e] = temp;
                }
            }
        }
    }
    cout << dp[1][K] << "\n";

    return 0;
}