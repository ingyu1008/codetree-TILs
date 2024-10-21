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

    UF uf(N);

    vector<int> left(N+1);
    iota(left.begin(), left.end(), -1);

    int ans = 0;
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;
        int u = uf.find(k);
        int v = left[u];
        if(v == -1) break;

        left[u] = left[uf.find(v)];
        uf.unite(u, v);
        ans++;
    }

    cout << ans << "\n";


    return 0;
}