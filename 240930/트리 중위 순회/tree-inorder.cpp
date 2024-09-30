#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;

    vector<vector<int>> v(K);

    function<void(int)> dfs = [&](int depth){
        if(depth == K) return;
        dfs(depth+1);
        int u;
        cin >> u;
        v[depth].push_back(u);
        dfs(depth+1);
    };

    dfs(0);
    for(int i = 0; i < K; i++){
        for(auto &x: v[i]){
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}