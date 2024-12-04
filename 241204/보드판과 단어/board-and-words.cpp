#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<string> words(N);

    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    vector<string> grid(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> grid[i];
    }

    vector<ll> p = {31, 37};
    vector<ll> mod = {1000000007, 1000000009};

    vector<vector<bool>> visited(4, vector<bool>(4, false));
    set<pair<ll,ll>> hashes_set;

    vector<int> dr = {1, 1, 0, -1, -1, -1, 0, 1};
    vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};

    function<void(int, int, int, pair<ll, ll>)> dfs = [&](int r, int c, int sz, pair<ll, ll> prevHash) {
        hashes_set.insert(prevHash);
        if(sz == 8){
            return;
        }

        for(int i = 0; i < 8; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || visited[nr][nc]){
                continue;
            }

            visited[nr][nc] = true;
            pair<ll, ll> newHash = {prevHash.first * p[0] + grid[nr][nc] - 'a' + 1, prevHash.second * p[1] + grid[nr][nc] - 'a' + 1};
            dfs(nr, nc, sz + 1, newHash);
            visited[nr][nc] = false;
        }

    };

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            visited[i][j] = true;
            dfs(i, j, 1, {grid[i][j] - 'a' + 1, grid[i][j] - 'a' + 1});
            visited[i][j] = false;
        }
    }

    int ans = 0;

    for(auto &s: words){
        pair<ll, ll> hash = {0, 0};
        for(int i = 0; i < s.size(); i++){
            hash.first = hash.first * p[0] + s[i] - 'a' + 1;
            hash.second = hash.second * p[1] + s[i] - 'a' + 1;
        }

        if(hashes_set.find(hash) != hashes_set.end()){
            ans = max(ans, (int)s.size());
        }
    }

    cout << ans << '\n';

    return 0;
}