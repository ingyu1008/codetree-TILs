#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i++) cin >> A[i];

    vector<pair<int, int>> E(N, {-1, -1});
    vector<int> par(N);

    int cur = 0;
    
    for(int i = 1; i < N; i++){
        if(A[i] < A[cur]){
            E[cur].first = i;
            par[i] = cur;
            cur = i;
        } else if(cur == 0 || A[i] < A[par[cur]]){
            E[cur].second  = i;
            par[i] = cur;
            cur = i;
        } else if(A[i] > A[par[cur]] ){
            cur = par[cur];
            i--;
        }
    }
    function<void(int)> dfs = [&](int cur){
        if(E[cur].first >= 0) dfs(E[cur].first);
        if(E[cur].second >= 0) dfs(E[cur].second);
        cout << A[cur] << "\n";
    };

    dfs(0);

    return 0;
}