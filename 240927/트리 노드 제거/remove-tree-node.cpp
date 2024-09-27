#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> E(505);
    int u;
    cin >> u;

    for(int i = 1; i < N; i++){
        cin >> u;
        E[u].push_back(i);
        E[i].push_back(u);
    }

    cin >> u;
    
    int ans = 0;

    stack<pair<int, int>> st;
    st.push({0, 0});

    while(!st.empty()){
        auto [cur, par] = st.top();
        st.pop();

        bool leaf = true;

        if(cur == u) continue;

        for(auto &nxt: E[cur]){
            if(nxt == par) continue;
            if(nxt == u) continue;
            st.push({nxt, cur});
            leaf = false;
        }

        if(leaf) ans++;
    }

    cout << ans << "\n";

    return 0;
}