#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            parent[i][j] = {i, j};
        }
    }

    function<pair<int, int>(int, int)> find = [&](int r, int c){
        if(parent[r][c] == make_pair(r, c)){
            return make_pair(r, c);
        }
        return parent[r][c] = find(parent[r][c].first, parent[r][c].second);
    };

    auto unite = [&](int r1, int c1, int r2, int c2){
        auto [p1, p2] = make_pair(find(r1, c1), find(r2, c2));
        if(p1 == p2){
            return;
        }
        parent[p1.first][p1.second] = p2;
    };

    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};

    vector<array<int, 5>> E;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == -1 || grid[i][j] == 0){
                continue;
            }
            vector<vector<int>> dist(N, vector<int>(N, 1e9));
            queue<pair<int, int>> q;
            q.push({i, j});
            dist[i][j] = 0;

            while(!q.empty()){
                auto [r, c] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr < 0 || nr >= N || nc < 0 || nc >= N){
                        continue;
                    }

                    if(grid[nr][nc] == -1){
                        continue;
                    }

                    if(dist[nr][nc] > dist[r][c] + 1){
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }

            for(int r = 0; r < N; r++){
                for(int c = 0; c < N; c++){
                    if(grid[r][c] != 1 && grid[r][c] != 2){
                        continue;
                    }

                    if(dist[r][c] == 1e9){
                        continue;
                    }

                    E.push_back({dist[r][c], i, j, r, c});
                }
            }
        }
    }

    sort(E.begin(), E.end());

    ll ans = 0;

    for(int i = 0;i < E.size(); i++){
        for(auto [d, r1, c1, r2, c2] : E){
            if(find(r1, c1) == find(r2, c2)){
                continue;
            }
            if(grid[r1][c1] == 2 && grid[r2][c2] == 2){
                continue;
            }
            if(grid[r1][c1] == 1 && grid[r2][c2] == 1){
                continue;
            }

            ans += d;
            // cout << d << " " << r1 << " " << c1 << " " << r2 << " " << c2 << '\n';
            unite(r1, c1, r2, c2);
            grid[r1][c1] = 1;
            grid[r2][c2] = 1;
            break;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 2){
                ans = -1;
            }
        }
    }

    cout << ans << '\n';


    return 0;
}