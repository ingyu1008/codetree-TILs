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

    int ans = -1e9;

    for(int sr = 0; sr < N; sr++)
    {
        for(int sc = 0; sc < M; sc++)
        {
            for(int rsz = 1; rsz <= N; rsz++)
            {
                for(int csz = 1; csz <= M; csz++)
                {
                    // Check if the rectangle is within bounds
                    if(sr + rsz > N || sc + csz > M)
                        continue;
                    
                    int sum = 0;
                    for (int r = sr; r < sr + rsz; r++)
                    {
                        for (int c = sc; c < sc + csz; c++)
                        {
                            sum += grid[r][c];
                            grid[r][c] -= 25000;
                        }
                    }



                    for(int er = 0; er < N; er++){
                        for(int ec = 0; ec < M; ec++){
                            if (er >= sr && er < sr + rsz && ec >= sc && ec < sc + csz)
                                continue;
                            
                            for(int rsz2 = 1; rsz2 <= N; rsz2++)
                            {
                                for(int csz2 = 1; csz2 <= M; csz2++)
                                {
                                    // Check if the rectangle is within bounds
                                    if(er + rsz2 > N || ec + csz2 > M)
                                        continue;
                                    
                                    int sum2 = 0;
                                    for (int r = er; r < er + rsz2; r++)
                                    {
                                        for (int c = ec; c < ec + csz2; c++)
                                        {
                                            sum2 += grid[r][c];
                                        }
                                    }
                                    // if(sr == 0 && sc == 0 && rsz == 3 && csz == 2 && er == 1 && ec == 3){
                                    //     cout << "sum: " << sum << endl;
                                    //     cout << "sum2: " << sum2 << endl;
                                    // }

                                    ans = max(ans, sum + sum2);
                                }
                            }
                        }
                    }

                    for (int r = sr; r < sr + rsz; r++)
                    {
                        for (int c = sc; c < sc + csz; c++)
                        {
                            grid[r][c] += 25000;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}