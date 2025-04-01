#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(N));

    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> v[i][j];

    int ans = 0;

    for(int i = 0; i < N; i++){
        unordered_map<int, int> row, col;
        for(int j = 0; j < N; j++){
            row[v[i][j]]++;
            if(row[v[i][j]] == M){
                ans++;
                break;
            }
        }

        for(int j = 0; j < N; j++){
            col[v[j][j]]++;
            if(col[v[i][j]] == M){
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}