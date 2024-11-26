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
        for(int j = 0; j < b; j++){
            int c;
            cin >> c;
            E[c].push_back(a);
            indegree[a]++;
        }
    }

    int K;
    cin >> K;
    vector<int> ans;
    queue<int> q;

    while(K--){
        int c;
        cin >> c;
        indegree[c] = 0;

        q.push(c);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        ans.push_back(cur);

        for(int next : E[cur]){
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';

    for(int a : ans){
        cout << a << ' ';
    }

    

    return 0;
}