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
    dp[1] = 2;
    dp[2] = 7;

    ll mod = 1e9+7;

    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1]*2 + dp[i-2]*3) % mod;
        for(int j = 0; j <= i-3; j++){
            dp[i] = (dp[i] + dp[j]*2) % mod;
        }
    }

    cout << dp[N] << "\n";

    return 0;
}