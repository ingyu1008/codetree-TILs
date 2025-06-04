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

    vector<vector<int>> dp(N + 1, vector<int>(200001, -1e9));

    dp[0][100000] = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 200001; j++){
            if(dp[i][j] == -1e9) continue;

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]); // skip the current element
            if(j + A[i] < 200001) {
                dp[i+1][j + A[i]] = max(dp[i+1][j + A[i]], dp[i][j] + A[i]); // take the current element
            }
            if(j - A[i] >= 0) {
                dp[i+1][j - A[i]] = max(dp[i+1][j - A[i]], dp[i][j] + A[i]); // take the current element
            }
        }
    }
    
    cout << dp[N][100000] / 2 << endl;    

    

    return 0;
}
