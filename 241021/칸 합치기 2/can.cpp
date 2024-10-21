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

    vector<int> right(N+2);

    iota(right.begin(), right.end(), 1);

    UF uf(N);
    int ans = N;

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u = uf.find(u);
        v = uf.find(v);

        while(u != v){
            int r = uf.find(right[u]);
            int rr = right[r];
            if(uf.find(u) != uf.find(v)) ans--;
            uf.unite(u, r);
            u = uf.find(u);
            v = uf.find(v);
            right[u] = rr;
        }

        cout << ans << "\n";
    }


    return 0;
}