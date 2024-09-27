#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> E(N+1);
    int u;
    cin >> u;

    for(int i = 1; i < N; i++){
        cin >> u;
        E[u].push_back(i);
        E[i].push_back(u);
    }

    cin >> u;

    for(int i = 0; i < N; i++){
        if(i == u) E[i].clear();
        if(find(E[i].begin(), E[i].end(), u) == E[i].end()) continue;
        E[i].erase(remove(E[i].begin(), E[i].end(), u), E[i].end());
    }
    
    int ans = 0;

    stack<pair<int, int>> st;
    st.push({0, -1});

    while(!st.empty()){
        auto [cur, par] = st.top();
        st.pop();

        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            st.push({nxt, cur});
        }

        if(E[cur].size() == 1) ans++;
    }

    cout << ans << "\n";

    return 0;
}