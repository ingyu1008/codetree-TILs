#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    int ans = 0;
    for(int dx = 1; dx < N; dx++)
    {
        for(int dy = 1; dy < N; dy++)
        {
            for(int r = 0; r < N; r++)
            {
                for(int c = 0; c < N; c++)
                {
                    // start at (r, c)
                    // (+1, -1) by dx
                    // (+1, +1) by dy
                    // (-1, +1) by dx
                    // (-1, -1) by dy

                    if((r + dx + dy >= N) || (c - dx < 0) || (c - dx+dy+dy  >= N))
                        continue;
                    
                    int sum = 0;
                    int cr = r;
                    int cc = c;
                    int dx1 = dx;
                    int dy1 = dy;
                    while(dx1 > 0){
                        cr++; cc--;
                        sum += grid[cr][cc];
                        dx1--;
                    }
                    while(dy1 > 0){
                        cr++; cc++;
                        sum += grid[cr][cc];
                        dy1--;
                    }
                    while(dx1 < dx){
                        cr--; cc++;
                        sum += grid[cr][cc];
                        dx1++;
                    }
                    while(dy1 < dy){
                        cr--; cc--;
                        sum += grid[cr][cc];
                        dy1++;
                    }
                    
                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}