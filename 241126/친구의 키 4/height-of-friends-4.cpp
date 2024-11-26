#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N, M;
    cin >> N >> M;
    

    vector<pair<int, int>> edges;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    int lo = 0, hi = M;
    int ans = M;
    while(lo <= hi){
        int mid = (lo + hi) / 2;

        vector<vector<int>> E(N+1);
        vector<int> indegree(N+1, 0);

        for(int i = 0; i < mid; i++){
            int a = edges[i].first;
            int b = edges[i].second;
            E[a].push_back(b);
            indegree[b]++;
        }

        int cnt = 0;

        queue<int> q;

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            cnt++;
            for(int v : E[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(cnt == N){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    if(ans == M){
        cout << "Consistent";
    } else {
        cout << ans+1 << '\n';
    }
    

    return 0;
}