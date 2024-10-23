#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> P;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        P.push_back({a, b});
    }

    vector<pair<double, pair<int, int>>> E;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            double d = sqrt(pow(P[i].first - P[j].first, 2) + pow(P[i].second - P[j].second, 2));
            E.push_back({d, {i, j}});
        }
    }

    sort(E.begin(), E.end());

    vector<int> parent(N);

    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    auto unite = [&](int x, int y){
        x = find(x);
        y = find(y);
        if(x != y){
            parent[x] = y;
        }
    };

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        unite(a, b);
    }

    double ans = 0;

    for(auto [d, p] : E){
        auto [a, b] = p;
        if(find(a) != find(b)){
            ans += d;
            unite(a, b);
        }
    }

    cout << fixed << setprecision(2) << ans << '\n';

    return 0;
}