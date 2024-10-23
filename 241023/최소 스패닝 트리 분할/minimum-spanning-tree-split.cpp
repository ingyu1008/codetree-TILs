#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;
    
    vector<int> parent(N+1);

    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    };

    auto unite = [&](int a, int b){
        a = find(a);
        b = find(b);
        if(a != b) parent[a] = b;
    };

    vector<array<int, 3>> edges;

    for(int i = 0; i < M; i++){
        int a, b, w;
        cin >> a >> b >> w;

        edges.push_back({w, a, b});
    }

    sort(edges.begin(), edges.end());

    ll ans = 0;
    ll mx = 0;

    for(auto [w, a, b] : edges){
        if(find(a) != find(b)){
            unite(a, b);
            mx= max(mx, 1LL*w);
            ans += w;
        }
    }

    cout << ans - mx << '\n';

    return 0;
}