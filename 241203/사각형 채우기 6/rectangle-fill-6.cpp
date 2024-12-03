#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dp(M*N, vector<int>((1 << M), -1));

    int mod = 10007;

    function<int(int, int)> solve = [&](int idx, int mask) -> int {
        if(idx == M*N) return mask == 0;
        if(idx > M*N) return 0;
        if(dp[idx][mask] != -1) return dp[idx][mask];

        if(mask & 1) return dp[idx][mask] = solve(idx + 1, mask >> 1);

        int ret = solve(idx + 1, (mask >> 1) + (1 << (M-1)));

        if((mask & 2) == 0 && idx % (M) != M-1){
            ret += solve(idx + 2, (mask >> 2));
        }

        return dp[idx][mask] = ret % mod;
    };

    cout << solve(0, 0) << '\n';

    return 0;
}