#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char **argv)
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N, M, C;
    cin >> N >> M >> C;

    vector<vector<int>> grid(N, vector<int>(N));
    
    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for(int r1 = 0; r1 < N; r1++){
        for(int c1 = 0; c1 < N-M; c1++){
            for(int r2 = 0; r2 < N; r2++){
                for(int c2 = 0; c2 < N-M; c2++){
                    // check overlap
                    if(r1 == r2 && (c1 < c2 && c1 + M - 1 >= c2  || c1 > c2 && c2 + M - 1 >= c1)) continue;
                    
                    int sum1 = 0, sum2 = 0;
                    // select optimal
                    for(int i = 0; i < (1 << M); i++){
                        int cap = 0;
                        int val = 0;
                        for(int j = 0; j < M; j++){
                            if(i & (1 << j)){
                                cap += grid[r1][c1 + j];
                                val += grid[r1][c1 + j]*grid[r1][c1 + j];
                            }
                        }
                        if(cap <= C) {
                            sum1 = max(sum1, val);
                        }
                    }

                    for(int i = 0; i < (1 << M); i++){
                        int cap = 0;
                        int val = 0;
                        for(int j = 0; j < M; j++){
                            if(i & (1 << j)){
                                cap += grid[r2][c2 + j];
                                val += grid[r2][c2 + j]*grid[r2][c2 + j];
                            }
                        }
                        if(cap <= C) {
                            sum2 = max(sum2, val);
                        }
                    }

                    ans = max(ans, sum1 + sum2);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
