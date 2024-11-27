#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> E(N);
    vector<int> indegree(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        E[a].push_back(b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> order;

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);
        for (int v : E[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                pq.push(v);
            }
        }
    }

    if (order.size() != N) {
        cout << "-1\n";
    } else {
        for (int u : order) {
            cout << u + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}