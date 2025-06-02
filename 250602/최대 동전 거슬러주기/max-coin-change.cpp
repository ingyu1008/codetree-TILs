#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> dp(N+1, vector<int>(M+1, -1e9));
    dp[0][0] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            dp[i+1][j] = dp[i][j];
            if(j >= A[i]) dp[i+1][j] = max(dp[i+1][j], dp[i+1][j - A[i]] + 1);
        }
    }

    if(dp[N][M] < 0) cout << "-1\n";
    else cout << dp[N][M];

    return 0;
}