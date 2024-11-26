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

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int ans = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans++;
        for (int v : E[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if(ans == N) {
        cout << "Not Exists\n";
    } else {
        cout << "Exists\n";
    }
    

    return 0;
}