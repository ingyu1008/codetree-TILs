#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    int max_regions = 0;
    int k = 1;

    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};


    for (int height = 1; height < 100; height++)
    {
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        int regions = 0;

        function<void(int, int)> dfs = [&](int r, int c)
        {
            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc] && grid[nr][nc] > height)
                {
                    visited[nr][nc] = true;
                    dfs(nr, nc);
                }
            }
        };
        
        for(int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && grid[i][j] > height)
                {
                    visited[i][j] = true;
                    dfs(i, j);
                    regions++;
                }
            }
        }
        if (regions > max_regions)
        {
            max_regions = regions;
            k = height;
        }
    }

    cout <<k << " " << max_regions << endl;

    return 0;
}