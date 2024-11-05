#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;

    int tot = 0;

    vector<vector<int>> cities(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> cities[i][j];
            tot += cities[i][j];
        }
    }

    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(M));
    vector<vector<int>> size(N, vector<int>(M, 1));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            parent[i][j] = {i, j};
        }
    }

    function<pair<int, int>(int, int)> find = [&](int x, int y) {
        if(parent[x][y] == make_pair(x, y)) return make_pair(x, y);
        return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
    };

    auto unite = [&](int x1, int y1, int x2, int y2) {
        auto [a, b] = find(x1, y1);
        auto [c, d] = find(x2, y2);
        
        if(a == c && b == d) return;
        if(size[a][b] < size[c][d]) swap(a, c), swap(b, d);
        parent[c][d] = {a, b};
    };

    vector<array<int, 5>> E;

    //horizontal
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M-1; j++){
            if(cities[i][j] == 0) continue;
            for(int k = j+1; k < M; k++){
                if(cities[i][k] == 0) continue;
                E.push_back({k - j - 1, i, j, i, k});
            }
        }
    }

    //vertical
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N-1; j++){
            if(cities[j][i] == 0) continue;
            for(int k = j+1; k < N; k++){
                if(cities[k][i] == 0) continue;
                E.push_back({k - j - 1, j, i, k, i});
            }
        }
    }

    sort(E.begin(), E.end());

    ll ans = 0;

    for(auto &[w, x1, y1, x2, y2] : E){
        if(find(x1, y1) == find(x2, y2)) continue;

        // cout << w << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        ans += w;
        unite(x1, y1, x2, y2);
        tot--;
    }

    if(tot > 1){
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }




    return 0;
}