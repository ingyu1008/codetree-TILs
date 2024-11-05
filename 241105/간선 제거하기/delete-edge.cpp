#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> E;

    ll total = 0;
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        E.push_back({c, a, b});
        total += c;
    }

    sort(E.begin(), E.end());

    vector<int> par(N+1);

    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    };

    auto unite = [&](int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) par[a] = b;
    };

    ll mst = 0;

    for(auto [c, a, b] : E){
        if(find(a) == find(b)) continue;
        unite(a, b);
        mst += c;
    }

    cout << total - mst << '\n';


    return 0;
}