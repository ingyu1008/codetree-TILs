#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> E(N+1);
    vector<int> par(N+1);

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    vector<int> indegree(N+1);

    stack<int> st;
    st.push(1);

    while(!st.empty()){
        int cur = st.top();
        st.pop();

        for(auto &nxt: E[cur]){
            if(indegree[nxt] > 0) continue;
            indegree[cur]++;
            par[nxt] = cur;
            st.push(nxt);
        }
    }

    vector<int> dp0(N+1, 1e9), dp1(N+1, 1);
    
    for(int i = 1; i <= N; i++) if(indegree[i] == 0) {
        st.push(i);
        dp0[i] = 0; // leaf can be 0
    }



    while(!st.empty()){
        int cur = st.top();
        st.pop();

        dp1[cur] = 1;
        dp0[cur] = 0;

        for(auto &nxt: E[cur]){
            if(nxt == par[cur]) continue;

            dp0[cur] += dp1[nxt];
            dp1[cur] += min(dp0[nxt], dp1[nxt]);
        }

        indegree[par[cur]]--;
        if(indegree[par[cur]] == 0) st.push(par[cur]);
    }

    cout << min(dp0[1], dp1[1]) << "\n";


    
    return 0;
}