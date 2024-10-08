#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> E(N+1);
    vector<int> A(N+1);

    for(int i = 1; i <= N; i++) cin >> A[i];

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;

        E[u].push_back(v);
        E[v].push_back(u);
    }

    vector<int> parent(N+1);
    vector<int> indegree(N+1);
    stack<int> topsort;

    function<void(int, int)> dfs = [&](int cur, int par){
        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            indegree[cur]++;
            parent[cur] = par;
            dfs(nxt, cur);
        }
        if(indegree[cur] == 0) topsort.push(cur);
    };

    int ans = 0;

    while(!topsort.empty()){
        int cur = topsort.top();
        topsort.pop();

        int val = abs(1 - A[cur]);
        
        ans += val;

        if(A[cur] > 1){
            A[cur] -= val;
            A[parent[cur]] += val;
        } else {
            A[cur] += val;
            A[parent[cur]] -= val;
        } 
    } 

    cout << ans << "\n";

    return 0;
}