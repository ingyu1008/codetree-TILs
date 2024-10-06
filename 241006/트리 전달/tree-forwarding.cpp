#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> E(N+1);
    vector<int> A(N+1);

    int u;
    cin >> u;

    for(int i = 2; i <= N; i++){
        cin >> u;
        E[u].push_back(i);
    }

    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        A[x] += y;
    }

    function<void(int)> dfs = [&](int cur){
        for(auto &nxt: E[cur]){
            A[nxt] += A[cur];
            dfs(nxt);
        }
    };

    dfs(1);

    for(int i = 1; i <= N; i++) cout << A[i] << " ";

    return 0;
}