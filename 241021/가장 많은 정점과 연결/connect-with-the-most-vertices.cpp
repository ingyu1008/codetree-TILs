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
    vector<array<int, 2>> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i][0];
        A[i][1] = i;
    }

    UF uf(N);
    for(int i = 0; i < M ;i++){
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }



    sort(A.begin() + 1, A.end());

    int ans = 0;

    for(int i = 2; i <= N; i++){
        if(uf.find(A[i][1]) == uf.find(A[1][1])) continue;

        uf.unite(A[i][1], A[1][1]);
        ans += A[i][0] + A[1][0];
    }

    if(ans > K) cout << "NO\n";
    else cout << ans << "\n";


    return 0;
}