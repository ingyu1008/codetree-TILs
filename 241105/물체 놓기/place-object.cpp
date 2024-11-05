#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<array<int, 3>> E;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int w;
            cin >> w;

            if(i == j)  continue;

            E.push_back({w, i, j});
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

    int ans = 0;

    for(auto [w, u, v] : E){
        if(find(u) == find(v)) continue;
        unite(u, v);
        ans += w;
    }

    cout << ans + *min_element(A.begin(), A.end()) << '\n';


    return 0;
}