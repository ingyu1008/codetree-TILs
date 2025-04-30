#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> dp(N+1);

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;

    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-2]*4 + dp[i-1]*2) % 10007;
    }

    cout << dp[N] << "\n";

    return 0;
}