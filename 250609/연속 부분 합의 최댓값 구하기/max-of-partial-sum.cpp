#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<int> dp(N);
    dp[0] = A[0];

    for(int i = 1; i < N; i++)
    {
        dp[i] = max(A[i], dp[i - 1] + A[i]);
    }

    int ans = dp[0];
    for(int i = 0; i < N; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
