#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;

    vector<int> A(400 * 400);

    iota(A.begin(), A.end(), 0);

    vector<array<int, 3>> E;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M-1; j++) {
            // (i, j) with (i, j+1)
            int w;
            cin >> w;
            E.push_back({i * M + j, i * M + j + 1, w});
        }
    }

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < M; j++) {
            // (i, j) with (i+1, j)
            int w;
            cin >> w;
            E.push_back({i * M + j, (i + 1) * M + j, w});
        }
    }

    sort(E.begin(), E.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
        return a[2] < b[2];
    });

    function<int(int)> find = [&](int x) {
        return A[x] == x ? x : A[x] = find(A[x]);
    };

    auto unite = [&](int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            A[x] = y;
        }
    };

    int ans = 0;

    for (const auto& e : E) {
        int u = e[0], v = e[1], w = e[2];
        if (find(u) != find(v)) {
            unite(u, v);
            ans += w;
        }
    }

    cout << ans << '\n';

    return 0;
}