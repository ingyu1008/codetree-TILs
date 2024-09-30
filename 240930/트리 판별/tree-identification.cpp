#include <bits/stdc++.h>
using namespace std;

int main() {
    int M;
    cin >> M;

    vector<vector<int>> E(10101);
    vector<int> indegree(10101);
    vector<int> nodes;

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        indegree[v]++;
        nodes.push_back(u);
        nodes.push_back(v);
    }

    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    int root = -1;
    for(auto cur : nodes){
        if(indegree[cur] == 0){
            if(root == -1) root = cur;
            else {
                cout << "0\n";
                return 0;
            }
        }
    }
    
    vector<int> visited(10101, false);

    function<void(int)> dfs = [&](int cur) {
        for(auto nxt : E[cur]){
            if(visited[nxt]) {
                cout << "0\n";
                exit(0);
            }

            visited[nxt] = true;
            dfs(nxt);
        }
    };

    visited[root] = true;
    dfs(root);

    for(auto cur : nodes){
        if(!visited[cur]){
            cout << "0\n";
            return 0;
        }
    }

    cout << "1\n";

    return 0;
}