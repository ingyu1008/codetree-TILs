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

    vector<int> dp(N, -100000);
    dp[0] = 0;
    int ans = 0;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j <= i + A[i] && j < N; j++){
            dp[j] = max(dp[j], dp[i] + 1);
            ans = max(ans, dp[j]);
        }
    }

    cout << ans << endl;

    return 0;
}