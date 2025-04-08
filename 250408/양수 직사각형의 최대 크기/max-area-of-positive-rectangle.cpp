#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = -1;

    for(int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            for(int rsz = 1; rsz <= N; rsz++)
            {
                for (int csz = 1; csz <= M; csz++)
                {
                    if (r + rsz - 1 >= N || c + csz - 1 >= M)
                        break;

                    bool contains_negative = false;
                    for (int i = r; i < r + rsz; i++)
                    {
                        for (int j = c; j < c + csz; j++)
                        {
                            if (grid[i][j] < 0)
                            {
                                contains_negative = true;
                                break;
                            }
                        }
                        if (contains_negative)
                            break;
                    }
                    if (contains_negative)
                        continue;
                    
                    int sz = rsz * csz;
                    ans = max(ans, sz);
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}