#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<array<int, 4>> P(N);

    for(int i = 0; i < N; i++){
        cin >> P[i][0] >> P[i][1] >> P[i][2];
        P[i][3] = i;
    }

    vector<array<int, 3>> E;

    sort(P.begin(), P.end(), [&](array<int, 4> a, array<int, 4> b){
        return a[0] < b[0];
    });

    for(int i = 1; i < N; i++){
        E.push_back({abs(P[i][0] - P[i-1][0]), P[i][3], P[i-1][3]});
    }

    sort(P.begin(), P.end(), [&](array<int, 4> a, array<int, 4> b){
        return a[1] < b[1];
    });

    for(int i = 1; i < N; i++){
        E.push_back({abs(P[i][1] - P[i-1][1]), P[i][3], P[i-1][3]});
    }

    sort(P.begin(), P.end(), [&](array<int, 4> a, array<int, 4> b){
        return a[2] < b[2];
    });

    for(int i = 1; i < N; i++){
        E.push_back({abs(P[i][2] - P[i-1][2]), P[i][3], P[i-1][3]});
    }

    sort(E.begin(), E.end());

    ll ans = 0;

    vector<int> par(N);
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

    for(auto &[w, u, v] : E){
        if(find(u) == find(v)) continue;
        unite(u, v);
        ans += w;
    }

    cout << ans << '\n';

    return 0;
}