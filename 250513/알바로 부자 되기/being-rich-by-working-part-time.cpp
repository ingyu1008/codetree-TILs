#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<array<int, 3>> input(N);

    for (int i = 0; i < N; i++)
    {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }
    sort(input.begin(), input.end());

    vector<int> dp(N);

    for (int i = 0; i < N; i++)
    {
        dp[i] = input[i][2];
        for (int j = 0; j < i; j++)
        {
            if (input[j][1] < input[i][0])
            {
                dp[i] = max(dp[i], dp[j] + input[i][2]);
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";


    return 0;
}