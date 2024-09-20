#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N;
    cin >> N;

    vector<vector<int>> E(N+1);

    for(int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    vector<int> par(N+1);

    par[1] = 1;

    stack<int> st;
    st.push(1);

    while(!st.empty()){
        int cur = st.top();
        st.pop();

        for(auto &nxt: E[cur]){
            if(par[nxt]) continue;
            par[nxt] = cur;
            st.push(nxt);
        }
    }

    for(int i = 2; i <= N; i++) cout << par[i] << "\n";

    return 0;
}