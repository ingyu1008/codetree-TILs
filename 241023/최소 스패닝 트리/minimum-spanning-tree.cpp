#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> E(M);
    for (int i = 0; i < M; i++) {
        cin >> E[i][0] >> E[i][1] >> E[i][2];
    }

    vector<int> parent(N+1);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    };

    auto unite = [&](int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            parent[u] = v;
        }
    };

    sort(E.begin(), E.end(), [](auto& a, auto& b) {
        return a[2] < b[2];
    });

    int ans = 0;

    for (auto& e : E) {
        if (find(e[0]) != find(e[1])) {
            unite(e[0], e[1]);
            ans += e[2];
        }
    }

    cout << ans << '\n';

    return 0;
}