#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> par;
    vector<int> sz;
    vector<int> rank;

    UF(int N): par(N+1), sz(N+1, 1), rank(N+1, 1){
        iota(par.begin(), par.end(), 0);
    }

    int find(int u){
        if(u >= par.size()) return u;
        if(u == par[u]) return u;

        return par[u] = find(par[u]);
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;

        if(rank[u] > rank[v]) swap(u, v);

        par[u] = v;
        sz[v] += sz[u];
        if(rank[u] == rank[v]) rank[v]++;
    }
};

int main() {
    int N;
    cin >> N;

    UF uf(N);

    for(int i = 2; i < N; i++){
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }

    for(int i = 2; i <= N; i++){
        if(uf.find(1) == uf.find(i)) continue;
        cout << 1 << " " << i << "\n";
        break;
    }
    

    return 0;
}