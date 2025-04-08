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
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    function<bool(int, int)> dfs = [&](int i, int j) {
        if(i == N-1 && j == M-1)
            return true;
        if (i < 0 || i >= N || j < 0 || j >= M)
            return false;
        if (grid[i][j] == 0)
            return false;
        grid[i][j] = 0;
        return dfs(i + 1, j) || dfs(i, j + 1);
    };

    if (dfs(0, 0))
        cout << "1\n";
    else
        cout << "0\n";
            
    return 0;
}