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

    vector<array<int, 2>> A(M);
    for(int i = 0; i < M; i++){
        cin >> A[i][0];
        A[i][1] = i;
    }
    sort(A.begin(), A.end());

    vector<bool> valid(N, false);

    int ans = 0;
    for(int i = 0; i < M; i++){
        if(A[i][0] <= ans) continue;
        valid[A[i][1]] = true;
        ans++;
    }

    ans = 0;

    for(int i = 0; i < M; i++){
        if(valid[i] == false) break;
        ans++;
    }

    cout << ans <<"\n";



    return 0;
}