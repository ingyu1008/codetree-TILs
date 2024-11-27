#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N, M;
    cin >> N >> M;

    vector<vector<int>> mat(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> mat[i][j];
    
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};

    auto flip = [&](int i, int j) {
        for(int k = 0; k < 4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M)
                mat[nr][nc] ^= 1;
        }

        mat[i][j] ^= 1;
    };

    int mn = 1e9;

    for(int i = 0; i < (1 << M); i++){
        vector<vector<int>> temp = mat;
        int cnt = 0;

        for(int j = 0; j < M; j++){
            if(i & (1 << j)){
                flip(0, j);
                cnt++;
            }
        }

        for(int j = 1; j < N; j++){
            for(int k = 0; k < M; k++){
                if(mat[j - 1][k] == 0){
                    flip(j, k);
                    cnt++;
                }
            }
        }

        bool flag = true;

        for(int j = 0; j < M; j++){
            if(mat[N - 1][j] == 0 ){
                flag = false;
                break;
            }
        }

        if(flag){
            mn = min(mn, cnt);
        }
    }

    if(mn == 1e9){
        cout << "-1\n";
    } else {
        cout << mn << "\n";
    }

    return 0;
}