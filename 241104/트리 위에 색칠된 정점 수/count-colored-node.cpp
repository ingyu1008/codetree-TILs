#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<vector<int>> E(N+1);
    for(int i = 0; i < N-1; i++){
        int a, b, w;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    vector<int> depth(N+1);
    vector<int> depth2(N+1);
    vector<int> euler;
    vector<int> first(N+1, -1);
    vector<int> colored(N+1, false);

    int K;
    cin >> K;

    for(int i = 0; i < K; i++){
        int x;
        cin >> x;
        colored[x] = true;
    }

    function<void(int, int, int, int)> dfs = [&](int cur, int d, int d2, int prev){
        depth[cur] = d;
        depth2[cur] = d2;
        euler.push_back(cur);
        if(first[cur] == -1){
            first[cur] = euler.size()-1;
        }

        for(auto next : E[cur]){
            if( next == prev ) continue;
            int nd2 = d2;
            if(colored[next]) nd2 = d2+1;
            dfs(next, d+1, nd2, cur);
            euler.push_back(cur);
        }
    };

    if(colored[1]){
        dfs(1, 1, 1, -1);
    } else {
        dfs(1, 1, 0, -1);
    }

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

    auto lca = [&](int u, int v){
        int l = first[u];
        int r = first[v];

        if(l > r){
            swap(l, r);
        }

        int k = log2(r-l+1);

        int a = sparse_table[k][l];
        int b = sparse_table[k][r - (1 << k) + 1];

        return depth[a] < depth[b] ? a : b;
    };
    
    int Q;
    cin >> Q;

    while(Q--){
        int a, b;
        cin >> a >> b;

        int u = lca(a, b);

        cout << depth2[a] + depth2[b] - 2*depth2[u] + ((colored[u])?1:0) << '\n';
    }
    


    return 0;
}