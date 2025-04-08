#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    vector<vector<bool>> visited(N, vector<bool>(N, false));

    vector<int> sizes;

    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, 1, 0, -1};

    function<int(int, int)> dfs = [&](int r, int c){
        int size = 1;
        
        for(int d = 0; d < 4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visited[nr][nc]) continue;
            if(grid[nr][nc] == 0) continue;

            visited[nr][nc] = true;
            size += dfs(nr, nc);
        }

        return size;
    };

    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 1 && !visited[i][j]){
                visited[i][j] = true;
                sizes.push_back(dfs(i, j));
            }
    sort(sizes.begin(), sizes.end());
    cout << sizes.size() << "\n";
    for (int i = 0; i < sizes.size(); i++)
        cout << sizes[i] << "\n";
            
    return 0;
}