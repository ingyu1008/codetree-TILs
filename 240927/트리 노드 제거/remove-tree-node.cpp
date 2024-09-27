#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> E(505);

    int root = 0;
    int u;

    for(int i = 0; i < N; i++){
        cin >> u;
        if(u == -1){
            root = i;
            continue;
        }
        E[u].push_back(i);
    }

    int remove;
    cin >> remove;
    
    int ans = 0;

    stack<pair<int, int>> st;
    st.push({root, root});

    while(!st.empty()){
        auto [cur, par] = st.top();
        st.pop();

        bool leaf = true;

        if(cur == remove) continue;

        for(auto &nxt: E[cur]){
            if(nxt == remove) continue;
            st.push({nxt, cur});
            leaf = false;
        }

        if(leaf) ans++;
    }

    cout << ans << "\n";

    return 0;
}