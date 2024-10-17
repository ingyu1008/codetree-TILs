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
    int N, M;
    cin >> N >> M;

    int A, B;
    cin >> A >> B;

    UF uf(N);

    vector<array<int, 3>> E;

    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back({w, u, v});
    }   
    
    sort(E.rbegin(), E.rend());
    
    for(auto &[w, u, v]: E){
        uf.unite(u, v);

        if(uf.find(A) == uf.find(B)){
            cout << w << "\n";
            break;
        }
    }

    return 0;
}