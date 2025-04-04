#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char** argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v[i][j];

    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, 1, 0, -1};

    function<int(int, int, int)> solve = [&](int r, int c, int depth) {
        if (depth == 0) return 0;

        int ans = 0;
        int cur = v[r][c];
        v[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            if (v[nr][nc] > 0) {
                ans = max(ans, solve(nr, nc, depth - 1));
            }
        }

        v[r][c] = cur;

        return ans + cur;
    };

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = max(ans, solve(i, j, 3));
        }
    }

    cout << ans << '\n';

    return 0;
}