#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector<vector<int>> grid(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = INT_MAX;
    vector<int> dr = {0, 1};
    vector<int> dc = {1, 0};

    for(int mn = 1; mn <= 100; mn++){
        for(int mx = mn; mx <= 100; mx++){
            bool reachable = false;
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(N, vector<bool>(N, false));

            if(grid[0][0] < mn || grid[0][0] > mx) continue;
            if(grid[N - 1][N - 1] < mn || grid[N - 1][N - 1] > mx) continue;

            q.push({0, 0});
            visited[0][0] = true;

            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                if(r == N - 1 && c == N - 1){
                    reachable = true;
                    break;
                }

                for(int d = 0; d < 2; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]){
                        if(grid[nr][nc] >= mn && grid[nr][nc] <= mx){
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }

            if(reachable){
                ans = min(ans, mx - mn);
            }
        }
    }

    cout << ans << "\n";


    return 0;
}