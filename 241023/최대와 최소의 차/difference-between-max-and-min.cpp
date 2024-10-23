#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;
    
    vector<int> parent(N + 1);

    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    };

    auto unite = [&](int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[a] = b;
    };

    vector<array<int, 3>> E;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        E.push_back({a, b, c});
    }

    sort(E.begin(), E.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
        return a[2] > b[2];
    });

    ll smallest = 0;

    for (const auto& e : E) {
        if (find(e[0]) != find(e[1])) {
            unite(e[0], e[1]);
            smallest += 1 - e[2];
        }
    }

    iota(parent.begin(), parent.end(), 0);
    sort(E.begin(), E.end(), [](const array<int, 3>& a, const array<int, 3>& b) {
        return a[2] < b[2];
    });

    ll largest = 0;
    
    for (const auto& e : E) {
        if (find(e[0]) != find(e[1])) {
            unite(e[0], e[1]);
            largest += 1 - e[2];
        }
    }

    cout << largest * largest - smallest * smallest << '\n';


    return 0;
}