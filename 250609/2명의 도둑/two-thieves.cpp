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
                    if(r1 == r2 && (c1 + M - 1 >= c2  || c2 + M - 1 >= c1)) continue;
                    int tot = 0;
                    // select optimal
                    vector<int> v1, v2;
                    for(int i = 0; i < M; i++){
                        v1.push_back(grid[r1][c1 + i]);
                        v2.push_back(grid[r2][c2 + i]);
                    }
                    sort(v1.rbegin(), v1.rend());
                    sort(v2.rbegin(), v2.rend());

                    int sum1 = 0, sum2 = 0;
                    for(int i = 0; i < M; i++){
                        if(sum1 + v1[i] <= C){
                            sum1 += v1[i];
                            tot += v1[i]*v1[i];
                        }
                        if(sum2 + v2[i] <= C){
                            sum2 += v2[i];
                            tot += v2[i]*v2[i];
                        }
                    }

                    ans = max(ans, tot);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
