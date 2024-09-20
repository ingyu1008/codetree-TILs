#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> E(N+1);

    for(int i = 1; i < N; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }

    vector<int> depth(N+1);

    depth[1] = 1;

    stack<int> st;
    st.push(1);

    while(!st.empty()){
        int cur = st.top();
        st.pop();

        for(auto &[nxt, cost]: E[cur]){
            if(depth[nxt]) continue;
            depth[nxt] = depth[cur] + cost;
            st.push(nxt);
        }
    }

    int mxidx = 0;
    for(int i = 1; i <= N; i++){
        if(depth[i] >= depth[mxidx]) mxidx = i;
    }

    fill(depth.begin(), depth.end(), 0);
    depth[mxidx] = 1;
    st.push(mxidx);

    while(!st.empty()){
        int cur = st.top();
        st.pop();

        for(auto &[nxt, cost]: E[cur]){
            if(depth[nxt]) continue;
            depth[nxt] = depth[cur] + cost;
            st.push(nxt);
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(depth[i] >= depth[mxidx]) mxidx = i;
    }
    
    cout << depth[mxidx] - 1 << "\n";

    return 0;
}