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
    int N, M, K;

    cin >> N >> M >> K;

    UF uf(N);

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }   

    int u;
    cin >> u;

    for(int i = 1; i < K; i++){
        int v;
        cin >> v;
        if(uf.find(u) != uf.find(v)){
            cout << "0\n";
            exit(0);
        }
    }

    cout << "1\n";

    return 0;
}