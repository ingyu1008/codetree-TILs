#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(N));

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> v[i][j];

    int ans = 0;

    for(int i = 0; i < N; i++){
        int r = -1, c = -1;
        int row = 0, col = 0;
        for(int j = 0; j < N; j++){
            if(r == v[i][j]) row++;
            else {
                r = v[i][j];
                row = 1;
            }
            if(row == M){
                ans++;
                break;
            }
        }

        for(int j = 0; j < N; j++){
            if(c == v[j][i]) col++;
            else {
                c = v[j][i];
                col = 1;
            }
            if(col == M){
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}