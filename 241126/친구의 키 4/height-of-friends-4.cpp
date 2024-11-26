#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> E(N+1);
    vector<int> indegree(N+1, 0);

    vector<pair<int, int>> edges;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        indegree[b]++;

        edges.push_back({a, b});
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<bool> visited(N+1, false);
    int ans = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        ans++;
        for (int v : E[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if(ans == N) {
        cout << "Consistent\n";
    } else {
        for(int i = 0; i < M; i++){
            if(!visited[edges[i].first] || !visited[edges[i].second]){
                cout <<  i+1 << "\n";
                return 0;
            }
        }
    }
    

    return 0;
}