#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<vector<int>> par(N+1, vector<int>(20, -1));

    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        par[b][0] = a;
    }

    for(int j = 1; j < 20; j++){
        for(int i = 1; i <= N; i++){
            if(par[i][j-1] != -1){
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }

    int u, v;
    cin >> u >> v;

    if(u == v){
        cout << u << '\n';
        return 0;
    }

    for(int j = 19; j >= 0; j--){
        if(par[u][j] != -1 && par[u][j] != par[v][j]){
            u = par[u][j];
            v = par[v][j];
        }
    }

    cout << par[u][0] << '\n';


    return 0;
}