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

    for(int i = 2; i <= N; i++){
        dp[i] = 0;
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    cout << dp[N] << "\n";

    return 0;
}