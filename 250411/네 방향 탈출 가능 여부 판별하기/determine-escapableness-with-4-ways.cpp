#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    int sr = 0, sc = 0;
    queue<pair<int, int>> q;

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    q.push({sr, sc});

    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    while(!q.empty()){
        auto [cr, cc] = q.front();
        q.pop();

        for(int d = 0; d < 4; d++){
            int nr = cr + dr[d];
            int nc = cc + dc[d];

            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(grid[nr][nc] == 0) continue;
            if(visited[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if(visited[N-1][M-1]){
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}