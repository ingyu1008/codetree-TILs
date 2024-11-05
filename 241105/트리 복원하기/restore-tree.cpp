#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<array<int, 3>> E;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x;
            cin >> x;
            if(i < j){
                E.push_back({x, i, j});
            }
        }
    }

    sort(E.begin(), E.end());

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

    vector<array<int, 3>> ans;

    for(auto &[w, u, v] : E){
        if(find(u) == find(v)) continue;
        unite(u, v);
        ans.push_back({u, v, w});
    }

    sort(ans.begin(), ans.end());

    for(auto &[u, v, w] : ans){
        cout << u+1 << ' ' << v+1 << ' ' << w << '\n';
    }



    return 0;
}