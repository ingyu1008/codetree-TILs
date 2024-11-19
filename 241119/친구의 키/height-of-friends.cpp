#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    // cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;

    vector<int> indegree(N+1, 0);
    vector<vector<int>> adj(N+1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int next : adj[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return 0;
}