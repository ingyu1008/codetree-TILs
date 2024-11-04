#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<int> par(N+1, -1);
    vector<vector<int>> E(N+1);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        par[b] = a;
        E[a].push_back(b);
    }

    int root;
    for(int i = 1; i <= N; i++){
        if(par[i] == -1){
            root = i;
            break;
        }
    }

    vector<int> depth(N+1);
    vector<int> euler;
    vector<int> first(N+1, -1);

    function<void(int, int)> dfs = [&](int cur, int d){
        depth[cur] = d;
        euler.push_back(cur);
        if(first[cur] == -1){
            first[cur] = euler.size()-1;
        }

        for(auto next : E[cur]){
            dfs(next, d+1);
            euler.push_back(cur);
        }
    };

    dfs(root, 0);

    vector<vector<int>> sparse_table(log2(euler.size()) + 10, vector<int>(euler.size()));

    for(int i = 0; i < euler.size(); i++){
        sparse_table[0][i] = euler[i];
    }

    for(int i = 1; i < sparse_table.size(); i++){
        for(int j = 0; j + (1 << i) <= euler.size(); j++){
            int a = sparse_table[i-1][j];
            int b = sparse_table[i-1][j + (1 << (i-1))];
            sparse_table[i][j] = depth[a] < depth[b] ? a : b;
        }
    }

    int u, v;
    cin >> u >> v;

    int l = first[u];
    int r = first[v];

    if(l > r){
        swap(l, r);
    }

    int k = log2(r-l+1);

    int a = sparse_table[k][l];
    int b = sparse_table[k][r - (1 << k) + 1];

    cout << (depth[a] < depth[b] ? a : b) << '\n';
    


    return 0;
}