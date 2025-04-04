#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    int ans = 0;

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int sum = 0;
                for (int r = 0; r < N; r++)
                {
                    for (int c = 0; c < N; c++)
                    {
                        if (abs(r - i) + abs(c - j) <= k)
                        {
                            sum += v[r][c];
                        }
                    }
                }

                if (sum * M >= k*k + (k+1)*(k+1))
                {
                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}