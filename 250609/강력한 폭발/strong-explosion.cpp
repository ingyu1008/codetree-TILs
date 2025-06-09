#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<vector<int>> grid(N, vector<int>(N));
    vector<pair<int, int>> bombs;

    vector<vector<int>> dr = {{-2, -1, 0, 1, 2}, {-1, 0, 0, 0, 1}, {-1, -1, 0, 1, 1}};
    vector<vector<int>> dc = {{0, 0, 0, 0, 0}, {0, -1, 0, 1, 0}, {-1, 1, 0, -1, 1}};

    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                bombs.emplace_back(i, j);
            }
        }
    }

    int ans = 0;

    function<void(int)> dfs = [&](int x){
        if(x == bombs.size()) {
            int cnt = 0;
            for(int i = 0; i < N; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(grid[i][j] != 0) {
                        cnt++;
                    }
                }
            }
            ans = max(ans, cnt);
            return;
        }

        int r = bombs[x].first;
        int c = bombs[x].second;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 5; j++){
                int nr = r + dr[i][j];
                int nc = c + dc[i][j];
                if(nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    grid[nr][nc] += 2; // Mark as exploded
                }
            }
            dfs(x + 1); // Recur to the next bomb
            for(int j = 0; j < 5; j++){
                int nr = r + dr[i][j];
                int nc = c + dc[i][j];
                if(nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    grid[nr][nc] -= 2; // Reset to un-exploded
                }
            }
        }
    };

    dfs(0);
    cout << ans << endl;




    return 0;
}
