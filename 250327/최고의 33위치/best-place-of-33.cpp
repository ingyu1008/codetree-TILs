#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int>> v(N, vector<int>(N));

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> v[i][j];

    int ans = 0;

    for(int i = 0; i+2 < N; i++){
        for(int j = 0; j+2 < N; j++){
            int cnt = 0;
            for(int r = i; r < i+3; r++) for(int c = j; c < j+3; c++){
                cnt += v[r][c];
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans << "\n";

    return 0;
}