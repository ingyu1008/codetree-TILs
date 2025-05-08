#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));

    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};

    priority_queue<array<int, 3>> pq;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            pq.push({1, i, j});
            dp[i][j] = 1;
        }
    }

    while(!pq.empty()){
        auto [cur, r, c] = pq.top();
        pq.pop();

        if (dp[r][c] > cur){
            continue;
        }

        for (int d = 0; d < 4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N){
                continue;
            }

            if (grid[nr][nc] > grid[r][c]){
                if(dp[nr][nc] < cur + 1){
                    dp[nr][nc] = cur + 1;
                    pq.push({dp[nr][nc], nr, nc});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";



    return 0;
}