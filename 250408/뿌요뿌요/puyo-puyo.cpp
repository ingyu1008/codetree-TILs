#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int count = 0;
    int mx = 0;

    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};
    
    function<int(int, int, int)> dfs = [&](int r, int c, int origin){
        int sz = 1;

        for(int d = 0; d < 4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (visited[nr][nc]) continue;
            if (grid[nr][nc] != origin) continue;

            visited[nr][nc] = true;
            sz += dfs(nr, nc, origin);
        }
        return sz;
    };

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (visited[i][j]) continue;
            visited[i][j] = true;
            int sz = dfs(i, j, grid[i][j]);
            if( sz >= 4) count++;
            mx = max(mx, sz);
        }
    }
    cout << count << " "<< mx << "\n";

    return 0;
}