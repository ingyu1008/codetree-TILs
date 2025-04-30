#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<ll> dp(N+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }

    cout << dp[N] << '\n';

    return 0;
}