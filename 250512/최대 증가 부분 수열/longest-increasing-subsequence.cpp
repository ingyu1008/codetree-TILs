#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<pair<int, int>> dp(N + 1, {0, 0});

    dp[0] = {1, A[0]};

    for (int i = 1; i < N; i++)
    {
        dp[i] = {1, A[i]};
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                if (dp[j].first + 1 > dp[i].first)
                {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = A[i];
                }
                else if (dp[j].first + 1 == dp[i].first)
                {
                    dp[i].second = max(dp[i].second, A[i]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, dp[i].first);
    }

    cout << ans << "\n";

    return 0;
}