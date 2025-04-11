#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> grid(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    queue<pair<int, int>> q;

    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for(int i = 0; i < K; i++){
        int r, c;
        cin >> r >> c;
        q.push({r-1, c-1});
    }

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    while(!q.empty()){
        auto [cr, cc] = q.front();
        q.pop();

        for(int d = 0; d < 4; d++){
            int nr = cr + dr[d];
            int nc = cc + dc[d];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(grid[nr][nc] == 1) continue;
            if(visited[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cnt += visited[i][j];
        }
    }

    cout << cnt << "\n";

    return 0;
}