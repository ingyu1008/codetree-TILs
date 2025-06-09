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
        cin >> A[i];

    vector<vector<int>> dp(4, vector<int>(N + 1, -1e9));
    dp[0][0] = 0;
    dp[0][2] = A[1];
    dp[1][1] = A[0];
    dp[1][3] = max(A[0] + A[2], A[1] + A[2]);
    dp[2][2] = A[0] + A[1];
    dp[3][3] = A[0] + A[1] + A[2];

    for(int i = 4; i <= N; i++){
        for(int j = 0; j < 4; j++){
            dp[j][i] = dp[j][i-2] + A[i-1];
            if(j > 0) dp[j][i] = max(dp[j][i], dp[j-1][i-1] + A[i-1]);
        }
    }

    int ans = 0;
    for(int i = 0; i < 4; i++)
        ans = max(ans, dp[i][N]);
    
    cout << ans << endl;


    return 0;
}
