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
    vector<bool> isLeaf(N+1, true);
    stack<int> topsort;

    function<void(int, int)> dfs = [&](int cur, int par){
        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            indegree[cur]++;
            parent[nxt] = cur;
            dfs(nxt, cur);
            isLeaf[cur] = false;
        }
    };

    dfs(1, 0);

    vector<int> dp_select(N+1), dp_deselect(N+1);
    for(int i = 1; i <= N; i++) if(indegree[i] == 0) topsort.push(i);


    while(!topsort.empty()){
        int cur = topsort.top();
        topsort.pop();

        if(isLeaf[cur]){
            dp_select[cur] = A[cur];
            dp_deselect[cur] = 0;
        } else {
            dp_select[cur] = A[cur];
            for(auto &nxt: E[cur]){
                if(nxt == parent[cur]) continue;
                dp_select[cur] += dp_deselect[nxt];
                dp_deselect[cur] += max(dp_select[nxt], dp_deselect[nxt]);
            }
        }

        indegree[parent[cur]]--;
        if(indegree[parent[cur]] == 0) topsort.push(parent[cur]);
    } 

    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, dp_select[i]);
        ans = max(ans, dp_deselect[i]);
    }

    cout << ans << "\n";

    return 0;
}