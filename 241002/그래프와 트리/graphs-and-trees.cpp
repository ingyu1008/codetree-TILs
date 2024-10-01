#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> par(N+1);
    vector<int> cycle(N+1, false);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    };

    auto unite = [&] (int u, int v){
        u = find(u);
        v = find(v);
        
        if(u == v){
            cycle[u] = true;
        }

        par[v] = u;
        cycle[u] |= cycle[v];
    };

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }

    int ans = 0;

    for(int i = 1; i <= N; i++){
        if(find(i) == i){
            if(!cycle[i]) ans ++;
        }
    }

    cout << ans << "\n";

    return 0;
}